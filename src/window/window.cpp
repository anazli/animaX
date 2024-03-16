#include "window/window.h"

#include <iostream>

Window::Window(GLint width, GLint height) : m_width(width), m_height(height) {
  initialize();
}

Window::~Window() {
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

GLint Window::bufferWidth() const { return m_bufferWidth; }

GLint Window::bufferHeight() const { return m_bufferHeight; }

bool Window::shouldClose() const { return glfwWindowShouldClose(m_window); }

void Window::swapBuffers() const { glfwSwapBuffers(m_window); }

void Window::setTitle(const std::string &title) { m_title = title; }

std::string Window::title() const { return m_title; }

int Window::initialize() {
  if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW!" << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  m_window =
      glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
  if (!m_window) {
    std::cout << "GLFW Window creation failed!" << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwGetFramebufferSize(m_window, &m_bufferWidth, &m_bufferHeight);
  glfwMakeContextCurrent(m_window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD!" << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glEnable(GL_DEPTH_TEST);
  glViewport(0, 0, m_bufferWidth, m_bufferHeight);
  return EXIT_SUCCESS;
}
