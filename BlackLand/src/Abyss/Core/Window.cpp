/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��5��30��19:38:35
 * @Description: ���ڻ���
 */

#include "Abyss/Core/Window.hpp"

#ifdef AS_PLATFORM_WINDOWS
#include "Platform/Windows/WindowWindow.hpp"
#endif // AS_PLATFORM_WINDOWS


namespace Abyss {
	// Ϊ�����ò�ͬ��ƽ̨�� ��Ҫ����������ʱ����Ҫ�ж�ƽ̨������Ҳ�����Ƶķ�����ͨ���ӿڻ�ȡ��ͬ��ƽ̨ʵ��
	Scope<Window> Create(const WindowProps& props)
	{
		#ifdef AS_PLATFORM_WINDOWS
			return CreateScope<WindowWindow>(props);
		#else 
			AS_LOG_ERROR << "Unknown platform!";
			return nullptr;
		#endif
	}
}