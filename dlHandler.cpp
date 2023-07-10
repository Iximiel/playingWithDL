#include "dlHandler.hpp"
#include <dlfcn.h>
#include <iostream>
dlHandler::dlHandler(std::string_view name, int flags)
    : handle(dlopen(name.data(), flags)) {
  std::cerr << "open\n";
}
dlHandler::~dlHandler() {
  std::cerr << "close\n";
  dlclose(handle);
}

dlHandler::dlHandler(dlHandler &&other) : handle(other.handle) {
  other.handle = nullptr;
}
