/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月1日21:43:29
 * @Description: 渲染使用api版本，后续可能不止支持opengl的版本
 */

#include "Abyss/Render/RendererAPI.hpp"
namespace Abyss {
	RendererAPI::API RendererAPI::API_ = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (API_)
		{
		case Abyss::RendererAPI::API::None:
			ABYSS_LOG_ERROR << "RendererAPI::None is currently";
			return nullptr;
		case Abyss::RendererAPI::API::OpenGL:
			break;
		default:
			break;
		}
	}
}