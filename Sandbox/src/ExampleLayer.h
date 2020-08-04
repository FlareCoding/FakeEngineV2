#pragma once

#include <Fake.h>

class ExampleLayer : public FakeLayer
	{
	public:
		virtual void OnAttach() override
			{
		//	FAKE_LOG_INFO("Application starts!");

			FakeString string = "Hello World!";
			FakeString result = string.Split();
		//	std::cout << result << std::endl;

			/*
			char *arr = string.SplitChar();
			for (uint32_t i = 0; i < string.Length(); ++i)
				std::cout << arr[i] << std::endl;
			*/
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
