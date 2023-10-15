#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "application.h"

using namespace std;

int main() {
  GLuint WIDTH = 800, HEIGHT = 600;
  if (!glfwInit()) {
    cout << "GLFW initialization failed!" << endl;
    return 1;
  }
  // setup glfw window properties
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  auto app = Application{};
  cout << "Hello Test Application" << endl;

  return 0;
}
