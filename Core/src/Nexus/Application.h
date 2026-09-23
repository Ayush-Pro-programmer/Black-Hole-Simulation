#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include <memory>

namespace Nexus {

	class NEXUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Windows;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
