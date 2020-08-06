#pragma once

#include <Fake.h>

class ExampleLayer : public FakeLayer
	{
	public:
		virtual void OnAttach() override
			{
			FAKE_LOG_INFO("Application starts!");

			FakeString str1 = "Hello World!";
			FakeString str2 = "Hello World!";
			
			std::cout << "str1.Hash(): " << str1.Hash() << "\n";
			std::cout << "str2.Hash(): " << str2.Hash() << "\n";
			std::cout << "Are strings equal: " << (str1.Hash() == str2.Hash()) << "\n\n";

			FakeString str3 = "Good morning";
			FakeString str4 = "Good Morning";

			std::cout << "str3.Hash(): " << str3.Hash() << "\n";
			std::cout << "str4.Hash(): " << str4.Hash() << "\n";
			std::cout << "Are strings equal: " << (str3.Hash() == str4.Hash()) << "\n\n";
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
