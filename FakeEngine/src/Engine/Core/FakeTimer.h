#pragma once

#include "FakePch.h"

class FakeTimer
	{
	private:
		const char *Name;
		bool Stopped;
		std::chrono::time_point<std::chrono::steady_clock> StartPoint;

	public:
		FakeTimer(const char *name)
			: Name(name), Stopped(false)
			{
			StartPoint = std::chrono::high_resolution_clock::now();
			}

		~FakeTimer()
			{
			if (!Stopped)
				Stop();
			}

		void Stop()
			{
			auto endPoint = std::chrono::high_resolution_clock::now();

			long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(StartPoint).time_since_epoch().count();
			long long end   = std::chrono::time_point_cast<std::chrono::milliseconds>(endPoint).time_since_epoch().count();

			FAKE_LOG_TRACE("%s Time: %llms", Name, (end - start));
			Stopped = true;
			}

		static double GetTime()
			{
			auto now = std::chrono::system_clock::now().time_since_epoch();
			return (double)std::chrono::duration_cast<std::chrono::microseconds>(now).count();
			}

		static std::string GetTimeStamp()
			{
			std::time_t t = std::time(0);
			std::tm now;
			localtime_s(&now, &t);

			return std::to_string(now.tm_mday) + '.' + std::to_string(now.tm_mon + 1) + '.' + std::to_string(now.tm_year + 1900) + ' '
				+ std::to_string(now.tm_hour) + ':' + std::to_string(now.tm_min) + ':' + std::to_string(now.tm_sec);
			}
	};