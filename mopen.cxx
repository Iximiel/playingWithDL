#include "dlHandler.hpp"
#include "simpleRegister.hpp"
#include <dlfcn.h>
#include <iostream>
using std::cout;
int main(int, char **) {
  /* {
    cout << "****B is RTLD_GLOBAL:\n";
    cout << "loading A:\n";
    dlHandler handleA("./A.so", RTLD_LAZY);
    cout << "loading B:\n";
    dlHandler handleB("./B.so", RTLD_NOW | RTLD_GLOBAL);
    cout << "loading C:\n";
    dlHandler handleC("./C.so", RTLD_NOW | RTLD_LOCAL);
    cout << "deleting B:\n";
    // C.so and B.so both contains a variable called "testB"
    handleB.close();
    cout << "closing the scope:\n";
  }*/
  {
    cout << "****B is RTLD_GLOBAL but with LM_ID_NEWLM:\n";
    cout << "loading A:\n";
    dlHandler handleA("./A.so", RTLD_LAZY);
    cout << "loading B:\n";
    // dlHandler handleB(LM_ID_NEWLM, "./B.so", RTLD_NOW | RTLD_GLOBAL);
    auto *handleB = dlmopen(LM_ID_NEWLM, "./B.so", RTLD_DEEPBIND);
    cout << "loading C:\n";
    dlHandler handleC("./C.so", RTLD_NOW | RTLD_LOCAL);
    cout << "deleting B:\n";
    // handleB.close();
    dlclose(handleB);
    cout << "closing the scope:\n";
  }
  // cout << "LM_ID_BASE : " << LM_ID_BASE << "\nLM_ID_NEWLM: " << LM_ID_BASE
  //  << LM_ID_NEWLM << "\n";
  return 0;
}