/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��10��18:11:13
 * @Description: ��ɫ���࣬���ض�����ɫ����ƬԪ��ɫ�����󶨣� ����uniform���������ļ��ж�ȡ��ɫ����Ȼ��������ӣ������д�����
 */

#ifndef OPENGL_SHADER_HPP_
#define OPENGL_SHADER_HPP_

#include "Abyss/Render/Shader.hpp"

namespace Abyss {
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
		~OpenGLShader();

		virtual void Bind() override;
		virtual void Unbind() override;

		// uniform���ߺ���
		virtual void SetBool(const std::string& name, bool value) const override;
		virtual void SetInt(const std::string& name, int value) const override;
		virtual void SetFloat(const std::string& name, float value) const override;

		virtual void SetVec2(const std::string& name, const glm::vec2& value) const override;
		virtual void SetVec2(const std::string& name, float x, float y) const override;
		virtual void SetVec3(const std::string& name, const glm::vec3& value) const override;
		virtual void SetVec3(const std::string& name, float x, float y, float z) const override;
		virtual void SetVec4(const std::string& name, const glm::vec4& value) const override;
		virtual void SetVec4(const std::string& name, float x, float y, float z, float w) const override;
		virtual void SetMat2(const std::string& name, const glm::mat2& mat) const override;
		virtual void SetMat3(const std::string& name, const glm::mat3& mat) const override;
		virtual void SetMat4(const std::string& name, const glm::mat4& mat) const override;

		virtual const std::string& GetName() const override;

	private:
		bool CheckCompileErrors(GLint shader, std::string type);

		uint rendererID_;              // ��ɫ�������id shader program id ������ͳһ����
		std::string name_;


	};
}

#endif // !OPENGL_SHADER_HPP_