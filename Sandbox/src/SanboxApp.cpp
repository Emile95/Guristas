#include <Guristas.h>

class Sandbox : public Guristas::Application
{
};

Guristas::Application* Guristas::CreateApplication()
{
	return new Sandbox();
}