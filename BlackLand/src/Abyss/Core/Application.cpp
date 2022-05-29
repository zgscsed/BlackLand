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
		: isRunning_(false)
	{
		ABYSS_LOG_INFO << "Application constructor...";
	}
	Application::~Application()
	{
		ABYSS_LOG_INFO << "Application destructor...";
	}

	// 应用程序执行
	void Application::Exec()
	{
		LOG_INFO << "Application destructor...";
		while (isRunning_)
		{

		}
	}

}