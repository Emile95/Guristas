#pragma once

#ifdef GURISTAS_PLATFORM_WINDOWS

extern Guristas::Application* Guristas::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Guristas::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Guristas inly support Windows!
#endif