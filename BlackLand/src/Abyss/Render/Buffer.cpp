/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��13��22:55:28
 * @Description: buffer���࣬ ���㻺�����
 */


#include "Abyss/Render/RendererAPI.hpp"

#include "Abyss/Render/Buffer.hpp"
#include "Platform/OpenGL/OpenGLBuffer.hpp"

namespace Abyss {

	Ref<VertexBuffer> VertexBuffer::Create(uint size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			ABYSS_LOG_ERROR << "RendererAPI::None is currently";
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLVertexBuffer>(size);
		}
		ABYSS_LOG_ERROR << " unknown vertexBuffer rendererAPI type";
		return nullptr;
	}

	Ref<VertexBuffer> VertexBuffer::Create(float *vertices, uint size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			ABYSS_LOG_ERROR << "RendererAPI::None is currently";
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}
		ABYSS_LOG_ERROR << " unknown vertexBuffer rendererAPI type";
		return nullptr;
	}
}