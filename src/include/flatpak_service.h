#pragma once
#include <stddef.h>

typedef struct {
  char *id;
  char *branch;
} AppInfo;

AppInfo *get_installed_apps(size_t *count);
