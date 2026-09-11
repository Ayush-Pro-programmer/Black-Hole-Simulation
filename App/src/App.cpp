#include <Nexus.h>

class Sandbox : public Nexus::Application 
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

Nexus::Application* Nexus::CreateApplication() {
	return new Sandbox();
}