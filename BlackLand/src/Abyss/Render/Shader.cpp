/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月10日18:11:13
 * @Description: 着色器基类，加载顶点着色器和片元着色器，绑定， 设置uniform变量
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