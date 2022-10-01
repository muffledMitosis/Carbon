#include "AppWindow.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstddef>
#include <iostream>

namespace Carbon {
ApplicationWindow::ApplicationWindow()
{
  glfwInit();
  int code = glfwGetError(NULL);
  if (code != GLFW_NO_ERROR)
  {
    std::cout << code << std::endl;
    exit(1);
  }
  this->window = glfwCreateWindow(800, 600, "LMAO", NULL, NULL);
  glfwMakeContextCurrent(this->window);
  gladLoadGL();
  //if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
  //  std::cout << "Failed to initialize GLAD" << std::endl;
  //  //return -1;
  //} 
	std::cout << "WINDOW CREATED" << std::endl;
}

ApplicationWindow::~ApplicationWindow()
{
}
}
