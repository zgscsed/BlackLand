/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月30日19:38:35
 * @Description: windows 平台下的窗口类
 */


#include "Platform/Windows/WindowWindow.hpp"

#include "Abyss/Event/ApplicationEvent.hpp"

namespace Abyss {

	static int windowCount = 0;
	static void GLFWErrorCallback(int error, const char* description)
	{
		ABYSS_LOG_ERROR<<"GLFW Error "<< error<<" : "<< description;
	}

	// 输入
	void processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, width, height);
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
	//ABYSS_LOG_INFO << "Window update...";
	// input
// -----
	//processInput(window_);

	// render
	// ------
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	// -------------------------------------------------------------------------------
	glfwSwapBuffers(window_);
	glfwPollEvents();
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
		glfwTerminate(); 
		// 这个调用ABYSS_LOG_ERROR 提出非法标记
		ABYSS_LOG_ERROR << "Failed to create GLFW window";
		return -1;
	}
	++windowCount;

	glfwMakeContextCurrent(window_);
	glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ABYSS_LOG_INFO << "Failed to initialize GLAD";
		return -1;
	}

	glfwSetWindowUserPointer(window_, &data_);

	// set glfw callbacks
	glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		WindowCloseEvent event;
		data.eventCallback_(event);
		});

	glfwSetKeyCallback(window_, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
				ABYSS_LOG_INFO << "key press:" << key;
				break;
			case GLFW_RELEASE:
				ABYSS_LOG_INFO << "key release:" << key;
				break;
			case GLFW_REPEAT:
				ABYSS_LOG_INFO << "key repeat:" << key;
				break;
			}
		});

	return 0;
}

void WindowWindow::Shutdown()
{

	glfwSetWindowShouldClose(window_, true);
}

}