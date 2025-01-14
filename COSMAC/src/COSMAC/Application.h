#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "COSMAC/Events/ApplicationEvent.h"

#include "Window.h"

namespace COSMAC 
{
	class COSMAC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}