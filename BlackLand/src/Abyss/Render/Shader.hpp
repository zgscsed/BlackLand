/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月10日18:11:13
 * @Description: 着色器基类，加载顶点着色器和片元着色器
 */

#ifndef SHADER_HPP_
#define SHADER_HPP_

#include "Abyss/Core/Base.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Abyss {
	class Shader 
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() = 0;       // 激活着色器程序
		virtual void Unbind() = 0;     // 通过传入id 0解除

		// uniform工具函数
		virtual void SetBool(const std::string &name, bool value) const = 0;
		virtual void SetInt(const std::string &name, int value) const = 0;
		virtual void SetFloat(const std::string& name, float value) const = 0;

		virtual void SetVec2(const std::string& name, const glm::vec2& value) const = 0;
		virtual void SetVec2(const std::string& name, float x, float y) const = 0;
		virtual void SetVec3(const std::string& name, const glm::vec3& value) const = 0;
		virtual void SetVec3(const std::string& name, float x, float y, float z) const = 0;
		virtual void SetVec4(const std::string& name, const glm::vec4& value) const = 0;
		virtual void SetVec4(const std::string& name, float x, float y, float z, float w) const = 0;
		virtual void SetMat2(const std::string& name, const glm::mat2& mat) const = 0;
		virtual void SetMat3(const std::string& name, const glm::mat3& mat) const = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& mat) const = 0;

		virtual const std::string& GetName() const = 0;
		static Ref<Shader> Create(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
	};
}


#endif // !SHADER_HPP_
