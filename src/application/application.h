#pragma once

#include <KHR/khrplatform.h>

#include <memory>
#include <vector>

#include "mesh/mesh.h"
#include "shader/shader.h"
#include "window/window.h"

class Application {
 public:
  Application() = default;
  Application(const Application& other) = delete;
  Application& operator=(const Application& other) = delete;
  Application(Application&& other) = delete;
  Application operator=(Application&& other) = delete;

  void createWindow(GLint width = 500, GLint height = 500,
                    const std::string& title = std::string());
  const std::unique_ptr<Window>& getWindow();
  void render(std::vector<MeshPtr>& meshContainer,
              std::vector<ShaderPtr> shaderContainer);

 private:
  std::unique_ptr<Window> m_window;

  // virtual void Initialize();
  // virtual void Update(float deltaTime);
  // virtual void Render(float aspectRatio);
  // virtual void ShutDown();
};
