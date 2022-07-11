/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��10��18:11:13
 * @Description: ��ɫ�����࣬���ض�����ɫ����ƬԪ��ɫ�����󶨣� ����uniform����
 */

#include "Abyss/Render/Shader.hpp"
#include "Abyss/Render/RendererAPI.hpp"

#include "Platform/OpenGL/OpenGLShader.hpp"
namespace Abyss {
	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			ABYSS_LOG_ERROR << "RendererAPI::API::None is currently not support ";
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLShader>(name, vertexPath, fragmentPath);
		}
		ABYSS_LOG_INFO << "unknown API type";
		return nullptr;
	}
}