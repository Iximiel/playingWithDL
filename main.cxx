#include "dlHandler.hpp"
#include "simpleRegister.hpp"
#include <dlfcn.h>
#include <iostream>
using std::cout;
int main(int, char **) {
  /*{
    cout << "****B is RTLD_GLOBAL:\n";
    cout << "loading A:\n";
    dlHandler handleA("./A.so", RTLD_LAZY);
    cout << "loading B:\n";
    auto *handleB = new dlHandler("./B.so", RTLD_NOW | RTLD_GLOBAL);
    cout << "loading C:\n";
    dlHandler handleC("./C.so", RTLD_NOW | RTLD_LOCAL);
    cout << "deleting B:\n";
    // C.so and B.so both contains a variable called "testB"
    delete handleB;
    cout << "closing the scope:\n";
  }*/
  {
    cout << "****B is RTLD_LOCAL:\n";
    cout << "loading A:\n";
    dlHandler handleA("./A.so", RTLD_LAZY);
    cout << "loading B:\n";
    auto *handleB = new dlHandler("./B.so", RTLD_NOW | RTLD_LOCAL);
    cout << "loading C:\n";
    dlHandler handleC("./C.so", RTLD_NOW | RTLD_LOCAL);
    cout << "deleting B:\n";
    delete handleB;
    myRegister::simpleRegister::get().plotActions();
    cout << "closing the scope:\n";
  }
  return 0;
}