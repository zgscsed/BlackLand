/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022��5��30��19:38:35
 * @Description: app�¼�
 */

#ifndef APPLICATION_EVENT_HPP_
#define APPLICATION_EVENT_HPP_

#include "Abyss/Event/Event.hpp"

namespace Abyss {

	// ���ڹر��¼�
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CALSS_CATEGORY(EventCategoryApplication)
		//static EventType GetStaticType() { return Abyss::EventType::WindowClose; }
		//virtual EventType GetEventType() const override { return GetStaticType(); }
		//virtual const char* GetName() const override { return #EventType::WindowClose; }
		//virtual int GetCategory() const override { return EventCategoryApplication; }
	};

}

#endif // !APPLICATION_EVENT_HPP_
