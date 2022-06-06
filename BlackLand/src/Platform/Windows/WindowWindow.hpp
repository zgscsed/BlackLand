/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��5��30��19:38:35
 * @Description: windows ƽ̨�µĴ�����
 */

#ifndef WINDOW_WINDOW_HPP_
#define WINDOW_WINDOW_HPP_

# include "Abyss/Core/Window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Abyss {
	class WindowWindow : public Window{
	public:
		WindowWindow(const WindowProps& pros);
		virtual ~WindowWindow();

		void OnUpdate() override;

		int GetWidth() const override;
		int GetHeight() const override;

		// window attributes
		virtual void SetEventCallback(const EventCallback& callback);

		virtual void* GetNativeWindow() const;

	private:
		virtual int Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* window_;
		// ����glfw�У� �¼�����ʱ��ȡ���ص�
		struct WindowData {
			std::string title_;
			int width_;
			int height_;

			EventCallback eventCallback_;
		};

		WindowData data_;
	};
}

#endif // !WINDOW_WINDOW_HPP_
