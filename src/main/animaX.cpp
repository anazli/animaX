#include <iostream>

#include "application/application.h"

/*
#ifdef __linux__
#include "platform/linux_main.h"
#else
#include "platform/win32_main.h"
#endif
*/

using namespace std;

int main() {
  Application app;
  app.createWindow(800, 600, "AnimaX");
  app.render();
  return 0;
}
