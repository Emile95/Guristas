#pragma once

#include "Events.h"

namespace Guristas
{
	class MouseEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MouseMovedEvent : public MouseEvent
	{
	public:
		MouseMovedEvent(float& x, float& y) 
			: _x(x), _y(y) {}

		const float& GetX() const { return _x; }
		const float& GetY() const { return _y; }

		EVENT_CLASS_TYPE(MouseMoved)

	private:
		float _x;
		float _y;
	};

	class MouseScrolledEvent : public MouseEvent
	{
	public:
		MouseScrolledEvent(float& xOffset, float& yOffset)
			: _xOffset(xOffset), _yOffset(yOffset) {}

		const float& GetXOffset() const { return _xOffset; }
		const float& GetYOffset() const { return _yOffset; }

		EVENT_CLASS_TYPE(MouseScrolled)

	private:
		float _xOffset;
		float _yOffset;
	};

	class MouseButtonEvent : public MouseEvent
	{
	public:
		const int& GetButtonCode() const { return _buttonCode; }

		EVENT_CLASS_TYPE(MouseButtonPressed)

	protected:
		MouseButtonEvent(int& buttonCode)
			: _buttonCode(buttonCode) {}

		int _buttonCode;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int& buttonCode)
			: MouseButtonEvent(buttonCode) {}
	};

	class MouseButtonReleasedEvent : public MouseEvent
	{
	public:
		MouseButtonReleasedEvent(int& buttonCode) { }

		EVENT_CLASS_TYPE(MouseReleased)
	};
}
