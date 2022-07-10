/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月6日22:46:10
 * @Description: opengl版本的渲染api
 */

#include "Platform/OpenGL/OpenGLRendererAPI.hpp"

#include <glad/glad.h>

namespace Abyss{
	void OpenGLRendererAPI::Init()
	{
		// 这里可以用来初始化opengl的状态机，设置一些开关
		// 比如
		// glEnable(GL_DEPTH_TEST);
	}
	void OpenGLRendererAPI::SetViewport(uint x, uint y, uint width, uint height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}
	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}