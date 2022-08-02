#pragma once

#include "Events.h"

namespace Guristas
{
	class WindowEvent : public Event
	{
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowResizeEvent : public WindowEvent
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: _width(width), _height(height) {}

		unsigned int GetWidth() const { return _width; }
		unsigned int GetHeight() const { return _height; }

		EVENT_CLASS_TYPE(WindowResize)
	private:
		unsigned int _width, _height;
	};

	class WindowCloseEvent : public WindowEvent
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
	};

	class AppTickEvent : public WindowEvent
	{
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
	};

	class AppUpdateEvent : public WindowEvent
	{
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
	};

	class AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
	};
}
