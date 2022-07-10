/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月10日18:11:13
 * @Description: 着色器基类，加载顶点着色器和片元着色器，绑定， 设置uniform变量
 */

#include "Abyss/Render/Shader.hpp"
#include "Abyss/Render/RendererAPI.hpp"
namespace Abyss {
	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
	{
		ABYSS_LOG_INFO << "需要完善";
		return nullptr;
	}
}