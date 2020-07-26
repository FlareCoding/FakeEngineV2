#pragma once

#include "Engine/Core/DataTypes/FakeList.h"

template<typename T>
class FakeStack
	{
	private:
		FakeList<T> List;

	public:
		FakeStack() {}
		~FakeStack() {}

		void Push(T value)
			{
			List.Append(value);
			}

		void Pop()
			{
			List.RemoveLast();
			}

		T Top()
			{
			return List.GetLast();
			}

		bool IsEmpty()
			{
			return List.IsEmpty();
			}

		uint32_t Size()
			{
			return List.Size();
			}

		void Print()
			{
			List.Print();
			}
	};

typedef FakeStack<int> FakeStackInt;
typedef FakeStack<float> FakeStackFloat;
typedef FakeStack<double> FakeStackDouble;
typedef FakeStack<const char*> FakeStackString;
typedef FakeStack<short> FakeStackShort;
typedef FakeStack<long> FakeStackLong;
typedef FakeStack<bool> FakeStackBool;