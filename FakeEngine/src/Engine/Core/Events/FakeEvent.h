#pragma once

#include "FakePch.h"

enum class FakeEventType
	{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoves, FileMenu,
	AppTick, AppUpdate, AppRender,
	KeyPressed, KeyReleased, KeyTyped,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

enum FakeEventCategory
	{
	None = 0,
	EventCategoryApplication = BIT(0),
	EventCategoryInput       = BIT(1),
	EventCategoryKeyboard    = BIT(2),
	EventCategoryMouse       = BIT(3),
	EventCategoryMouseButton = BIT(4),
	};

#define FAKE_EVENT_CLASS_TYPE(type) static FakeEventType GetStaticType() { return FakeEventType::##type; }\
	virtual FakeEventType GetEventType() const override { return GetStaticType(); }\
	virtual const char *GetName() const override { return #type; }

#define FAKE_EVENT_CLASS_CATEGORY(type) virtual int GetCategoryFlags() const override { return type; }

class FakeEvent
	{
	friend class FakeEventDispatcher;

	public:
		bool Handled = false;

		virtual FakeEventType GetEventType() const = 0;
		virtual const char *GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual FakeString ToString() const
			{
			return GetName();
			}

		inline bool IsInCategory(FakeEventCategory c)
			{
			return GetCategoryFlags() & c;
			}
	};

class FakeEventDispatcher
	{
	template<typename T>
	using EventFn = std::function<bool(T&)>;

	private:
		FakeEvent &Event;

	public:
		FakeEventDispatcher(FakeEvent &e) : Event(e) {}

		template<typename T, typename F>
		bool Dispatch(const F &func)
			{
			if (Event.GetEventType() == T::GetStaticType())
				{
				Event.Handled = func(static_cast<T&>(Event));
				return true;
				}

			return false;
			}
	};

inline std::ostream &operator<<(std::ostream &stream, const FakeEvent &e)
	{
	return stream << e.ToString();
	}