#pragma once

#include <limits>
#include <type_traits>

#define _USE_MATH_DEFINES
#include <math.h>

#define FAKE_PI M_PI
#define FAKE_EPSILON std::numeric_limits<float>::epsilon

template<typename T>
inline T fake_min_value()
	{
	return std::numeric_limits<T>::min();
	}

template<typename T>
inline T fake_max_value()
	{
	return std::numeric_limits<T>::max();
	}

template<typename T>
inline T fake_radians(T degrees)
	{
	return degrees * static_cast<T>(FAKE_PI / 180.0);
	}

template<typename T>
inline T fake_degrees(T radians)
	{
	return radians * static_cast<T>(180.0 / FAKE_PI);
	}

template<typename T>
inline T fake_faculty(T num)
	{
	T ret = static_cast<T>(1);
	T i;

	for (i = ret; i <= num; ++i)
		{
		ret *= i;
		}

	return ret;
	}

template<typename T>
inline T fake_pow(T basis, uint32_t potenz)
	{
	if (static_cast<T>(0) == potenz)
		return static_cast<T>(1);

	T ret = basis;
	uint32_t i;

	for (i = 0; i < potenz; ++i)
		{
		ret *= basis;
		}

	return ret / static_cast<T>(2);
	}

// HINT: fake_sqrt returns wrong values if ints are provided as argument
// TODO: static_casts for raw values
template<typename T>
inline T fake_sqrt(T value)
	{
	T ret = static_cast<T>(1);
	uint32_t i;

	for (i = 0; i <= 10; ++i)
		{
		ret -= (ret * ret - value) / (2 * ret);
		}

	return ret;
	}
