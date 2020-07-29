#pragma once

#include "FakePch.h"

class FakeString
	{
	private:
		char *Data;
		uint32_t Size;

	public:
		FakeString() = default;
		FakeString(const char *str)
			{
			Size = (uint32_t)strlen(str);
			Data = new char[Size];
			memcpy(Data, str, Size);
			}

		FakeString(const FakeString &other)
			{
			Size = other.Size;
			Data = new char[Size];
			memcpy(Data, other.Data, Size);
			}

		FakeString(const std::string &str)
			{
			Size = (uint32_t)strlen(str.c_str());
			Data = new char[Size];
			memcpy(Data, str.c_str(), Size);
			}

		FakeString(FakeString &&other) noexcept
			{
			Size = other.Size;
			Data = other.Data;

			other.Size = 0;
			other.Data = nullptr;
			}

		~FakeString()
			{
			delete Data;
			}

		FakeString &operator=(const FakeString &other)
			{
			if (this != &other)
				{
				delete[] Data;

				Size = other.Size;
				Data = new char[Size];

				memcpy(Data, other.Data, Size);
				}

			return *this;
			}

		FakeString &operator=(FakeString &&other) noexcept
			{
			if (this != &other)
				{
				delete[] Data;

				Size = other.Size;
				Data = new char[Size];

				memcpy(Data, other.Data, Size);
				}

			return *this;
			}

		const wchar_t *ConvertToWString()
			{
			std::string tmp = "";

			for (uint32_t i = 0; i < Size; i++)
				tmp += Data[i];

			std::wstring ws(Size, L' ');
			ws.resize(std::mbstowcs(&ws[0], tmp.c_str(), Size));
			return ws.c_str();
			}

		void Print()
			{
			for (uint32_t i = 0; i < Size; i++)
				printf("%c", Data[i]);

			printf("\n");
			}

		friend std::ostream &operator<<(std::ostream &stream, const FakeString &string)
			{
			for (uint32_t i = 0; i < string.Size; ++i)
				stream << string.Data[i];

			return stream;
			}
	};