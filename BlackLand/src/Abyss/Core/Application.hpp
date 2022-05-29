/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��5��27��20:25:17
 * @Description: 
 */

#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <string>

namespace Abyss {

	class Application {
	public:
		Application(const std::string &name = "Abyss App");
		~Application();

		// Ӧ�ó���ִ��
		void Exec();

	private:
		bool isRunning_;
	};

}

#endif // !APPLICATION_HPP_
