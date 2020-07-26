#pragma once

#include <limits>
#include <type_traits>

struct FakeBasicOperators
	{
	template<typename T>
	static T MinValue()
		{
		return std::numeric_limits<T>::min();
		}

	template<typename T>
	static T MaxValue()
		{
		return std::numeric_limits<T>::max();
		}
	};