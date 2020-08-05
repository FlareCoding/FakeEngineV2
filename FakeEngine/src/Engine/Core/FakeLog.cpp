#include "FakePch.h"
#include "FakeLog.h"

#include "Engine/Core/Defines/FakeConsole.h"
#include "Engine/Core/FakeTimer.h"

#include "Engine/Core/Maths/FakeVector2.h"
#include "Engine/Core/Maths/FakeVector3.h"
#include "Engine/Core/Maths/FakeVector4.h"

#include "Engine/Core/Maths/FakeMatrix2.h"
#include "Engine/Core/Maths/FakeMatrix3.h"
#include "Engine/Core/Maths/FakeMatrix4.h"

FakeLogLevel FakeLog::Severity = FakeLogLevel::None;

template<typename T>
FakeString FakeLog::Replace(const FakeString &format, const FakeString &pattern, const T &replaceValue)
	{
	FakeString out = format;
	std::stringstream ss;
	ss << replaceValue;
	
	return out.Replace(pattern, ss.str());
	}

void FakeLog::Print(const char *format, ...)
	{
	va_list args;
	FakeString out = format;
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

	if (out.Contains("%s"))
		{
		while (out.Contains("%s"))
			{
			char *s = va_arg(args, char*);
			out = Replace<char*>(out, "%s", s);
			}
		}

	if (out.Contains("%ll"))
		{
		while (out.Contains("%ll"))
			{
			long long l = va_arg(args, long long);
			out = Replace<long long>(out, "%ll", l);
			}
		}

	if (out.Contains("%l"))
		{
		while (out.Contains("%l"))
			{
			long l = va_arg(args, long);
			out = Replace<long>(out, "%l", l);
			}
		}

	if (out.Contains("%ud"))
		{
		while (out.Contains("%ud"))
			{
			unsigned int d = va_arg(args, unsigned int);
			out = Replace<unsigned int>(out, "%ud", d);
			}
		}

	if (out.Contains("%d"))
		{
		while (out.Contains("%d"))
			{
			int d = va_arg(args, int);
			out = Replace<int>(out, "%d", d);
			}
		}

	if (out.Contains("%f"))
		{
		while (out.Contains("%f"))
			{
			double f = va_arg(args, double);
			out = Replace<double>(out, "%f", f);
			}
		}

	if (out.Contains("%v2f"))
		{
		while (out.Contains("%v2f"))
			{
			FakeVec2f vector = va_arg(args, FakeVec2f);
			out = Replace<FakeVec2f>(out, "%v2f", vector);
			}
		}

	if (out.Contains("%v3f"))
		{
		while (out.Contains("%v3f"))
			{
			FakeVec3f vector = va_arg(args, FakeVec3f);
			out = Replace<FakeVec3f>(out, "%v3f", vector);
			}
		}

	if (out.Contains("%v4f"))
		{
		while (out.Contains("%v4f"))
			{
			FakeVec4f vector = va_arg(args, FakeVec4f);
			out = Replace<FakeVec4f>(out, "%v4f", vector);
			}
		}

	if (out.Contains("%m2f"))
		{
		while (out.Contains("%m2f"))
			{
			FakeMat2f mat = va_arg(args, FakeMat2f);
			out = Replace<FakeMat2f>(out, "%m2f", mat);
			}
		}

	if (out.Contains("%m3f"))
		{
		while (out.Contains("%m3f"))
			{
			FakeMat3f mat = va_arg(args, FakeMat3f);
			out = Replace<FakeMat3f>(out, "%m3f", mat);
			}
		}

	/*
	if (Contains(out, "%m4f"))
		{
		while (Contains(out, "%m4f"))
			{
			FakeMat4f mat = va_arg(args, FakeMat4f);
			out = Replace<FakeMat4f>(out, "%m4f", mat);
			}
		}
	*/

	va_end(args);
	std::cout << "[" << FakeTimer::GetTimeStamp() << "] " << out << std::endl;
	printf(FAKE_CONSOLE_COLOR_WHITE);
	}
