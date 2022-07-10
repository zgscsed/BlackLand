/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年7月1日21:43:29
 * @Description: 渲染使用api版本，后续可能不止支持opengl的版本
 */

#ifndef RENDERER_API_HPP_
#define RENDERER_API_HPP_

#include "Abyss/Core/Base.hpp"
#include <glm/glm.hpp>

namespace Abyss {

	class RendererAPI {
	public:
		// api类型
		enum class API
		{
			None = 0,
			OpenGL = 1
		};

		virtual ~RendererAPI() = default;

		// 初始化函数， 一般是需要的
		virtual void Init() = 0;
		// 设置视口， 调整视角的时候可以改变，放大缩小
		virtual void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;
		// 每一次渲染清除一下
		virtual void SetClearColor(const glm::vec4& color) = 0;
		// 清除颜色缓存
		virtual void Clear() = 0;

		// 其他Render类，判断当前API 是哪类 
		static API GetAPI() { return API_; }
		static Scope<RendererAPI> Create();
	private:
		static API API_;
	};
}


#endif //!RENDERER_API_HPP_