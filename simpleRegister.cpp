#include "simpleRegister.hpp"
#include <iostream>
namespace myRegister {
simpleRegister::simpleRegister() { std::cout << "init\n"; }

simpleRegister &simpleRegister::get() {
  static simpleRegister singleton;
  return singleton;
}

baseptr simpleRegister::act(std::string_view key) {
  return mymap.at(std::string(key))();
}

void simpleRegister::registerAction(std::string_view directive,
                                    baseCreator action) {
  std::cout << directive << " has been registered\n";
  mymap.emplace(std::string(directive), action);
  // mymap.emplace_back(std::string(directive));
}

void simpleRegister::deRegisterAction(std::string_view directive) {

  auto it = mymap.find(std::string(directive));
  // auto it = std::find(mymap.begin(), mymap.end(), std::string(directive));

  if (it != mymap.end()) {
    mymap.erase(it);
    std::cout << directive << " has been un-registered\n";
  }
}

void simpleRegister::plotActions() const {
  std::cout << "registered Actions: (" << mymap.size() << ")\n";
  for (const auto &it : mymap) {
    std::cout << " " << it.first << "\n";
  }
}

keylist simpleRegister::getActionsNames() const {
  keylist toret;
  for (const auto &it : mymap) {
    toret.emplace_back(it.first);
  }
  return toret;
}
} // namespace myRegister