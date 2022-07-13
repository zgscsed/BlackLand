/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月13日22:55:28
 * @Description: buffer基类， 顶点缓冲对象
 */

#include "Platform/OpenGL/OpenGLBuffer.hpp"

#include <glad/glad.h>

namespace Abyss {
	OpenGLVertexBuffer::OpenGLVertexBuffer(uint size)
	{
		glGenBuffers(1, &rendererID_);
		glBindBuffer(GL_ARRAY_BUFFER, rendererID_);
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
	}
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint size)
	{
		glGenBuffers(1, &rendererID_);
		glBindBuffer(GL_ARRAY_BUFFER, rendererID_);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &rendererID_);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, rendererID_);
	}
	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);   // 解绑都是使用0
	}

	void OpenGLVertexBuffer::SetData(const void* data, uint size)
	{
		glBindBuffer(GL_ARRAY_BUFFER, rendererID_);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}
}
