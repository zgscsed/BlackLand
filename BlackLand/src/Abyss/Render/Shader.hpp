/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��10��18:11:13
 * @Description: ��ɫ�����࣬���ض�����ɫ����ƬԪ��ɫ��
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

		virtual void Bind() = 0;       // ������ɫ������
		virtual void Unbind() = 0;     // ͨ������id 0���

		// uniform���ߺ���
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
