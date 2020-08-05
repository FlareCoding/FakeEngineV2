#pragma once

#include <Fake.h>

class ExampleLayer : public FakeLayer
	{
	public:
		virtual void OnAttach() override
			{
			FAKE_LOG_INFO("Application starts!");

			FakeString str = "Tes";
			std::cout << "Old: " << str << "\n";
			str += 't';
			std::cout << "New: " << str << "\n\n";

			FakeString str2 = "Hello";
			std::cout << "Old: " << str2 << "\n";
			str2 += " World!";
			std::cout << "New: " << str2 << "\n";

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
