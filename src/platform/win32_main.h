#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _WIN32_LEAN_AND_MEAN
#define _WIN32_EXTRA_LEAN

#include "glad/glad.h"
#include "windows.h"
#include <iostream>
#include "application/application.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, PSTR, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);