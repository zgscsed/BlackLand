/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��5��29��20:25:17
 * @Description: һЩ�����Ĺ���
 */

#ifndef BASE_HPP_
#define BASE_HPP_

#include <memory>


#ifdef _WIN32
 //define something for Windows (32-bit and 64-bit, this part is common)
	#define AS_PLATFORM_WINDOWS            // windowƽ̨
	#ifdef _WIN64
   //define something for Windows (64-bit only)
		#define AS_PLATFORM_WINDOWS 
	#else
	   //define something for Windows (32-bit only)
	#endif
#elif __linux__
 // linux
#elif __unix__ // all unices not caught above
 // Unix
#elif defined(_POSIX_VERSION)
 // POSIX
#else
#error "Unknown"
#endif

#ifdef AS_PLATFORM_WINDOWS
	#ifdef AS_BUILD_DLL
		#define AS_API __declspec(dllexport)
	#else
		#define AS_API __declspec(dllimport)
	#endif
#else
	#error Only supports Windows!
#endif


namespace Abyss {

#define BIT(x) (1 << x)
#define AS_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) {return this->fn(std::forward<decltype(args)>(args)...); }
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	// �������
	using uint = unsigned int;
}

#include "Abyss/Core/Log.hpp"
#endif // !BASE_HPP_
