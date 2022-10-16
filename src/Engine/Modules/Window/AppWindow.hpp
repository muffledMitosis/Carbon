#pragma once

#include "../../Core.h"
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Carbon
{
class C_API ApplicationWindow
{
public:
	unsigned int width	= 800;
	unsigned int height = 800;
	std::string name		= "LMAOOO";
	GLFWwindow* window;
	ApplicationWindow();
	~ApplicationWindow();

private:
	/* data */
};
}	 // namespace Carbon
