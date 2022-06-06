/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月30日19:38:35
 * @Description: 窗口基类
 */

#include "Abyss/Core/Window.hpp"

#ifdef AS_PLATFORM_WINDOWS
#include "Platform/Windows/WindowWindow.hpp"
#endif // AS_PLATFORM_WINDOWS


namespace Abyss {
	// 为了适用不同的平台， 需要将创建对象时，需要判断平台，其它也是类似的方法，通过接口获取不同的平台实例
	Scope<Window> Window::Create(const WindowProps& props)
	{
		#ifdef AS_PLATFORM_WINDOWS
			return CreateScope<WindowWindow>(props);
		#else 
			AS_LOG_ERROR << "Unknown platform!";
			return nullptr;
		#endif
	}
}