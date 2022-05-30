/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月30日19:38:35
 * @Description: windows 平台下的窗口类
 */

#include "Abyss/Core/Base.hpp"
#include "Platform/Windows/WindowWindow.hpp"

#include "Abyss/Event/ApplicationEvent.hpp"

namespace Abyss {

	static int windowCount = 0;
	static void GLFWErrorCallback(int error, const char* description)
	{
		ABYSS_LOG_ERROR<<"GLFW Error "<< error<<" : "<< description;
	}
WindowWindow::WindowWindow(const WindowProps& props)
{
	Init(props);
}
WindowWindow::~WindowWindow()
{
	Shutdown();
}

void WindowWindow::OnUpdate()
{

}

int WindowWindow::GetWidth() const
{
	return data_.width_;
}
int WindowWindow::GetHeight() const
{
	return data_.height_;
}

// window attributes
void WindowWindow::SetEventCallback(const EventCallback& callback)
{
	data_.eventCallback_ = callback;
}

void* WindowWindow::GetNativeWindow() const
{
	return window_;
}

int WindowWindow::Init(const WindowProps& props)
{
	data_.title_ = props.title_;
	data_.width_ = props.width_;
	data_.height_ = props.height_;

	ABYSS_LOG_INFO << "Create window " << props.title_ << " ; width:" << props.width_ << " ;height: " << props.height_;

	if (windowCount == 0)
	{
		ABYSS_LOG_INFO << "glfwInit";
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwSetErrorCallback(GLFWErrorCallback);
	}

	window_ = glfwCreateWindow(data_.width_, data_.height_, data_.title_.c_str(), nullptr, nullptr);
	if (window_ == nullptr)
	{
		ABYSS_LOG_ERROR << "Failed to create GLFW window";
		glfwTerminate();
		return -1;
	}
	++windowCount;

	//glfwMakeContextCurrent(window_);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glfwSetWindowUserPointer(window_, &data_);

	// set glfw callbacks
	glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		WindowCloseEvent event;
		data.eventCallback_(event);
		});
}

void WindowWindow::Shutdown()
{

}

}