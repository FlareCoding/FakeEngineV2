#include "FakePch.h"
#include "FakeLog.h"

#include "Engine/Core/Defines/FakeConsole.h"
#include "Engine/Core/FakeTimer.h"

#include "Engine/Core/Maths/FakeVector2.h"
#include "Engine/Core/Maths/FakeVector3.h"
#include "Engine/Core/Maths/FakeVector4.h"

FakeLogLevel FakeLog::Severity = FakeLogLevel::None;

bool FakeLog::Contains(const std::string &format, const std::string &pattern)
	{
	if (format.find(pattern) != std::string::npos)
		return true;
	else
		return false;
	}

template<typename T>
std::string FakeLog::Replace(const std::string &format, const std::string &pattern, const T &replaceValue)
	{
	std::string out = format;
	std::stringstream ss;
	ss << replaceValue;
	
	return out.replace(out.find(pattern), pattern.length(), ss.str());
	}

void FakeLog::Print(const char *format, ...)
	{
	va_list args;
	std::string out = format;
	va_start(args, format);

	printf(FAKE_CONSOLE_FONT_BRIGHT);
	switch (Severity)
		{
		case FakeLogLevel::FatalLevel:
		case FakeLogLevel::ErrorLevel:
			printf(FAKE_CONSOLE_COLOR_RED);
			break;

		case FakeLogLevel::InfoLevel:
			printf(FAKE_CONSOLE_COLOR_BLUE);
			break;

		case FakeLogLevel::WarningLevel:
			printf(FAKE_CONSOLE_COLOR_YELLOW);
			break;

		case FakeLogLevel::TraceLevel:
			printf(FAKE_CONSOLE_COLOR_GREEN);
			break;

		case FakeLogLevel::None:
		default:
			printf(FAKE_CONSOLE_COLOR_WHITE);
			break;
		}

	if (Contains(out, "%s"))
		{
		while (Contains(out, "%s"))
			{
			char *s = va_arg(args, char*);
			out = Replace<char*>(out, "%s", s);
			}
		}

	if (Contains(out, "%ll"))
		{
		while (Contains(out, "%ll"))
			{
			long long l = va_arg(args, long long);
			out = Replace<long long>(out, "%ll", l);
			}
		}

	if (Contains(out, "%l"))
		{
		while (Contains(out, "%l"))
			{
			long l = va_arg(args, long);
			out = Replace<long>(out, "%l", l);
			}
		}

	if (Contains(out, "%ud"))
		{
		while (Contains(out, "%ud"))
			{
			unsigned int d = va_arg(args, unsigned int);
			out = Replace<unsigned int>(out, "%ud", d);
			}
		}

	if (Contains(out, "%d"))
		{
		while (Contains(out, "%d"))
			{
			int d = va_arg(args, int);
			out = Replace<int>(out, "%d", d);
			}
		}

	if (Contains(out, "%f"))
		{
		while (Contains(out, "%f"))
			{
			double f = va_arg(args, double);
			out = Replace<double>(out, "%f", f);
			}
		}

	if (Contains(out, "%v2f"))
		{
		while (Contains(out, "%v2f"))
			{
			FakeVec2f vector = va_arg(args, FakeVec2f);
			out = Replace<FakeVec2f>(out, "%v2f", vector);
			}
		}

	if (Contains(out, "%v3f"))
		{
		while (Contains(out, "%v3f"))
			{
			FakeVec3f vector = va_arg(args, FakeVec3f);
			out = Replace<FakeVec3f>(out, "%v3f", vector);
			}
		}

	/*
	if (Contains(out, "%v4f"))
		{
		while (Contains(out, "%v4f"))
			{
			FakeVec4f vector = va_arg(args, FakeVec4f);
			out = Replace<FakeVec4f>(out, "%v4f", vector);
			}
		}
	*/

	va_end(args);
	std::cout << "[" << FakeTimer::GetTimeStamp() << "] " << out << std::endl;
	printf(FAKE_CONSOLE_COLOR_WHITE);
	}
