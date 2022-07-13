/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月13日22:55:28
 * @Description: 封装 opengl顶点缓冲对象 VBO
 */

#ifndef OPENGL_VERTEX_BUFFER_HPP_
#define OPENGL_VERTEX_BUFFER_HPP_
#include "Abyss/Render/Buffer.hpp"

namespace Abyss {
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint size);
		OpenGLVertexBuffer(float* vertices, uint size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetData(const void* data, uint size) override;

	private:
		uint rendererID_;
	};
}

#endif // !OPENGL_VERTEX_BUFFER_HPP_