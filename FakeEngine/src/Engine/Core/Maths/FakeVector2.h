#pragma once

#include "FakeMathFunctions.h"

template<typename T>
struct FakeVector2
	{
	T x, y;

	FakeVector2()
		{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		}

	FakeVector2(T value)
		{
		x = value;
		y = value;
		}

	FakeVector2(T x, T y)
		{
		this->x = x;
		this->y = y;
		}

	FakeVector2(const FakeVector2<T>&) = default;
	FakeVector2<T> &operator=(const FakeVector2<T>&) = default;

	FakeVector2<T> &Add(const FakeVector2<T> &other)
		{
		x += other.x;
		y += other.y;
		return *this;
		}

	FakeVector2<T> &Subtract(const FakeVector2<T> &other)
		{
		x -= other.x;
		y -= other.y;
		return *this;
		}

	FakeVector2<T> &Multiply(const FakeVector2<T> &other)
		{
		x *= other.x;
		y *= other.y;
		return *this;
		}

	// HINT: bei division durch 0 könnte man auch einen nullvektor zurück geben
	FakeVector2<T> &Divide(const FakeVector2<T> &other)
		{
		if (other.x > static_cast<T>(0) && other.y > static_cast<T>(0))
			{
			x /= other.x;
			y /= other.y;
			}

		return *this;
		}

	FakeVector2<T> &AddScalar(T value)
		{
		x += value;
		y += value;
		return *this;
		}

	FakeVector2<T> &SubtractScalar(T value)
		{
		x -= value;
		y -= value;
		return *this;
		}

	FakeVector2<T> &MultiplyScalar(T value)
		{
		x *= value;
		y *= value;
		return *this;
		}

	// HINT: bei division durch 0 könnte man auch einen nullvektor zurück geben
	FakeVector2<T> &DivideScalar(T value)
		{
		if (value > static_cast<T>(0))
			{
			x /= value;
			y /= value;
			}

		return *this;
		}

	T Length()
		{
		return fake_sqrt(x * x + y * y);
		}

	T InverseLength()
		{
		return static_cast<T>(1) / fake_sqrt(x * x + y * y);
		}

	static T InverseLength(const FakeVector2<T> &other)
		{
		return static_cast<T>(1) / fake_sqrt(other.x * other.x + other.y * other.y);
		}

	T Dot(const FakeVector2<T> &other)
		{
		return x * other.x + y * other.y;
		}

	static T Dot(const FakeVector2<T> &left, const FakeVector2<T> &right)
		{
		return left.x * right.x + left.y * right.y;
		}

	FakeVector2<T> &Normalize()
		{
		T invLen = InverseLength();
		x *= invLen;
		y *= invLen;
		return *this;
		}

	static FakeVector2<T> Normalize(const FakeVector2<T> &other)
		{
		T invLen = FakeVector2<T>::InverseLength(other);

		FakeVector2<T> result;
		result.x = other.x * invLen;
		result.y = other.y * invLen;
		return result;
		}

	FakeVector2<T> &Lerp(const FakeVector2<T> &other, T deltaTime)
		{
		x = x * static_cast<T>(1 - deltaTime) + other.x * deltaTime;
		y = y * static_cast<T>(1 - deltaTime) + other.y * deltaTime;
		return *this;
		}

	static FakeVector2<T> Lerp(const FakeVector2<T> &start, const FakeVector2<T> &end, T deltaTime)
		{
		FakeVector2<T> result;
		result.x = start.x * static_cast<T>(1 - deltaTime) + end.x * deltaTime;
		result.y = start.y * static_cast<T>(1 - deltaTime) + end.y * deltaTime;
		return result;
		}

	FakeVector2<T> &Abs()
		{
		x = ABS(x);
		y = ABS(y);
		return *this;
		}

	static FakeVector2<T> Abs(const FakeVector2<T> &other)
		{
		FakeVector2<T> result;
		result.x = ABS(other.x);
		result.y = ABS(other.y);
		return result;
		}

	FakeVector2<T> &Clamp(const FakeVector2<T> &min, const FakeVector2<T> &max)
		{
		x = MIN(MAX(x, min.x), max.x);
		y = MIN(MAX(y, min.y), max.y);
		return *this;
		}

	static FakeVector2<T> Clamp(FakeVector2<T> &vector, const FakeVector2<T> &min, const FakeVector2<T> &max)
		{
		FakeVector2<T> result;
		result.x = MIN(MAX(vector.x, min.x), max.x);
		result.y = MIN(MAX(vector.y, min.y), max.y);
		return result;
		}

	friend FakeVector2<T> operator+(FakeVector2<T> left, const FakeVector2<T> &right)
		{
		return left.Add(right);
		}

	friend FakeVector2<T> operator-(FakeVector2<T> left, const FakeVector2<T> &right)
		{
		return left.Subtract(right);
		}

	friend FakeVector2<T> operator*(FakeVector2<T> left, const FakeVector2<T> &right)
		{
		return left.Multiply(right);
		}

	friend FakeVector2<T> operator/(FakeVector2<T> left, const FakeVector2<T> &right)
		{
		return left.Divide(right);
		}

	friend FakeVector2<T> operator+(FakeVector2<T> left, T value)
		{
		return left.AddScalar(value);
		}

	friend FakeVector2<T> operator-(FakeVector2<T> left, T value)
		{
		return left.SubtractScalar(value);
		}

	friend FakeVector2<T> operator*(FakeVector2<T> left, T value)
		{
		return left.MultiplyScalar(value);
		}

	friend FakeVector2<T> operator/(FakeVector2<T> left, T value)
		{
		return left.DivideScalar(value);
		}

	FakeVector2<T> &operator++()
		{
		++x;
		++y;
		return *this;
		}

	FakeVector2<T> &operator--()
		{
		--x;
		--y;
		return *this;
		}

	FakeVector2<T> &operator+=(const FakeVector2<T> &other)
		{
		return Add(other);
		}

	FakeVector2<T> &operator-=(const FakeVector2<T> &other)
		{
		return Subtract(other);
		}

	FakeVector2<T> &operator*=(const FakeVector2<T> &other)
		{
		return Multiply(other);
		}

	FakeVector2<T> &operator/=(const FakeVector2<T> &other)
		{
		return Divide(other);
		}

	FakeVector2<T> &operator+=(T value)
		{
		return AddScalar(value);
		}

	FakeVector2<T> &operator-=(T value)
		{
		return SubtractScalar(value);
		}

	FakeVector2<T> &operator*=(T value)
		{
		return MultiplyScalar(value);
		}

	FakeVector2<T> &operator/=(T value)
		{
		return DivideScalar(value);
		}

	bool operator==(const FakeVector2<T> &other)
		{
		return x == other.x && y == other.y;
		}

	bool operator==(const FakeVector2<T> &other) const
		{
		return x == other.x && y == other.y;
		}

	bool operator!=(const FakeVector2<T> &other)
		{
		return !(*this == other);
		}

	bool operator!=(const FakeVector2<T> &other) const
		{
		return !(*this == other);
		}

	bool operator<(const FakeVector2<T> &other)
		{
		return x < other.x && y < other.y;
		}

	bool operator<(const FakeVector2<T> &other) const
		{
		return x < other.x && y < other.y;
		}

	bool operator>(const FakeVector2<T> &other)
		{
		return x > other.x && y > other.y;
		}

	bool operator>(const FakeVector2<T> &other) const
		{
		return y > other.x && y > other.y;
		}

	bool operator<=(const FakeVector2<T> &other)
		{
		return x <= other.x && y <= other.y;
		}

	bool operator<=(const FakeVector2<T> &other) const
		{
		return x <= other.x && y <= other.y;
		}

	bool operator>=(const FakeVector2<T> &other)
		{
		return x >= other.x && y >= other.y;
		}

	bool operator>=(const FakeVector2<T> &other) const
		{
		return x >= other.x && y >= other.y;
		}

	T &operator[](uint32_t i)
		{
		return *((T*)this + i);
		}

	const T &operator[](uint32_t i) const
		{
		return *((T*)this + i);
		}

	friend std::ostream &operator<<(std::ostream &stream, const FakeVector2<T> &other)
		{
		return stream << "[ " << other.x << ", " << other.y << " ]";
		}
	};

typedef FakeVector2<int> FakeVec2i;
typedef FakeVector2<double> FakeVec2d;
typedef FakeVector2<float> FakeVec2f;
typedef FakeVector2<short> FakeVec2s;
typedef FakeVector2<long> FakeVec2l;
typedef FakeVector2<bool> FakeVec2b;
