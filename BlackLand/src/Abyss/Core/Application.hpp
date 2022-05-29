/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月27日20:25:17
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

		// 应用程序执行
		void Exec();

	private:
		bool isRunning_;
	};

}

#endif // !APPLICATION_HPP_
