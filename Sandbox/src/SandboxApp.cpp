#include <Fake.h>

#include "ExampleLayer.h"

class SandboxApp : public FakeApplication
	{
	virtual void OnInit() override
		{
		PushLayer(new ExampleLayer());
		}

	virtual void OnShutdown() override
		{

		}
	};

FakeApplication *CreateApp()
	{
	return new SandboxApp();
	}