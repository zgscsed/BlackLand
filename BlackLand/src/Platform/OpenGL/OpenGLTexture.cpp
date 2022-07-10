/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月7日23:34:14
 * @Description: opengl版本的纹理类 2D。暂时自考虑2d显示
 */

#include "Platform/OpenGL/OpenGLTexture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <GLFW/glfw3.h>

namespace Abyss {
	OpenGLTexture2D::OpenGLTexture2D(uint width, uint height)
		:width_(width),
		 height_(height)
	{
		isLoaded_ = false;
		internalFormat_ = GL_RGBA8;
		dataFormat_ = GL_RGBA;

		glGenTextures(1, &rendererID_);
		glBindTexture(GL_TEXTURE_2D, rendererID_);
		glTextureStorage2D(rendererID_, 1, internalFormat_, width_, height_);
		glTexParameteri(rendererID_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(rendererID_, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexParameteri(rendererID_, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(rendererID_, GL_TEXTURE_WRAP_T, GL_REPEAT);

		//glTexImage2D(GL_TEXTURE_2D, 0, internalFormat_, width_, height_, 0, dataFormat_, GL_UNSIGNED_BYTE, nullptr);
	}
	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		:path_(path)
	{
		int width, height, channels;
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		if (data != nullptr)
		{
			isLoaded_ = true;
			width_ = width;
			height_ = height;

			ABYSS_LOG_INFO << "chanels:" << channels;
			if (channels == 4)
			{
				internalFormat_ = GL_RGBA;
				dataFormat_ = GL_RGBA;
			}
			else if (channels == 3)
			{
				internalFormat_ = GL_RGB;
				dataFormat_ = GL_RGB;
			}

			glGenTextures(1, &rendererID_);
			glBindTexture(GL_TEXTURE_2D, rendererID_);
			// set the texture wrapping parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
			// set the texture filtering parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, internalFormat_, width_, height_, 0, dataFormat_, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			stbi_image_free(data);
		 }
	}
	OpenGLTexture2D::~OpenGLTexture2D()
	{

	}

	void OpenGLTexture2D::Bind(uint slot) const
	{
		glActiveTexture(slot);
		glBindTexture(GL_TEXTURE_2D, rendererID_);
	}
}
