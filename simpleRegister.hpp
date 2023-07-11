#ifndef SIMPLEREGISTER_HPP
#define SIMPLEREGISTER_HPP
#include <functional>
#include <map>
#include <memory>
#include <string_view>
#include <vector>

struct base {};
using baseptr = std::unique_ptr<::base>;
namespace myRegister {

using baseCreator = std::function<baseptr()>;
using actionMap = std::map<std::string, baseCreator>;
using keylist = std::vector<std::string>;
//  struct so is default public

class simpleRegister {
  actionMap mymap{};
  // simpleRegister() = default;
  simpleRegister();
  ~simpleRegister() = default;
  simpleRegister(const simpleRegister &) = delete;
  simpleRegister(simpleRegister &&) = delete;
  simpleRegister &operator=(const simpleRegister &) = delete;
  simpleRegister &operator=(simpleRegister &&) = delete;

public:
  static simpleRegister &get();
  baseptr act(std::string_view);
  void registerAction(std::string_view directive, baseCreator act);
  void deRegisterAction(std::string_view directive);
  void plotActions() const;
  keylist getActionsNames() const;
};
} // namespace myRegister
template <typename T> struct ActionRegistration {
private:
  std::string name;

public:
  ActionRegistration(std::string_view directive) : name(directive) {
    myRegister::simpleRegister::get().registerAction(
        name, []() -> baseptr { return std::make_unique<T>(); });
  }
  ActionRegistration(const ActionRegistration &) = delete;
  ~ActionRegistration() {
    myRegister::simpleRegister::get().deRegisterAction(name);
  }
};

#endif // SIMPLEREGISTER_HPP