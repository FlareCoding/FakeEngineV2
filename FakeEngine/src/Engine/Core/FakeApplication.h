#pragma once

#include "Engine/Core/FakeLayerStack.h"
#include "Engine/Core/FakeTimeStep.h"
#include "Engine/Core/Events/FakeApplicationEvents.h"

class FakeApplication
	{
	private:
		static FakeApplication *Self;

		double FrameTime = 0.0;
		double InitialTime = -1.0;
		double ElapsedTime = 0.0;
		uint32_t FrameCounter = 0;
		bool Running = true;
		bool Minimized = false;

		FakeLayerStack LayerStack;

		bool OnWindowClose(FakeWindowCloseEvent &e);
		bool OnWindowResize(FakeWindowResizeEvent &e);

	public:
		FakeApplication();
		virtual ~FakeApplication();

		virtual void OnInit() {}
		virtual void OnShutdown() {}

		void PushLayer(FakeLayer *layer);
		void PopLayer(FakeLayer *layer);
		void PushOverlay(FakeLayer *overlay);
		void PopOverlay(FakeLayer *overlay);

		void OnEvent(FakeEvent &e);
		void Run();
		void CloseApplication();

		inline static FakeApplication &Get() { return *Self; }
	};

FakeApplication *CreateApp();