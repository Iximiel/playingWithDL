#include "simpleRegister.hpp"
#include <iostream>

namespace C {
struct C : public base {
  C() { std::cout << "created a C\n"; }
};

ActionRegistration<C> testC("C");

// I wannt to seee if i can duplicate this
struct BC : public base {
  BC() { std::cout << "created an BC!!\n"; }
};

ActionRegistration<BC> testB("B but in C.so");
} // namespace C