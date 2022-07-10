/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��1��21:43:29
 * @Description: ��Ⱦʹ��api�汾���������ܲ�ֹ֧��opengl�İ汾
 */

#ifndef RENDERER_API_HPP_
#define RENDERER_API_HPP_

#include "Abyss/Core/Base.hpp"
#include <glm/glm.hpp>

namespace Abyss {

	class RendererAPI {
	public:
		// api����
		enum class API
		{
			None = 0,
			OpenGL = 1
		};

		virtual ~RendererAPI() = default;

		// ��ʼ�������� һ������Ҫ��
		virtual void Init() = 0;
		// �����ӿڣ� �����ӽǵ�ʱ����Ըı䣬�Ŵ���С
		virtual void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;
		// ÿһ����Ⱦ���һ��
		virtual void SetClearColor(const glm::vec4& color) = 0;
		// �����ɫ����
		virtual void Clear() = 0;

		// ����Render�࣬�жϵ�ǰAPI ������ 
		static API GetAPI() { return API_; }
		static Scope<RendererAPI> Create();
	private:
		static API API_;
	};
}


#endif //!RENDERER_API_HPP_