#pragma once
#include <string>
#include <vector>

struct AppInfo {
  std::string id;
  std::string branch;
};
std::vector<AppInfo> get_installed_apps();
