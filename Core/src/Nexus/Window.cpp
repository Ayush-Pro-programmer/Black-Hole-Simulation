#include "nxpch.h"
#include "Window.h"
#include "Logger.h"
#include "Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Nexus {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* desc)
	{
		NX_CORE_ERROR("GLFW error ({0}): {1}", error, desc);
	}

	Window::Window(const WindowProps& props)
	{
		Init(props);
	}

	Window::~Window() 
	{
		Shutdown();
	}

	void Window::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		NX_CORE_INFO("Creating window {0} ({1}x{2})", m_Data.Title, m_Data.Width, m_Data.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			if (!success)
			{
				NX_CORE_CRITICAL("Could not initialized GLFW!");
				return;
			}
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		// we are targeting OpenGL 4.6 core profile
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(
			(int)props.Width, (int)props.Height,
			props.Title.c_str(),
			nullptr, nullptr
		);
		if (!m_Window)
		{
			NX_CORE_CRITICAL("Failed to create GLFW window!");
			return;
		}

		NX_CORE_INFO("GLFW window created successfully");

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// set initial clear color once state is valid
		glClearColor(0.4f, 0.58f, 0.92f, 1.0f);

		// ----------------------------------------
		// GLFW callacks -> Nexus Event System
		// ----------------------------------------

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) 
		{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
		});

		glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos)
		{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowMovedEvent event(xpos, ypos);
				data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				data.EventCallback(event);
		});

		//TODO: Add remaing window events later...
	}

	void Window::Shutdown()
	{
		if (m_Window)
			glfwDestroyWindow(m_Window);

		// Terminate glfw if needed
		if (s_GLFWInitialized)
		{
			glfwTerminate();
			s_GLFWInitialized = false;
		}
	}

	void Window::OnUpdate()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}
}