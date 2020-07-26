#pragma once

#include "FakePch.h"

template<typename T>
class FakeList
	{
	private:
		struct Node
			{
			T Value;
			Node *Next;
			Node(T value) : Value(value), Next(nullptr) {}
			};

		Node *Root;
		uint32_t Length;

		void Append(Node *parent, T value)
			{
			if (parent->Next == nullptr)
				{
				parent->Next = new Node(value);
				++Length;
				}
			else
				{
				Append(parent->Next, value);
				}
			}

	public:
		FakeList()
			{
			Length = 0;
			Root = nullptr;
			}

		~FakeList()
			{
			Clear();
			delete Root;
			}

		void Append(T value)
			{
			if (Root == nullptr)
				{
				Root = new Node(value);
				++Length;
				}
			else
				{
				Append(Root, value);
				}
			}

		void Insert(T value)
			{
			Node *node = new Node(value);
			++Length;

			node->Next = Root;
			Root = node;
			}

		T GetFirst()
			{
			return Root->Value;
			}

		T GetLast()
			{
			Node *current = Root;
			FAKE_ASSERT(current, "Root was nullptr!");

			while (current->Next != nullptr)
				{
				current = current->Next;
				}

			return current->Value;
			}

		T Get(uint32_t index)
			{
			if (index <= 0)
				return GetFirst();

			if (index >= Length)
				return GetLast();

			Node *current = Root;
			FAKE_ASSERT(current, "Root was nullptr!");
			T ret = NULL;
			uint32_t i = 0;

			while (current != nullptr)
				{
				if (i == index)
					{
					ret = current->Value;
					break;
					}

				current = current->Next;
				i++;
				}

			return ret;
			}

		void RemoveFirst()
			{
			Node *tmp = Root;
			FAKE_ASSERT(tmp, "Root was nullptr!");
			Root = Root->Next;

			delete tmp;
			tmp = nullptr;
			--Length;
			}

		void RemoveLast()
			{
			if (Length == 1)
				{
				delete Root;
				Root = nullptr;
				Length = 0;
				return;
				}

			--Length;
			Node *current = Root;
			FAKE_ASSERT(current, "Root was nullptr!");

			while (current != nullptr)
				{
				if (current->Next->Next == nullptr)
					{
					delete current->Next;
					current->Next = nullptr;
					break;
					}

				current = current->Next;
				}
			}

		void Remove(uint32_t index)
			{
			if (index == 0)
				{
				RemoveFirst();
				return;
				}

			if (Length == index)
				{
				RemoveLast();
				return;
				}

			Node *current = Root;
			FAKE_ASSERT(current, "Root was nullptr!");
			uint32_t i = 0;
			--Length;

			while (current != nullptr)
				{
				if ((i + 1) == index)
					{
					Node *tmp = current->Next;
					current->Next = current->Next->Next;

					delete tmp;
					tmp = nullptr;

					break;
					}
				current = current->Next;
				}
			}

		void RemoveAll()
			{
			Clear();
			delete Root;
			}

		bool IsEmpty()
			{
			return Length == 0;
			}

		uint32_t Size()
			{
			return Length;
			}

		void Clear()
			{
			if (Length > 0)
				{
				Node *current = Root;
				FAKE_ASSERT(current, "Root was nullptr!");

				while (current != nullptr)
					{
					Node *tmp = current->Next;
					delete current;
					current = tmp;
					}

				Root = nullptr;
				Length = 0;
				}
			}

		T *ToArray()
			{
			T *arr = new T[Length];
			Node *current = Root;
			FAKE_ASSERT(current, "Root was nullptr!");
			uint32_t i = 0;

			while (current != nullptr)
				{
				arr[i] = current->Value;
				++i;
				current = current->Next;
				}

			return arr;
			}

		void Print()
			{
			if (Length == 0)
				{
				FAKE_LOG_WARN("List was empty!");
				return;
				}

			Node *current = Root;
			FAKE_ASSERT(current, "Root was nullptr!");

			while (current != nullptr)
				{
				std::cout << current->Value << std::endl;
				current = current->Next;
				}
			}

		friend std::ostream &operator<<(std::ostream &stream, FakeList<T> &list)
			{
			Node *current = list.Root;
			FAKE_ASSERT(current, "Root was nullptr!");
			uint32_t i = 0;

			stream << "[";
			while (current != nullptr)
				{
				if ((i + 1) == list.Size())
					{
					stream << current->Value;
					}
				else
					{
					stream << current->Value << ",";
					}

				++i;
				current = current->Next;
				}
			stream << "]";

			return stream;
			}
	};

typedef FakeList<int> FakeListInt;
typedef FakeList<float> FakeListFloat;
typedef FakeList<double> FakeListDouble;
typedef FakeList<const char*> FakeListString;
typedef FakeList<short> FakeListShort;
typedef FakeList<long> FakeListLong;
typedef FakeList<bool> FakeListBool;