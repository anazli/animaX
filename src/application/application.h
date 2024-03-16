#pragma once

#include <memory>

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
  void render();

 private:
  std::unique_ptr<Window> m_window;

  // virtual void Initialize();
  // virtual void Update(float deltaTime);
  // virtual void Render(float aspectRatio);
  // virtual void ShutDown();
};
