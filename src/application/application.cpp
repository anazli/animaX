#include "application/application.h"

// implementation...
void Application::createWindow(GLint width, GLint height,
                               const std::string &title) {
  m_window = std::make_unique<Window>(width, height, title);
}

const std::unique_ptr<Window> &Application::getWindow() { return m_window; }

void Application::render() {
  while (!m_window->shouldClose()) {
    glClearColor(0.1f, 0.4f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    m_window->swapBuffers();
    glfwPollEvents();
  }
}
