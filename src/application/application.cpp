#include "application/application.h"

// implementation...
void Application::createWindow(GLint width, GLint height) {
  m_window = std::make_unique<Window>(width, height);
}

const std::unique_ptr<Window> &Application::getWindow() { return m_window; }
