#pragma once

#include <vector>
#include <memory>

template<typename T, typename F>
class FakeHashmap
	{
	private:
		std::vector<std::pair<T, F>> Elements;

	public:
		FakeHashmap()
			{
			}

		~FakeHashmap()
			{
			Elements.clear();
			Elements.shrink_to_fit();
			}

		bool ContainsKey(T key)
			{
			for (auto it = Elements.begin(); it != Elements.end(); ++it)
				{
				std::pair<T, F> current = *it;
				if (current.first == key)
					return true;
				}

			return false;
			}

		bool ContainsValue(F value)
			{
			for (auto it = Elements.begin(); it != Elements.end(); ++it)
				{
				std::pair<T, F> current = *it;
				if (current.second == value)
					return true;
				}

			return false;
			}

		bool Put(T key, F value)
			{
			if (!ContainsKey(key) && !ContainsValue(value))
				{
				std::pair<T, F> pair;
				pair.first = key;
				pair.second = value;
				Elements.push_back(pair);
				return true;
				}

			return false;
			}

		bool Set(T key, F value)
			{
			if (ContainsKey(key))
				{
				uint32_t i;
				for (i = 0; i < Elements.size(); ++i)
					{
					std::pair<T, F> current = Elements.at(i);
					if (current.first == key)
						{
						Elements.at(i).second = value;
						return true;
						}
					}
				}

			return false;
			}

		bool Remove(T key, F value)
			{
			if (ContainsKey(key) && ContainsValue(value))
				{
				uint32_t i;
				for (i = 0; i < Elements.size(); ++i)
					{
					std::pair<T, F> current = Elements.at(i);
					if (current.first == key && current.second == value)
						{
						Elements.erase(Elements.begin() + i);
						return true;
						}
					}
				}

			return false;
			}

		bool Remove(T key)
			{
			if (ContainsKey(key))
				{
				uint32_t i;
				for (i = 0; i < Elements.size(); ++i)
					{
					std::pair<T, F> current = Elements.at(i);
					if (current.first == key)
						Elements.erase(Elements.begin() + i);
					}

				return true;
				}

			return false;
			}

		void RemoveAll()
			{
			Elements.clear();
			Elements.shrink_to_fit();
			}

		bool RemoveFirst()
			{
			Elements.erase(Elements.begin() + 0);
			return true;
			}

		bool RemoveLast()
			{
			Elements.erase(Elements.begin() + (Elements.size() - 1));
			return true;
			}

		F GetFirst()
			{
			return Elements.at(0).second;
			}

		F GetLast()
			{
			return Elements.at(Elements.size() - 1).second;
			}

		F GetAt(int i)
			{
			return Elements.at(i).second;
			}

		T GetKey(int i)
			{
			return Elements.at(i).first;
			}

		bool IsEmpty()
			{
			return Elements.size() == 0;
			}

		uint32_t Size()
			{
			return (uint32_t)Elements.size();
			}

		void Print()
			{
			for (auto it = Elements.begin(); it != Elements.end(); it++)
				{
				std::pair<T, F> current = *it;
				std::cout << current.first << ", " << current.second << std::endl;
				}
			}

		std::pair<T, F> &operator[](size_t i)
			{
			return Elements.at(i);
			}

		friend std::ostream &operator<<(std::ostream &stream, FakeHashmap<T, F> &hashmap)
			{
			stream << "[" << std::endl;
			uint32_t i;
			for (i = 0; i < hashmap.Size(); ++i)
				{
				std::pair<T, F> &current = hashmap[i];

				stream << "  {";
				stream << " " << current.first << ", " << current.second << " ";

				if ((i + 1) == hashmap.Size())
					{
					stream << "}" << std::endl;
					}
				else
					{
					stream << "}," << std::endl;
					}
				}
			stream << "]";

			return stream;
			}
	};

typedef FakeHashmap<const char*, int> FakeHashmapInt;
typedef FakeHashmap<const char*, float> FakeHashmapFloat;
typedef FakeHashmap<const char*, double> FakeHashmapDouble;
typedef FakeHashmap<const char*, const char*> FakeHashmapString;
typedef FakeHashmap<const char*, short> FakeHashmapShort;
typedef FakeHashmap<const char*, long> FakeHashmapLong;
typedef FakeHashmap<const char*, bool> FakeHashmapBool;