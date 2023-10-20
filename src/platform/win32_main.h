#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _WIN32_LEAN_AND_MEAN
#define _WIN32_EXTRA_LEAN

#include "glad/glad.h"

#include <windows.h>

#include "application/application.h"

#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#define WGL_CONTEXT_FLAGS_ARB 0x2094
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#define WGL_CONTEXT_MASK_ARB 0x9126

typedef HGLRC(WINAPI* PFNGLCREATECONTEXTATTRIBSARBPROC) (HDC, HGLRC, const int*);
typedef const char*(WINAPI* PFNWGLGETTEXTENSIONSSTRINGEXTPROC)(void);
typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC) (int);
typedef int (WINAPI* PFNWGLGETSWAPINTERVALEXTPROC) (void);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine,
                   int nShowCmd);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);