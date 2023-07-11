#include "dlHandler.hpp"
#include <dlfcn.h>
#include <iostream>
dlHandler::dlHandler(std::string_view name, int flags)
    : handle(dlopen(name.data(), flags)) {
  std::cerr << "open\n";
}

dlHandler::dlHandler(int namespaceFlag, std::string_view name, int flags)
    : handle(dlmopen(namespaceFlag, name.data(), flags)) {
  std::cerr << "mopen\n";
}

dlHandler::~dlHandler() {
  std::cerr << "close\n";
  if (handle) {
    // turns out that dlclose does not accepts NULL or nullptr
    dlclose(handle);
  }
}

void dlHandler::close() {
  std::cerr << "close\n";
  dlclose(handle);
  handle = nullptr;
}

bool dlHandler::isValid() const { return handle; }

dlHandler::dlHandler(dlHandler &&other) : handle(other.handle) {
  other.handle = nullptr;
}
