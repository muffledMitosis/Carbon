#pragma once

extern Carbon::Application* Carbon::CreateApplication();

int main()
{
	auto app = Carbon::CreateApplication();
	app->Run();
	return 0;
}
