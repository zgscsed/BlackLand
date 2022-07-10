/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��7��22:59:35
 * @Description: ��������࣬���������󶨵���ɫ����,����������������Ļ���
 */

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_
#include "Abyss/Core/Base.hpp"

namespace Abyss {

	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual uint GetWidth() const = 0;
		virtual uint GetHeight() const = 0;
		virtual uint GetRendererID() const = 0;

		virtual void SetData(void* data, uint size) = 0;

		virtual void Bind(uint slot = 0) const = 0;

		virtual bool IsLoaded() const = 0;

		virtual bool operator==(const Texture& other) const = 0;

	};

	// 2D ������ʱҲֻ������2d����ʾ
	class Texture2D : public Texture
	{
	public:
		static Ref<Texture2D> Create(uint width, uint height);
		static Ref<Texture2D> Create(const std::string& path);
	};

}

#endif // !TEXTURE_HPP_