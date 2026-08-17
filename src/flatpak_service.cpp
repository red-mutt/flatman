#include "include/flatpak_service.hpp"
#include <flatpak/flatpak.h>
#include <vector>

static void fetch_apps(FlatpakInstallation *install,
                       std::vector<AppInfo> &apps) {

  if (!install)
    return;
  GError *error = nullptr;
  if (error) {
    g_error_free(error);
    return;
  }

  GPtrArray *InstalledRefs =
      flatpak_installation_list_installed_refs(install, nullptr, &error);
  if (InstalledRefs) {
    for (guint i = 0; i < InstalledRefs->len; i++) {
      auto *ref = FLATPAK_REF(g_ptr_array_index(InstalledRefs, i));
      apps.push_back({
          flatpak_ref_get_name(ref),
          flatpak_ref_get_branch(ref),
      });
    }
  }
  g_ptr_array_unref(InstalledRefs);
}

std::vector<AppInfo> get_installed_apps() {
  FlatpakInstallation *Install =
      flatpak_installation_new_user(nullptr, nullptr);
  std::vector<AppInfo> apps;
  fetch_apps(Install, apps);
  return apps;
}
