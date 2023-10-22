#include "platform/win32_main.h"

#include <memory>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine,
                   int nShowCmd) {
  auto application = std::make_unique<Application>();
  CreateWin32Window(hInstance, lpCmdLine);

  return 0;
}

LRESULT WndProc(HWND, UINT, WPARAM, LPARAM) { return LRESULT(); }

WNDCLASSEX ConfigureAndRegisterWin32ClassEx(HINSTANCE hInstance) {
  WNDCLASSEX wndclass;
  wndclass.cbSize = sizeof(WNDCLASSEX);
  wndclass.style = CS_HREDRAW | CS_VREDRAW;
  wndclass.lpfnWndProc = WndProc;
  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 0;
  wndclass.hInstance = hInstance;
  wndclass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
  wndclass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
  wndclass.hCursor = LoadCursor(nullptr, IDC_ARROW);
  wndclass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
  wndclass.lpszMenuName = 0;
  wndclass.lpszClassName = "Windows Game Window";
  RegisterClassEx(&wndclass);

  return wndclass;
}

RECT ConfigureScreenRes() {
  auto screeWidth = GetSystemMetrics(SM_CXSCREEN);
  auto screenHeight = GetSystemMetrics(SM_CYSCREEN);
  auto clientWidth = 800;
  auto clientHeight = 600;
  RECT windowRect;
  SetRect(&windowRect, (screeWidth / 2) - (clientWidth / 2),
          (screenHeight / 2) - (clientHeight / 2),
          (screeWidth / 2) + (clientWidth / 2),
          (screenHeight / 2) + (clientHeight / 2));

  return windowRect;
}

void CreateWin32Window(HINSTANCE hInstance, PSTR lpCmdLine) {
  auto wndclass = ConfigureAndRegisterWin32ClassEx(hInstance);
  auto windowRect = ConfigureScreenRes();

  DWORD style = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX |
                 WS_MAXIMIZEBOX);
  AdjustWindowRectEx(&windowRect, style, FALSE, 0);

  HWND hwnd = CreateWindowEx(0, wndclass.lpszClassName, "Game Window", style,
                             windowRect.left, windowRect.top,
                             windowRect.right - windowRect.left,
                             windowRect.bottom - windowRect.top, nullptr,
                             nullptr, hInstance, lpCmdLine);
  HDC hdc = GetDC(hwnd);
}
