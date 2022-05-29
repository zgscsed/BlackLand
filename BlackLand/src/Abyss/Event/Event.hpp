/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月29日20:25:17
 * @Description: 事件类的基类
 */

#ifndef EVENT_HPP_
#define EVENT_HPP_

namespace Abyss {

	// 目前这些事件是实时处理的事件
	enum class EventType
	{
		None = 0,
		WindowClose
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	class Event
	{
	public:
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* Getname() const = 0;
		virtual int GetCategory() const = 0;
		virtual std::string ToString() const { return Getname(); }

		// 事件归属类型
		bool IsInCategory(EventCategory category)
		{
			return GetCategory() & category;
		}
	};
}
#endif // !EVENT_HPP_
