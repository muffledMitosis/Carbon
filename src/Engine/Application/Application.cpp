#include "Application.hpp"

namespace Carbon
{
Application::Application() {}
Application::~Application() {}

void Application::Run()
{
	while(this->ExitCondition)
	{
		this->Update();
	}
}
}	 // namespace Carbon
