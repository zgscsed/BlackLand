/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月27日20:25:17
 * @Description:
 */

#include "abysspch.h"
#include "Base.hpp"
#include "Application.hpp"



namespace Abyss {

	Application::Application(const std::string& name)
		: isRunning_(true)
	{
		ABYSS_LOG_INFO << "Application constructor...";
		window_ = Window::Create(WindowProps(name));
		window_->SetEventCallback(AS_BIND_EVENT_FN(Application::OnEvent));
	}
	Application::~Application()
	{
		ABYSS_LOG_INFO << "Application destructor...";
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(AS_BIND_EVENT_FN(Application::OnWindowClose));
	}

	// 应用程序执行
	void Application::Exec()
	{
		LOG_INFO << "Application destructor...";
		while (isRunning_)
		{

			// 更新
			window_->OnUpdate();
		}
	}

	bool Application::OnWindowClose(Event& e)
	{
		isRunning_ = false;
		return true;
	}

}