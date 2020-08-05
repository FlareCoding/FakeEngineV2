#pragma once

#include <Fake.h>

class ExampleLayer : public FakeLayer
	{
	public:
		virtual void OnAttach() override
			{
		//	FAKE_LOG_INFO("Application starts!");

			FakeString ex1 = "Hello World!";
			std::cout << "Before: " << ex1 << std::endl;
			ex1.Replace("Hello", "Nice");
			std::cout << "After: " << ex1 << std::endl << std::endl;

			FakeString ex2 = "yes I will do this yes sir";
			std::cout << "Before: " << ex2 << std::endl;
			ex2.Replace("yes", "NO");
			ex2.Replace("will do", "will not do");
			std::cout << "After: " << ex2 << std::endl;
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
