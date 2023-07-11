#include "simpleRegister.hpp"
#include <iostream>
namespace B {
struct B : public base {
  B() { std::cout << "created a B\n"; }
};
ActionRegistration<B> testB("B");
} // namespace B