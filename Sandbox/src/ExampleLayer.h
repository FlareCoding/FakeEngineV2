#pragma once

#include <Fake.h>

class ExampleLayer : public FakeLayer
	{
	public:
		virtual void OnAttach() override
			{
			FAKE_LOG_INFO("Application starts!");

			FakeVec2i vec = { 1, 1 };
			FakeVec2i vec2 = { 2, 2 };

			if (vec < vec2)
				{
				std::cout << "vectors are equal!" << std::endl;
				}

			std::cout << vec << std::endl;
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