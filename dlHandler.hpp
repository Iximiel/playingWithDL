#include <string_view>
class dlHandler {
  void *handle{nullptr};

public:
  dlHandler(std::string_view, int flags);
  dlHandler(const dlHandler &) = delete;
  dlHandler(dlHandler &&);
  ~dlHandler();
  dlHandler &operator=(const dlHandler &) = delete;
  dlHandler &operator=(dlHandler &&) = delete;
};
/*
dlHandler &&loadLazy(std::string_view);
dlHandler &&loadNow(std::string_view);
dlHandler &&loadLocal(std::string_view);
dlHandler &&loadGlobal(std::string_view);
dlHandler &&loadNoDelete(std::string_view);
dlHandler &&loadNoLoad(std::string_view);
dlHandler &&loadDeepBind(std::string_view);
*/