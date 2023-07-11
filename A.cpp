#include "simpleRegister.hpp"
#include <iostream>

namespace A {
struct A : public base {
  A() { std::cout << "created an A\n"; }
};
ActionRegistration<A> testA("A");
} // namespace A
