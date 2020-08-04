#pragma once

template<typename T>
class FakeHArray
	{
	private:
		T *Data = nullptr;
		size_t _Size = 0;
		size_t _Capacity = 0;

	public:
		FakeHArray() = default;

		FakeHArray(size_t size)
			{

			}

		~FakeHArray()
			{
			delete[] Data;
			}

		size_t Size()
			{
			return _Size;
			}

		size_t Capacity()
			{
			return _Capacity;
			}

		void Resize(size_t size)
			{

			}

		void Reserve(size_t size)
			{

			}


	};

