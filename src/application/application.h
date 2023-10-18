#pragma once

class Application {
 public:
  Application() = default;
  Application(const Application& other) = delete;
  Application& operator=(const Application& other) = delete;
  Application(Application&& other) = delete;
  Application operator=(Application&& other) = delete;
  ~Application() = default;

  //virtual void Initialize();
  //virtual void Update(float deltaTime);
  //virtual void Render(float aspectRatio);
  //virtual void ShutDown();
};
