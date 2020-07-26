#pragma once

#include "Engine/Core/DataTypes/FakeList.h"

template<typename T>
class FakeQueue
	{
	private:
		FakeList<T> List;

	public:
		FakeQueue() {}
		~FakeQueue() {}

		void Enqueue(T value)
			{
			List.Append(value);
			}

		void Dequeue()
			{
			List.RemoveFirst();
			}

		T Front()
			{
			return List.GetFirst();
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

typedef FakeQueue<int> FakeQueueInt;
typedef FakeQueue<float> FakeQueueFloat;
typedef FakeQueue<double> FakeQueueDouble;
typedef FakeQueue<const char*> FakeQueueString;
typedef FakeQueue<short> FakeQueueShort;
typedef FakeQueue<long> FakeQueueLong;
typedef FakeQueue<bool> FakeQueueBool;