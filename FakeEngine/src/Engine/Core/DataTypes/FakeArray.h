#pragma once

#include "FakePch.h"

template<typename T, size_t T_Size>
class FakeArray
	{
	private:
		T Data[T_Size];

	public:
		FakeArray()
			{
			}

		void ZeroInitialize()
			{
			FAKE_ASSERT(Data, "No Data set!");
			memset(Data, 0, T_Size * sizeof(T));
			}

		void Print()
			{
			for (size_t i = 0; i < T_Size; ++i)
				std::cout << data[i] << std::endl;
			}

		constexpr int Size() const
			{
			return T_Size;
			}

		T *GetData() { return Data; }
		const T *GetData() const { return Data; }

		T &operator[](uint32_t i)
			{
			FAKE_ASSERT(i < T_Size, "Array index out of bounds!");
			return Data[i];
			}

		const T &operator[](uint32_t i) const
			{
			FAKE_ASSERT(i < T_Size, "Array index out of bounds!");
			return Data[i];
			}
	};
