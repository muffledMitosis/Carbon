#pragma once
#include "../Core.h"
namespace Carbon {

  class C_API Application
  {
  public:
    Application();
    ~Application();
    void Run();
  };
  // Client defines this
  Application* CreateApplication();
}
