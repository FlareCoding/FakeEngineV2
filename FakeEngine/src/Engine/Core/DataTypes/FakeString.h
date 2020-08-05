#pragma once

#include <cstring>

// TODO:
// - Replace
// - Find
// - 

// TEMP: move to FakeFileUtils
static char impl_to_upper_case(char letter)
	{
	switch (letter)
		{
		case 'a':
			return 'A';

		case 'b':
			return 'B';

		case 'c':
			return 'C';

		case 'd':
			return 'D';

		case 'e':
			return 'E';

		case 'f':
			return 'F';

		case 'g':
			return 'G';

		case 'h':
			return 'H';

		case 'i':
			return 'I';

		case 'j':
			return 'J';

		case 'k':
			return 'K';

		case 'l':
			return 'L';

		case 'm':
			return 'M';

		case 'n':
			return 'N';

		case 'o':
			return 'O';

		case 'p':
			return 'P';

		case 'q':
			return 'Q';

		case 'r':
			return 'R';

		case 's':
			return 'S';

		case 't':
			return 'T';

		case 'u':
			return 'U';

		case 'v':
			return 'V';

		case 'w':
			return 'W';

		case 'x':
			return 'X';

		case 'y':
			return 'Y';

		case 'z':
			return 'Z';
		}

	return letter;
	}

static char impl_to_lower_case(char letter)
	{
	switch (letter)
		{
		case 'A':
			return 'a';

		case 'B':
			return 'b';

		case 'C':
			return 'c';

		case 'D':
			return 'd';

		case 'E':
			return 'e';

		case 'F':
			return 'f';

		case 'G':
			return 'g';

		case 'H':
			return 'h';

		case 'I':
			return 'i';

		case 'J':
			return 'j';

		case 'K':
			return 'k';

		case 'L':
			return 'l';

		case 'M':
			return 'm';

		case 'N':
			return 'n';

		case 'O':
			return 'o';

		case 'P':
			return 'p';

		case 'Q':
			return 'q';

		case 'R':
			return 'r';

		case 'S':
			return 's';

		case 'T':
			return 't';

		case 'U':
			return 'u';

		case 'V':
			return 'v';

		case 'W':
			return 'w';

		case 'X':
			return 'x';

		case 'Y':
			return 'y';

		case 'Z':
			return 'z';
		}

	return letter;
	}

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
			delete[] Data;
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
			wchar_t *ret = new wchar_t[Size + 1];

			for (uint32_t i = 0; i < Size; ++i)
				ret[i] = Data[i];

			ret[Size + 1] = '\0';
			return ret;
			}

		const wchar_t *ToWStr() const
			{
			wchar_t *ret = new wchar_t[Size + 1];

			for (uint32_t i = 0; i < Size; ++i)
				ret[i] = Data[i];

			ret[Size + 1] = '\0';
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

		FakeString &Append(const char letter)
			{
			char *new_data = new char[(size_t)Size + 2]; // +1 for a character and another +1 for the null terminator
			new_data[Size] = letter;
			new_data[Size + 1] = '\0';
			if (Data) memcpy(new_data, Data, Size);

			if (Data) delete[] Data;
			Data = new_data;
			++Size;

			return *this;
			}

		FakeString &Append(const FakeString &other)
			{
			uint32_t new_size = Size + other.Size;
			char *new_data = new char[(size_t)new_size + 1]; // +1 for the null terminator

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

		FakeString *Split(size_t *outWordCount = 0)
			{
			// First get the word count to construct the size of the array
			// Then iterate through the string and put every word into the array

			uint32_t wordCount = 1;
			for (uint32_t i = 0; i < Size; ++i)
				{
				if (Data[i] == ' ')
					++wordCount;
				}

			FakeString *result = new FakeString[wordCount];

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

		bool Contains(const FakeString &other)
			{
			uint32_t i = 0;
			uint32_t j = 0;

			while (Data[i] != '\0')
				{
				if (Data[i] == other[j])
					{
					uint32_t init = i;
					while (Data[i] == other[j] && other[j] != '\0')
						{
						j++;
						i++;
						}

					if (other[j] == '\0')
						return true;
						
					j = 0;
					}
				i++;
				}

			return false;
			}

		uint32_t Find(const FakeString &other) const noexcept
			{
			// TODO

			return 0;
			}

		FakeString &Replace(const FakeString &find, const FakeString &replaceValue)
			{
			// TODO

			return *this;
			}

		FakeString &ToLowerCase()
			{
			for (uint32_t i = 0; i < Size; ++i)
				Data[i] = impl_to_lower_case(Data[i]);

			return *this;
			}

		const FakeString &ToLowerCase() const
			{
			for (uint32_t i = 0; i < Size; ++i)
				Data[i] = impl_to_lower_case(Data[i]);

			return *this;
			}

		FakeString &ToUpperCase()
			{
			for (uint32_t i = 0; i < Size; ++i)
				Data[i] = impl_to_upper_case(Data[i]);

			return *this;
			}

		const FakeString &ToUpperCase() const
			{
			for (uint32_t i = 0; i < Size; ++i)
				Data[i] = impl_to_upper_case(Data[i]);

			return *this;
			}

		FakeString& Reverse()
		{
			for (size_t i = 0; i < Size / 2; i++)
			{
				char temp = Data[i];
				Data[i] = Data[Size - i - 1];
				Data[Size - i - 1] = temp;
			}

			return *this;
		}

		void Print()
			{
			for (uint32_t i = 0; i < Size; i++)
				printf("%c", Data[i]);

			printf("\n");
			}

		operator char*()
			{
			char *result = new char[Size + 1];
			for (uint32_t i = 0; i < Size; ++i)
				result[i] = Data[i];

			result[Size + 1] = '\0';
			return result;
			}

		operator const char*() const
			{
			char *result = new char[Size + 1];
			for (uint32_t i = 0; i < Size; ++i)
				result[i] = Data[i];

			result[Size + 1] = '\0';
			return result;
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