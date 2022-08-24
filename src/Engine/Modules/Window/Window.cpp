#include "Window.hpp"
#include <GLFW/glfw3.h>
#include <cstddef>

namespace Carbon {
Window::Window()
{
  glfwInit();
  this->window = glfwCreateWindow(800, 600, "LMAO", NULL, NULL);
  glfwMakeContextCurrent(this->window);
}

Window::~Window()
{
}
}
