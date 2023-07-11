#include "dlHandler.hpp"
#include "simpleRegister.hpp"
#include <cstdio>
#include <dlfcn.h>
#include <filesystem>
#include <iostream>
#include <regex>
#include <vector>

using std::cout;
namespace fs = std::filesystem;

const auto isPlugin = std::regex(".*\\.so");
const auto isSharedLibrary = std::regex("lib.*\\.so");

int main(int, char **) {
  fs::path here = fs::path(PLUGINLOCATION);
  std::vector<std::string> listOfSo{};
  for (auto const &dir_entry : fs::directory_iterator{here}) {
    if (dir_entry.is_regular_file()) {
      std::string fname = dir_entry.path().filename();

      if (std::regex_search(fname, isPlugin) &&
          !std::regex_search(fname, isSharedLibrary)) {
        listOfSo.emplace_back(dir_entry.path().string());
      }
    }
  }
  myRegister::simpleRegister::get().plotActions();
  {
    std::vector<dlHandler> loadedLibs;

    for (const auto &it : listOfSo) {
      std::cout << "Loading " << it << "\n";
      dlHandler tmp(it.c_str(), RTLD_LAZY);
      if (tmp.isValid()) {
        loadedLibs.emplace_back(std::move(tmp));
      }
    }
    myRegister::simpleRegister::get().plotActions();
    dlHandler t("asd.so", RTLD_NOW | RTLD_LOCAL);
    std::cout << t.isValid() << "\n";
    for (const auto &tname :
         myRegister::simpleRegister::get().getActionsNames()) {
      auto tempAct = myRegister::simpleRegister::get().act(tname);
    }
  }
  std::cout << "At the end\n";
  myRegister::simpleRegister::get().plotActions();
  return 0;
}