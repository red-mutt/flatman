#include "include/flatpak_service.h"
#include <flatpak/flatpak.h>
#include <stdlib.h>

static void fetch_apps(FlatpakInstallation *install,
                       AppInfo **apps,
                       size_t *count) {
  if (!install)
    return;
  GError *error = NULL;
  GPtrArray *installed_refs =
      flatpak_installation_list_installed_refs(install, NULL, &error);

  if (!installed_refs) {
    if (error) {
      g_error_free(error);
      return;
    }
  }

  if (installed_refs) {
    for (guint i = 0; i < installed_refs->len; i++) {
      FlatpakRef *ref = FLATPAK_REF(g_ptr_array_index(installed_refs, i));
      *apps = realloc(*apps, (*count + 1) * sizeof(AppInfo));
      (*apps)[*count].id = strdup(flatpak_ref_get_name(ref));
      (*apps)[*count].branch = strdup(flatpak_ref_get_branch(ref));
      (*count)++;
    }
  }

  g_ptr_array_unref(installed_refs);
}

AppInfo *get_installed_apps(size_t *count) {
  FlatpakInstallation *user = flatpak_installation_new_user(NULL, NULL);
  FlatpakInstallation *system = flatpak_installation_new_system(NULL, NULL);
  AppInfo *apps = NULL;

  *count = 0;

  if (user) {
    fetch_apps(user, &apps, count);
  }
  if (system) {
    fetch_apps(system, &apps, count);
  }

  if (user)
    g_object_unref(user);
  if (system)
    g_object_unref(system);

  return apps;
}
