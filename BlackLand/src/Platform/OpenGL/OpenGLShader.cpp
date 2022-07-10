/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��10��18:11:13
 * @Description: ��ɫ���࣬���ض�����ɫ����ƬԪ��ɫ�����󶨣� ����uniform���������ļ��ж�ȡ��ɫ����Ȼ��������ӣ������д�����
 */

#include "abysspch.h"
#include "Platform/OpenGL/OpenGLShader.hpp"

namespace Abyss {
	OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
		:name_(name)
	{
		// 1 ���ļ�·���л�ȡ���㡢Ƭ����ɫ��
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		// ��֤�����׳��쳣
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			// ���ļ�
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			// ��ȡ�ļ�������
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// �ر��ļ�
			vShaderFile.close();
			fShaderFile.close();
			// ��������string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();

			ABYSS_LOG_INFO << "vertex:" << vertexCode;
		}
		catch (std::ifstream::failure e)
		{
			ABYSS_LOG_ERROR << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what();
		}

		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		// 2 ����
		unsigned int vertex, fragment;
		// vertex shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		CheckCompileErrors(vertex, "VERTEX");

		// fragment shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		CheckCompileErrors(fragment, "FRAGMENT");

		// shader program
		rendererID_ = glCreateProgram();
		glAttachShader(rendererID_, vertex);
		glAttachShader(rendererID_, fragment);

		glLinkProgram(rendererID_);
		CheckCompileErrors(rendererID_, "PROGRAM");

		// delete vertex fragment shader
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(rendererID_);
	}

	// ����shader program
	void OpenGLShader::Bind()
	{
		glUseProgram(rendererID_);
	}
	void OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}

	// uniform���ߺ���
	void OpenGLShader::SetBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(rendererID_, name.c_str()), value);
	}
	void OpenGLShader::SetInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(rendererID_, name.c_str()), value);
	}
	void OpenGLShader::SetFloat(const std::string& name, float value) const
	{
		glUniform1i(glGetUniformLocation(rendererID_, name.c_str()), value);
	}

	void OpenGLShader::SetVec2(const std::string& name, const glm::vec2& value) const
	{
		glUniform2fv(glGetUniformLocation(rendererID_, name.c_str()), 1, &value[0]);
	}
	void OpenGLShader::SetVec2(const std::string& name, float x, float y) const
	{
		glUniform2f(glGetUniformLocation(rendererID_, name.c_str()), x, y);
	}
	void OpenGLShader::SetVec3(const std::string& name, const glm::vec3& value) const
	{
		glUniform3fv(glGetUniformLocation(rendererID_, name.c_str()), 1, &value[0]);
	}
	void OpenGLShader::SetVec3(const std::string& name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(rendererID_, name.c_str()), x, y, z);
	}
	void OpenGLShader::SetVec4(const std::string& name, const glm::vec4& value) const
	{
		glUniform4fv(glGetUniformLocation(rendererID_, name.c_str()), 1, &value[0]);
	}
	void OpenGLShader::SetVec4(const std::string& name, float x, float y, float z, float w) const
	{
		glUniform4f(glGetUniformLocation(rendererID_, name.c_str()), x, y, z, w);
	}
	void OpenGLShader::SetMat2(const std::string& name, const glm::mat2& mat) const
	{
		glUniformMatrix2fv(glGetUniformLocation(rendererID_, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	void OpenGLShader::SetMat3(const std::string& name, const glm::mat3& mat) const
	{
		glUniformMatrix3fv(glGetUniformLocation(rendererID_, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(rendererID_, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}

	const std::string& OpenGLShader::GetName() const
	{
		return name_;
	}

	bool OpenGLShader::CheckCompileErrors(GLint shader, std::string type)
	{
		GLint success;
		GLchar infoLog[1024];

		if (type != "RPOGRAM")
		{

		}
		else
		{
			// ��
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				// ��ȡ��־
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				ABYSS_LOG_ERROR << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- -----------------------------------------------------";
				return true;
			}
		}

		return false;
	}
}
