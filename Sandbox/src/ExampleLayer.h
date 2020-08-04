#pragma once

#include <Fake.h>

class ExampleLayer : public FakeLayer
	{
	public:
		virtual void OnAttach() override
			{
			FAKE_LOG_INFO("Application starts!");

			size_t wordCount = 0;
			FakeString helloWorld = "Hello World!";
			FakeString* result = helloWorld.Split(&wordCount);
			std::cout << "Word Count: " << wordCount << "\n";

			for (size_t i = 0; i < wordCount; i++)
				std::cout << result[i] << "\n";

			}

		virtual void OnDetach() override
			{
			FAKE_LOG_INFO("Application ends!");
			}

		virtual void OnRender(FakeTimeStep ts) override
			{
		//	FAKE_LOG_INFO("Application is currently running!");
			}

		virtual void OnEvent(FakeEvent &e) override
			{
			FAKE_LOG_INFO("some event occurred!");
			}
	};
