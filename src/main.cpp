//OpenGL specific headers
#include <glad/glad.h>
#include <KHR/khrplatform.h>

//std headers
#include <iostream>

//local headers
#include "application/application.h"

#ifdef __linux__
#include "platform/linux_main.h"
#else
#include "platform/win32_main.h"
#endif

using namespace std;

int main() {
  GLuint WIDTH = 800, HEIGHT = 600;
  auto app = Application{};
  cout << "Hello Test Application" << endl;

  return 0;
}
