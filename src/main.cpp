//OpenGL specific headers
#include <glad/glad.h>
#include <KHR/khrplatform.h>

//std headers
#include <iostream>

//local headers
#include "application/application.h"
#include "platform/win32_main.h"

#ifdef __linux__
#include "platform/linux_main.h"
#else
#include "platform/win32_main.h"
#endif

using namespace std;

int main() {
#ifdef _WIN32
  return WinMain(GetModuleHandleA(nullptr), nullptr, GetCommandLineA(), SW_SHOWDEFAULT);
#else
  return 0;
#endif

}
