/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月7日22:59:35
 * @Description: 纹理类基类，加载纹理，绑定到着色器上,这里是所有纹理类的基类
 */

#include "Abyss/Render/RendererAPI.hpp"

#include "Abyss/Render/Texture.hpp"

#include "Platform/OpenGL/OpenGLTexture.hpp"

namespace Abyss {
	Ref<Texture2D> Texture2D::Create(uint width, uint height)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			ABYSS_LOG_ERROR<<"RendererAPI::API::None is currently not support";
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(width, height);
		}
		ABYSS_LOG_INFO << "unknown texture API type";
		return nullptr;
	}
	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			ABYSS_LOG_ERROR << "RendererAPI::API::None is currently not support";
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(path);
		}
		ABYSS_LOG_INFO << "unknown texture API type";
		return nullptr;
	}
}