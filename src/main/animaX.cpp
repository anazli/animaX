#include <iostream>
#include <memory>

#include "application/application.h"
#include "mesh/mesh.h"
#include "shader/shader.h"

/*
#ifdef __linux__
#include "platform/linux_main.h"
#else
#include "platform/win32_main.h"
#endif
*/

using namespace std;

int main() {
  Application app;
  app.createWindow(800, 600, "AnimaX");

  string vertex("src/shader/shader.vert");
  string fragment("src/shader/shader.frag");
  shared_ptr<Shader> shader = make_shared<Shader>();
  shader->createFromFile(vertex, fragment);

  unsigned int indices[] = {0, 3, 1, 1, 3, 2, 2, 3, 0, 0, 1, 2};

  GLfloat vertices[] = {-1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f,
                        1.0f,  -1.0f, 0.0f, 0.0f, 1.0f,  0.0f};
  shared_ptr<Mesh> mesh = make_shared<Mesh>();
  mesh->create(vertices, indices, 12, 12);

  vector<MeshPtr> meshCont;
  meshCont.push_back(mesh);
  vector<ShaderPtr> shaderCont;
  shaderCont.push_back(shader);

  app.render(meshCont, shaderCont);

  return 0;
}
