#include "nxpch.h"
#include "Application.h"
#include "Logger.h"

namespace Nexus {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() 
	{
		m_Windows = std::make_unique<Window>(WindowProps("[Nexus]", 1280, 720));
		m_Windows->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() 
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		NX_CORE_TRACE("{0}", e.ToString());
	}

	void Application::Run() 
	{
		while (m_Running) 
		{
			m_Windows->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}