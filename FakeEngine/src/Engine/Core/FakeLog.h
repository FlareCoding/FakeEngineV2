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

		template<typename T>
		static FakeString Replace(const FakeString &format, const FakeString &pattern, const T &repaceValue);

	public:
		inline static void SetLogLevel(FakeLogLevel level) { Severity = level; }
		static void Print(const char *format, ...);
	};

#ifdef FAKE_DEBUG
	#define FAKE_ASSERT_INSTANT(x) { if (!(x)) { __debugbreak(); } }
	#define FAKE_ASSERT(x, msg) { if (!(x)) { FakeLog::SetLogLevel(FakeLogLevel::FatalLevel); FakeLog::Print("Assertion failed: %s", msg); __debugbreak(); } }
#elif FAKE_RELEASE
	#define FAKE_ASSERT_INSTANT(x)
	#define FAKE_ASSERT(x, msg) { if (!(x)) { FakeLog::SetLogLevel(FakeLogLevel::ErrorLevel); FakeLog::Print("Assertion failed: %s", msg); } }
#endif

#define FAKE_LOG(format, ...) FakeLog::SetLogLevel(FakeLogLevel::None); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_TRACE(format, ...) FakeLog::SetLogLevel(FakeLogLevel::TraceLevel); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_INFO(format, ...) FakeLog::SetLogLevel(FakeLogLevel::InfoLevel); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_ERROR(format, ...) FakeLog::SetLogLevel(FakeLogLevel::ErrorLevel); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_FATAL(format, ...) FakeLog::SetLogLevel(FakeLogLevel::FatalLevel); FakeLog::Print(format, __VA_ARGS__);
#define FAKE_LOG_WARN(format, ...) FakeLog::SetLogLevel(FakeLogLevel::WarningLevel); FakeLog::Print(format, __VA_ARGS__);
