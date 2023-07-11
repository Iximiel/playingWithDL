#include "dlHandler.hpp"
#include "simpleRegister.hpp"
#include <dlfcn.h>
#include <filesystem>
#include <iostream>
#include <regex>
#include <vector>
using std::cout;
namespace fs = std::filesystem;

const auto isPlugin = std::regex(".*\\.so");

int main(int, char **) {
  fs::path here = fs::current_path();
  std::vector<std::string> listOfSo{};
  for (auto const &dir_entry : fs::directory_iterator{here}) {
    if (dir_entry.is_regular_file()) {
      std::string fname = dir_entry.path().filename();

      if (std::regex_search(fname, isPlugin)) {
        std::cout << fname << "\n";
        listOfSo.emplace_back(dir_entry.path().string());
      }
    }
  }
  std::vector<dlHandler> loadedLibs;
  for (auto &it : listOfSo) {
    std::cout << "Loading " << it << "\n";
    loadedLibs.emplace_back(it.c_str(), RTLD_LAZY | RTLD_LOCAL);
    std::cout << dlerror() << "\n";
    std::cout << loadedLibs.back().isValid() << "\n";
  }
  dlHandler t("asd.so", RTLD_NOW | RTLD_LOCAL);
  std::cout << t.isValid() << "\n";
  std::cout << dlerror() << "\n";
  return 0;
}