#pragma once

#include <cstring>

// TODO
// - Substr
// - 

class FakeString
	{
	private:
		char *Data = 0;
		uint32_t Size = 0;

	public:
		FakeString() = default;
		FakeString(const char *str)
			{
			Size = (uint32_t)strlen(str);
			Data = new char[(size_t)Size + 1];
			Data[Size] = '\0';
			memcpy(Data, str, Size);
			}

		FakeString(const FakeString &other)
			{
			Size = other.Size;
			Data = new char[(size_t)Size + 1];
			Data[Size] = '\0';
			memcpy(Data, other.Data, Size);
			}

		FakeString(const std::string &str)
			{
			Size = (uint32_t)strlen(str.c_str());
			Data = new char[(size_t)Size + 1];
			Data[Size] = '\0';
			memcpy(Data, str.c_str(), Size);
			}

		FakeString(const FakeString &other, uint32_t start, uint32_t end)
			{
			Size = end - start;
			Data = new char[(size_t)Size + 1];
			Data[Size] = '\0';
			memcpy(Data, &other.Data[start], Size);
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
				if (Data) delete[] Data;

				Size = other.Size;
				Data = new char[(size_t)Size + 1];
				Data[Size] = '\0';

				memcpy(Data, other.Data, Size);
				}

			return *this;
			}

		FakeString &operator=(FakeString &&other) noexcept
			{
			if (this != &other)
				{
				if (Data) delete[] Data;

				Size = other.Size;
				Data = new char[(size_t)Size + 1];
				Data[Size] = '\0';

				memcpy(Data, other.Data, Size);
				}

			return *this;
			}

		wchar_t *ToWStr()
			{
			wchar_t *ret = L"";

			for (uint32_t i = 0; i < Size; ++i)
				ret += Data[i];

			return ret;
			}

		const wchar_t *ToWStr() const
			{
			wchar_t *ret = L"";

			for (uint32_t i = 0; i < Size; ++i)
				ret += Data[i];

			return ret;
			}

		char *ToStr()
			{
			return Data;
			}

		const char *ToStr() const
			{
			return Data;
			}

		uint32_t Length() const noexcept
			{
			return Size;
			}

		char At(uint32_t i)
			{
			return Data[i];
			}

		FakeString& Append(const char letter)
		{
			char* new_data = new char[(size_t)Size + 2]; // +1 for a character and another +1 for the null terminator
			new_data[Size] = letter;
			new_data[Size + 1] = '\0';
			if (Data) memcpy(new_data, Data, Size);

			if (Data) delete[] Data;
			Data = new_data;
			++Size;

			return *this;
		}

		FakeString& Append(const FakeString &other)
		{
			uint32_t new_size = Size + other.Size;
			char* new_data = new char[(size_t)new_size + 1]; // +1 for the null terminator

			new_data[new_size] = '\0';
			if (Data) memcpy(new_data, Data, Size);						// copy existing string data
			memcpy((char*)(new_data + Size), other.Data, other.Size);	// copy appended string data

			if (Data) delete[] Data;
			Data = new_data;
			Size = new_size;

			return *this;
		}

		uint32_t FirstIndexOf(const char letter)
			{
			for (uint32_t i = 0; i < Size; ++i)
				{
				if (Data[i] == letter)
					return i;
				}

			return NULL;
			}

		uint32_t IndexOf(const char letter, uint32_t offset = 0)
			{
			if (0 == offset)
				return FirstIndexOf(letter);

			for (uint32_t i = 0; i < Size; ++i)
				{
				if (Data[i] == letter && offset > 0)
					{
					--offset;
					continue;
					}

				if (Data[i] == letter)
					return i;
				}

			return NULL;
			}

		uint32_t LastIndexOf(const char letter)
			{
			// Count how many times the letter exists
			uint32_t letterCount = 0;
			for (uint32_t i = 0; i < Size; ++i)
				{
				if (Data[i] == letter)
					letterCount++;
				}

			// If No Letter exists, return
			if (0 == letterCount)
				return NULL;

			// Get the last letter index
			for (uint32_t i = 0; i < Size; ++i)
				{
				if (Data[i] == letter && letterCount > 0)
					{
					--letterCount;
					continue;
					}

				if (Data[i] == letter)
					{
					return i;
					}
				}

			return NULL;
			}

		FakeString *Split(size_t* outWordCount = 0)
			{
			// First get the word count to construct the size of the array
			// Then iterate through the string and put every word into the array

			uint32_t wordCount = 1;
			for (uint32_t i = 0; i < Size; ++i)
			{
				if (Data[i] == ' ')
					++wordCount;
			}

			FakeString* result = new FakeString[wordCount];

			uint32_t charIdx = 0;
			for (uint32_t i = 0; i < wordCount; i++)
			{
				uint32_t wordBeginIdx = charIdx;
				while (Data[charIdx] != ' ' && Data[charIdx] != '\0')
				{
					charIdx++;
				}

				FakeString word = Substr(wordBeginIdx, charIdx);
				result[i] = word;

				charIdx++;
			}

			if (outWordCount)
				*outWordCount = wordCount;

			return result;
			}

		char *SplitChar()
			{
			char *result = new char[Size];
			for (uint32_t i = 0; i < Size; ++i)
				result[i] = Data[i];

			return result;
			}

		FakeString Substr(uint32_t beginIndex, uint32_t endIndex = 0)
			{
			if ((endIndex - beginIndex) > Size)
				return FakeString("-1");

			if (endIndex == 0)
				endIndex = Size;

			return FakeString(*this, beginIndex, endIndex);
			}

		uint32_t Find(const FakeString &other) const noexcept
			{
			

			return 0;
			}

		FakeString &Replace(const FakeString &find, const FakeString &replaceValue)
			{
			// TODO
			return *this;
			}

		void Print()
			{
			for (uint32_t i = 0; i < Size; i++)
				printf("%c", Data[i]);

			printf("\n");
			}

		friend FakeString operator+(FakeString str, const FakeString &other)
			{
			return str.Append(other);
			}

		friend FakeString operator+(FakeString str, const char letter)
			{
			return str.Append(letter);
			}

		FakeString &operator+=(const FakeString &other)
			{
			return Append(other);
			}

		FakeString &operator+=(const char letter)
			{
			return Append(letter);
			}

		char &operator[](uint32_t i)
			{
			return Data[i];
			}

		const char &operator[](uint32_t i) const
			{
			return Data[i];
			}

		friend std::ostream &operator<<(std::ostream &stream, const FakeString &string)
			{
			for (uint32_t i = 0; i < string.Size; ++i)
				stream << string[i];

			return stream;
			}
	};