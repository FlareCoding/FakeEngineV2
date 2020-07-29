#pragma once

#include "FakeEvent.h"

class FakeWindowResizeEvent : public FakeEvent
	{
	private:
		unsigned int Width, Height;

	public:
		FakeWindowResizeEvent(unsigned int w, unsigned int h) : Width(w), Height(h) {}

		inline unsigned int GetWidth() const { return Width; }
		inline unsigned int GetHeight() const { return Height; }

		FakeString ToString() const override
			{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << Width << ", " << Height;
			return ss.str();
			}

		FAKE_EVENT_CLASS_TYPE(WindowResize)
		FAKE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

class FakeWindowCloseEvent : public FakeEvent
	{
	public:
		FakeWindowCloseEvent() {}
		FAKE_EVENT_CLASS_TYPE(WindowClose)
		FAKE_EVENT_CLASS_CATEGORY(EventCategoryApplication)

		FakeString ToString() const override
			{
			return "WindowCloseEvent";
			}
	};

class FakeAppTickEvent : public FakeEvent
	{
	public:
		FakeAppTickEvent() {}
		FAKE_EVENT_CLASS_TYPE(AppTick)
		FAKE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

class FakeAppRenderEvent : public FakeEvent
	{
	public:
		FakeAppRenderEvent() {}
		FAKE_EVENT_CLASS_TYPE(AppRender)
		FAKE_EVENT_CLASS_CATEGORY(EventCategoryApplication)

		FakeString ToString() const override
			{
			return "AppRenderEvent";
			}
	};

class FakeAppUpdateEvent : public FakeEvent
	{
	public:
		FakeAppUpdateEvent() {}
		FAKE_EVENT_CLASS_TYPE(AppUpdate)
		FAKE_EVENT_CLASS_CATEGORY(EventCategoryApplication)

		FakeString ToString() const override
			{
			return "AppUpdate";
			}
	};

class FakeFileMenuEvent : public FakeEvent
	{
	private:
		unsigned int ID;

	public:
		FakeFileMenuEvent(unsigned int id) : ID(id) {}
		inline unsigned int GetID() const { return ID; }

		FAKE_EVENT_CLASS_TYPE(FileMenu)
		FAKE_EVENT_CLASS_CATEGORY(EventCategoryApplication)

		FakeString ToString() const override
			{
			std::stringstream ss;
			ss << "FileMenuEvent: " << ID;
			return ss.str();
			}
	};