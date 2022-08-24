#pragma once

#include "../../Core.h"
#include <string>
#include <GLFW/glfw3.h>

namespace Carbon {
class C_API Window
{
public:
  unsigned int width, height;
  std::string name;
  GLFWwindow* window;
  Window ();
  ~Window ();

private:
  /* data */
};
}

