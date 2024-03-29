#include "dlHandler.hpp"
#include <dlfcn.h>
#include <iostream>
dlHandler::dlHandler(std::string_view name, int flags)
    : handle(dlopen(name.data(), flags)) {
  std::cerr << "open " << name << "\n";
  if (!handle) {
    std::cerr << dlerror() << "\n";
  }
}

dlHandler::dlHandler(int namespaceFlag, std::string_view name, int flags)
    : handle(dlmopen(namespaceFlag, name.data(), flags)) {
  std::cerr << "mopen\n";
}

dlHandler::~dlHandler() {

  if (handle) {
    std::cerr << "close\n";
    // turns out that dlclose does not accepts NULL or nullptr
    dlclose(handle);
  }
}

void dlHandler::close() {
  std::cerr << "close manually\n";
  dlclose(handle);
  handle = nullptr;
}

bool dlHandler::isValid() const { return handle; }

dlHandler::dlHandler(dlHandler &&other) : handle(other.handle) {
  std::cerr << "moved\n";
  other.handle = nullptr;
}

dlHandler &dlHandler::operator=(dlHandler &&other) {
  std::cerr << "cmoved\n";
  this->handle = other.handle;
  other.handle = nullptr;
  return *this;
}