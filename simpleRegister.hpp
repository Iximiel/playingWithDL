#include <iostream>
#include <string_view>

struct ActionRegistration {
private:
  std::string name;

public:
  ActionRegistration(std::string_view directive) : name(directive) {
    std::cout << name << " has been registered\n";
  }
  ActionRegistration(const ActionRegistration &) = delete;
  ~ActionRegistration() { std::cout << name << " has been un-registered\n"; }
};