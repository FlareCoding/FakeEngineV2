#pragma once

enum class FakeLogLevel
	{
	None = 0,
	InfoLevel, TraceLevel, ErrorLevel, FatalLevel, WarningLevel
	};

class FakeLog
	{
	private:
		static FakeLogLevel Severity;

		static bool Contains(const std::string &format, const std::string &pattern);

		template<typename T>
		static std::string Replace(const std::string &format, const std::string &pattern, const T &repaceValue);

	public:
		inline static void SetLogLevel(FakeLogLevel level) { Severity = level; }
		static void Print(const char *format, ...);
	};

#define FAKE_ASSERT_INSTANT(x) { if (!(x)) { __debugbreak(); } }
#define FAKE_ASSERT(x, msg) { if (!(x)) { FakeLog::SetLogLevel(FakeLogLevel::FatalLevel); FakeLog::Print("Assertion failed: %s", msg); __debugbreak(); } }

#define FAKE_LOG(format, ...) FakeLog::SetLogLevel(FakeLogLevel::None); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_TRACE(format, ...) FakeLog::SetLogLevel(FakeLogLevel::TraceLevel); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_INFO(format, ...) FakeLog::SetLogLevel(FakeLogLevel::InfoLevel); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_ERROR(format, ...) FakeLog::SetLogLevel(FakeLogLevel::ErrorLevel); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_FATAL(format, ...) FakeLog::SetLogLevel(FakeLogLevel::FatalLevel); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_WARN(format, ...) FakeLog::SetLogLevel(FakeLogLevel::WarningLevel); FakeLog::Print(format, __VA_ARGS__);