#pragma once

#include "FakeEvent.h"

class FakeMouseMovedEvent : public FakeEvent
	{
	private:
		double MouseX, MouseY;

	public:
		FakeMouseMovedEvent(double x, double y) : MouseX(x), MouseY(y) {}
		inline double GetMouseX() const { return MouseX; }
		inline double GetMouseY() const { return MouseY; }

		std::string ToString() const override
			{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << MouseX << ", " << MouseY;
			return ss.str();
			}

		FAKE_EVENT_CLASS_TYPE(MouseMoved)
		FAKE_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

class FakeMouseScrolledEvent : public FakeEvent
	{
	private:
		double MouseXOffset, MouseYOffset;

	public:
		FakeMouseScrolledEvent(double xOffset, double yOffset) : MouseXOffset(xOffset), MouseYOffset(yOffset) {}
		inline double GetMouseXOffset() const { return MouseXOffset; }
		inline double GetMouseYOffset() const { return MouseYOffset; }

		std::string ToString() const override
			{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << MouseXOffset << ", " << MouseYOffset;
			return ss.str();
			}

		FAKE_EVENT_CLASS_TYPE(MouseScrolled)
		FAKE_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

class FakeMouseButtonEvent : public FakeEvent
	{
	protected:
		int ButtonCode;

	public:
		FakeMouseButtonEvent(int button) : ButtonCode(button) {}
		inline int GetButton() const { return ButtonCode; }
		FAKE_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

class FakeMouseButtonPressedEvent : public FakeMouseButtonEvent
	{
	public:
		FakeMouseButtonPressedEvent(int button) : FakeMouseButtonEvent(button) {}
		FAKE_EVENT_CLASS_TYPE(MouseButtonPressed)

		std::string ToString() const override
			{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << ButtonCode;
			return ss.str();
			}
	};

class FakeMouseButtonReleasedEvent : public FakeMouseButtonEvent
	{
	public:
		FakeMouseButtonReleasedEvent(int button) : FakeMouseButtonEvent(button) {}
		FAKE_EVENT_CLASS_TYPE(MouseButtonReleased)

		std::string ToString() const override
			{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << ButtonCode;
			return ss.str();
			}
	};