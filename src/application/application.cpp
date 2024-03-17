#include "application/application.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// implementation...
void Application::createWindow(GLint width, GLint height,
                               const std::string &title) {
  m_window = std::make_unique<Window>(width, height, title);
}

const std::unique_ptr<Window> &Application::getWindow() { return m_window; }

void Application::render(std::vector<MeshPtr> &meshContainer,
                         std::vector<ShaderPtr> shaderContainer) {
  while (!m_window->shouldClose()) {
    glfwPollEvents();
    glClearColor(0.1f, 0.4f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    GLuint uniformProjection = 0, uniformModel = 0;
    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),
        (GLfloat)m_window->bufferWidth() / m_window->bufferHeight(), 0.1f,
        100.0f);
    for (const ShaderPtr &s : shaderContainer) {
      s->use();
      uniformModel = s->getModel();
      uniformProjection = s->getProjection();
    }
    glm::mat4 model(1.0f);

    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
    model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(uniformProjection, 1, GL_FALSE,
                       glm::value_ptr(projection));
    meshContainer[0]->render();

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 1.0f, -2.5f));
    model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
    meshContainer[1]->render();

    glUseProgram(0);
    m_window->swapBuffers();
  }
}
