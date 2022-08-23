#pragma once
#include "../Core.h"
namespace Carbon {

  class C_API Application
  {
  public:
    Application();
    ~Application();
    bool ExitCondition;
    virtual void Update()=0;
    void Run();
  };
  // Client defines this
  Application* CreateApplication();
}
