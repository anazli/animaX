#include <iostream>

#include "application/application.h"

/*
#include <KHR/khrplatform.h>
#ifdef __linux__
#include "platform/linux_main.h"
#else
#include "platform/win32_main.h"
#endif
*/

using namespace std;

int main() {
  Application app;
  app.createWindow(800, 600);
  app.getWindow()->setTitle("AnimaX");
  return 0;
}
