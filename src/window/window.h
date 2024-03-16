#pragma once

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <string>

class Window {
 public:
  Window(GLint width = 500, GLint height = 500);
  ~Window();

  GLint bufferWidth() const;
  GLint bufferHeight() const;
  bool shouldClose() const;
  void swapBuffers() const;
  void setTitle(const std::string &title);
  std::string title() const;

 private:
  int initialize();
  GLFWwindow *m_window;
  GLint m_width, m_height;
  GLint m_bufferWidth, m_bufferHeight;
  std::string m_title;
};
