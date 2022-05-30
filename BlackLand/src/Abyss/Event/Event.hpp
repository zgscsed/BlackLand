/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月29日20:25:17
 * @Description: 事件类的基类
 */

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "Abyss/Core/Base.hpp"

namespace Abyss {

	// 目前这些事件是实时处理的事件
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize
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

	// 一些通用的方法
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::type;}\
								virtual EventType GetEventType() const override {return GetStaticType();}\
								virtual const char* Getname() const override {return #type;}
#define EVENT_CALSS_CATEGORY(category) virtual int GetCategory() const override {return category;}

	class Event
	{
	public:
		virtual ~Event() = default;
		bool handled_ = false;
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

	// 事件分发
	class EventDispatcher {
	public:
		EventDispatcher(Event& event)
			: event_(event)
		{

		}

		// 根据静态方法判断类型是否相同，然后执行传入的回调函数，执行事件响应
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (event_.GetEventType() == T::GetStaticType())
			{
				event_.handled_ |= func(static_cast<T&>(event_));
				return true;
			}
			return false;
		}

	private:
		Event& event_;
	};
}
#endif // !EVENT_HPP_
