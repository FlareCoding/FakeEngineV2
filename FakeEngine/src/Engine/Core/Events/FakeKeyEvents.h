#pragma once

#include "FakeEvent.h"

class FakeKeyEvent : public FakeEvent
	{
	protected:
		int KeyCode;

	public:
		FakeKeyEvent(int keyCode) : KeyCode(keyCode) {}
		inline int GetKeyCode() const { return KeyCode; }

		FAKE_EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};

class FakeKeyPressedEvent : public FakeKeyEvent
	{
	private:
		int RepeatCount;

	public:
		FakeKeyPressedEvent(int keyCode, int repeatCount) : FakeKeyEvent(keyCode), RepeatCount(repeatCount) {}
		inline int GetRepeatCount() const { return RepeatCount; }

		FakeString ToString() const override
			{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << KeyCode << " (" << RepeatCount << " repeats)";
			return ss.str();
			}

		FAKE_EVENT_CLASS_TYPE(KeyPressed)
	};

class FakeKeyReleasedEvent : public FakeKeyEvent
	{
	public:
		FakeKeyReleasedEvent(int keyCode) : FakeKeyEvent(keyCode) {}

		FakeString ToString() const override
			{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << KeyCode;
			return ss.str();
			}

		FAKE_EVENT_CLASS_TYPE(KeyReleased)
	};

class FakeKeyTypedEvent : public FakeKeyEvent
	{
	public:
		FakeKeyTypedEvent(int keyCode) : FakeKeyEvent(keyCode) {}

		FakeString ToString() const override
			{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << KeyCode;
			return ss.str();
			}

		FAKE_EVENT_CLASS_TYPE(KeyTyped)
	};