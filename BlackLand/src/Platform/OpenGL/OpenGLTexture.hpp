/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��7��23:34:14
 * @Description: opengl�汾�������� 2D����ʱ�Կ���2d��ʾ
 */

#include "Abyss/Render/Texture.hpp"
#include <glad/glad.h>

namespace Abyss {

	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(uint width, uint height);
		OpenGLTexture2D(const std::string& path);
		virtual ~OpenGLTexture2D();

		virtual uint GetWidth() const override { return width_; }
		virtual uint GetHeight() const override { return height_; }
		virtual uint GetRendererID() const override { return rendererID_; }

		virtual void Bind(uint slot = 0) const override {};
		virtual bool IsLoaded() const override { return isLoaded_; }
		virtual bool operator==(const Texture& other) const override
		{
			return rendererID_ == ((OpenGLTexture2D&)other).rendererID_;
		}

	private:
		std::string path_;
		bool isLoaded_;
		uint width_;
		uint height_;
		uint rendererID_;
		GLenum internalFormat_;    // ����ͼƬ�ĸ�ʽ
		GLenum dataFormat_;        // ����ͼƬ�ĸ�ʽ
	};

}