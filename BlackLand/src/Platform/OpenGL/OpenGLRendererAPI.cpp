/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��6��22:46:10
 * @Description: opengl�汾����Ⱦapi
 */

#include "Platform/OpenGL/OpenGLRendererAPI.hpp"

#include <glad/glad.h>

namespace Abyss{
	void OpenGLRendererAPI::Init()
	{
		// �������������ʼ��opengl��״̬��������һЩ����
		// ����
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