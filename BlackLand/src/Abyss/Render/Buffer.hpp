/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��13��22:55:28
 * @Description: buffer���࣬ ���㻺�����
 */


#ifndef BUFFER_HPP_
#define BUFFER_HPP_


#include "Abyss/Core/Base.hpp"

namespace Abyss {
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetData(const void* data, uint size) = 0;

		static Ref<VertexBuffer> Create(uint size);
		static Ref<VertexBuffer> Create(float* vertices, uint size);
	};
}
#endif // !BUFFER_HPP_