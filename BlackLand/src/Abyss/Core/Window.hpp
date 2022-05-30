/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月29日20:25:17
 * @Description: 窗口类基类
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "Abyss/Core/Base.hpp"

#include "Abyss/Event/Event.hpp"

#include <functional>

namespace Abyss {

	struct WindowProps {
		std::string title_;
		int width_;
		int height_;

		WindowProps(const std::string &title = "BlackLand", int width = 1600, int height = 900)
			: title_(title),
			  width_(width),
			  height_(height)
		{}
	};

	// 基类：窗口的大小，名称
	class Window {
	public:
		using EventCallback = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

		// window attributes
		virtual void SetEventCallback(const EventCallback& callback) = 0;

		virtual void* GetNativeWindow() const = 0;

		static Scope<Window> Create(const WindowProps& props = WindowProps());
	};
}

#endif // !WINDOW_HPP_
