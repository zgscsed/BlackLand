/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月27日20:25:17
 * @Description: 
 */

#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include "Abyss/Event/ApplicationEvent.hpp"

#include <string>

namespace Abyss {

	class Application {
	public:
		Application(const std::string &name = "Abyss App");
		~Application();

		void OnEvent(Event &e);
		// 应用程序执行
		void Exec();

		bool OnWindowClose(Event& e);

	private:
		bool isRunning_;
	};

}

#endif // !APPLICATION_HPP_
