#include "cpch.h"

#include "Application.h"

#include <GLFW/glfw3.h>

namespace COSMAC
{
	#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		COSMAC_CORE_INFO("{0}", e);
	}

	void Application::Run()
	{
		WindowResizeEvent e(800, 600);
		COSMAC_TRACE(e);

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
	
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}