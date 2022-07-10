/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��7��6��22:46:10
 * @Description: opengl�汾����Ⱦapi
 */

#ifndef OPENGL_RENDERER_API_HPP_
#define OPENGL_RENDERER_API_HPP_


#include "Abyss/Render/RendererAPI.hpp"

namespace Abyss {

	class OpenGLRendererAPI : public RendererAPI {
	public:
		virtual void Init() override;
		virtual void SetViewport(uint x, uint y, uint width, uint height) override;

		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;
	};
}

#endif   // !OPENGL_RENDERER_API_HPP_