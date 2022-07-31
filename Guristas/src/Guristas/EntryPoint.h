#pragma once

#ifdef GURISTAS_PLATFORM_WINDOWS

extern Guristas::Application* Guristas::CreateApplication();

int main(int argc, char** argv)
{
	Guristas::Logger::Init();

	GURISTAS_CORE_WARN("Logger initialize");
	GURISTAS_CLIENT_WARN("Logger initialize");

	auto app = Guristas::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Guristas inly support Windows!
#endif