#include "include/flatpak_service.hpp"
#include <flatpak/flatpak.h>
#include <vector>

static void fetch_apps(FlatpakInstallation *install,
                       std::vector<AppInfo> &apps) {
  if (!install)
    return;
  GError *error = nullptr;
  GPtrArray *installed_refs =
      flatpak_installation_list_installed_refs(install, nullptr, &error);

  if (!installed_refs) {
    if (error) {
      g_error_free(error);
      return;
    }
  }

  if (installed_refs) {
    for (guint i = 0; i < installed_refs->len; i++) {
      auto *ref = FLATPAK_REF(g_ptr_array_index(installed_refs, i));
      apps.push_back({
          flatpak_ref_get_name(ref),
          flatpak_ref_get_branch(ref),
      });
    }
  }

  g_ptr_array_unref(installed_refs);
}

std::vector<AppInfo> get_installed_apps() {
  FlatpakInstallation *user =
      flatpak_installation_new_user(nullptr, nullptr);
  FlatpakInstallation *system  = 
    flatpak_installation_new_system(nullptr, nullptr);
  std::vector<AppInfo> apps;

  if (user) {
    fetch_apps(user, apps);
  }
  if (system) {
    fetch_apps(system, apps);
  }

  g_object_unref(user);
  g_object_unref(system);
  return apps;
}
