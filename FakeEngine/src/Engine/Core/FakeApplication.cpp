#include "FakePch.h"
#include "FakeApplication.h"

#include "Engine/Core/FakeTimer.h"

FakeApplication *FakeApplication::Self = nullptr;
#define BIND_EVENT_FN(x) std::bind(&FakeApplication::x, this, std::placeholders::_1)

FakeApplication::FakeApplication()
	{
	FAKE_ASSERT(!Self, "Application already exists!");
	Self = this;

	// Fenster erstellen


	// Renderer erstellen

	}

FakeApplication::~FakeApplication()
	{

	}

void FakeApplication::Run()
	{
	
	OnInit();

	double t = 0.0;
	while (Running)
		{
		if (-1.0 == InitialTime)
			{
			InitialTime = FakeTimer::GetTime();
			}

		double currentTime = FakeTimer::GetTime();
		ElapsedTime = (currentTime - InitialTime) / 1000000.0;
		FakeTimeStep ts = (ElapsedTime - FrameTime) * 1000.0;
		FrameTime = ElapsedTime;

		if (!Minimized)
			{
			for (FakeLayer *layer : LayerStack)
				{
				layer->OnRender(ts);
				}
			}

		++FrameCounter;

		if (ElapsedTime - t > 1.0)
			{
			FAKE_LOG_TRACE("FPS: %d", FrameCounter);

			FrameCounter = 0;
			t += 1.0;
			}
		}

	OnShutdown();

	}

void FakeApplication::CloseApplication()
	{
	Running = false;
	}

void FakeApplication::PushLayer(FakeLayer *layer)
	{
	LayerStack.PushLayer(layer);
	layer->OnAttach();
	}

void FakeApplication::PopLayer(FakeLayer *layer)
	{
	LayerStack.PopLayer(layer);
	layer->OnDetach();
	}

void FakeApplication::PushOverlay(FakeLayer *overlay)
	{
	LayerStack.PushOverlay(overlay);
	overlay->OnAttach();
	}

void FakeApplication::PopOverlay(FakeLayer *overlay)
	{
	LayerStack.PopOverlay(overlay);
	overlay->OnDetach();
	}

void FakeApplication::OnEvent(FakeEvent &e)
	{
	FakeEventDispatcher dispatcher(e);
	dispatcher.Dispatch<FakeWindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	dispatcher.Dispatch<FakeWindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));

	for (auto it = LayerStack.end(); it != LayerStack.begin();)
		{
		(*--it)->OnEvent(e);
		if (e.Handled)
			{
			break;
			}
		}
	}

bool FakeApplication::OnWindowClose(FakeWindowCloseEvent &e)
	{
	Running = false;
	return true;
	}

bool FakeApplication::OnWindowResize(FakeWindowResizeEvent &e)
	{
	if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
		Minimized = true;
		return false;
		}

	Minimized = false;
	// TODO: Resize Rendering Viewport
	return true;
	}
