#pragma once

#ifdef NX_PLATFORM_WINDOWS

extern Nexus::Application* Nexus::CreateApplication();

int main(int argc, char** argv) 
{
	Nexus::Logger::Init();

	NX_CORE_TRACE("Initialized Logger!");
	NX_INFO("Initialized Logger v{}!", 0.1);
	NX_CORE_WARN("Initialized Logger!");
	NX_ERROR("Initialized Logger v{}!", 0.1);
	NX_CORE_CRITICAL("Initialized Logger!");

	auto app = Nexus::CreateApplication();
	app->Run();
	delete app;
}

#endif