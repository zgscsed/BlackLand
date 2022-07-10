/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��1��21:43:29
 * @Description: ��Ⱦʹ��api�汾���������ܲ�ֹ֧��opengl�İ汾
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