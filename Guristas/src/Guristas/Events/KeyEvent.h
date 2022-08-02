#pragma once

#include "Events.h"

namespace Guristas
{
	class KeyEvent : public Event
	{
	public:
		inline const int& GetKeyCode() const { return _keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int& keycode)
			: _keyCode(keycode) {}

		int _keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, bool isRepeat)
			: KeyEvent(keycode), _isRepeat(isRepeat) {}

		KeyPressedEvent(int& keycode, bool isRepeat)
			: KeyEvent(keycode), _isRepeat(isRepeat) {}

		KeyPressedEvent(int& keycode, bool& isRepeat)
			: KeyEvent(keycode), _isRepeat(isRepeat) {}

		KeyPressedEvent(int keycode, bool& isRepeat)
			: KeyEvent(keycode), _isRepeat(isRepeat) {}

		bool IsRepeat() const { return _isRepeat; }

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		bool _isRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		KeyReleasedEvent(int& keycode)
			: KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyReleased)

	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}

		KeyTypedEvent(int& keycode)
			: KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyTyped)

	};
}