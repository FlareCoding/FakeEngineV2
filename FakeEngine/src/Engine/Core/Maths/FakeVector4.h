#pragma once

#include "FakeMathFunctions.h"
#include "FakeVector3.h"

template<typename T>
struct FakeVector4
	{
	T x, y, z, w;

	FakeVector4()
		{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
		w = static_cast<T>(0);
		}

	FakeVector4(T value)
		{
		x = value;
		y = value;
		z = value;
		w = value;
		}

	FakeVector4(T x, T y, T z, T w)
		{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		}

	FakeVector4(const FakeVector4<T>&) = default;
	FakeVector4<T> &operator=(const FakeVector4<T>&) = default;

	FakeVector4<T> &Add(const FakeVector4<T> &other)
		{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
		}

	FakeVector4<T> &Subtract(const FakeVector4<T> &other)
		{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
		}

	FakeVector4<T> &Multiply(const FakeVector4<T> &other)
		{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
		}

	FakeVector4<T> &Divide(const FakeVector4<T> &other)
		{
		if (other.x > static_cast<T>(0) && other.y > static_cast<T>(0) && other.z > static_cast<T>(0) && other.w > static_cast<T>(0))
			{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			}

		return *this;
		}

	FakeVector4<T> &AddScalar(T value)
		{
		x += value;
		y += value;
		z += value;
		w *= value;
		return *this;
		}

	FakeVector4<T> &SubtractScalar(T value)
		{
		x -= value;
		y -= value;
		z -= value;
		w -= value;
		return *this;
		}

	FakeVector4<T> &MultiplyScalar(T value)
		{
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
		}

	FakeVector4<T> &DivideScalar(T value)
		{
		if (value > static_cast<T>(0))
			{
			x /= value;
			y /= value;
			z /= value;
			w /= value;
			}

		return *this;
		}

	T Length()
		{
		return fake_sqrt(x * x + y * y + z * z + w * w);
		}

	T InverseLength()
		{
		return static_cast<T>(1) / fake_sqrt(x * x + y * y + z * z + w * w);
		}

	static T InverseLength(const FakeVector4<T> &other)
		{
		return static_cast<T>(1) / fake_sqrt(other.x * other.x + other.y * other.y + other.z * other.z + other.w * other.w);
		}

	T Dot(const FakeVector4<T> &other)
		{
		return x * other.x + y * other.y + z * other.z + w * other.w;
		}

	static T Dot(const FakeVector4<T> &left, const FakeVector4<T> &right)
		{
		return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
		}

	FakeVector4<T> &Cross(const FakeVector4<T> &other)
		{
		x = y * other.z - other.y * z;
		y = z * other.x - other.z * x;
		z = x * other.y - other.x * y;
		w = static_cast<T>(0);
		return *this;
		}

	static FakeVector4<T> Cross(FakeVector4<T> &left, const FakeVector4<T> &right)
		{
		FakeVector4<T> result;
		result.x = left.y * right.z - right.y * left.z;
		result.y = left.z * right.x - right.z * left.x;
		result.z = left.x * right.y - right.x * left.y;
		result.w = static_cast<T>(0);
		return result;
		}

	FakeVector4<T> &Normalize()
		{
		T invLen = InverseLength();
		x *= invLen;
		y *= invLen;
		z *= invLen;
		w *= invLen;
		return *this;
		}

	static FakeVector4<T> Normalize(const FakeVector4<T> &other)
		{
		T invLen = FakeVector4<T>::InverseLength(other);

		FakeVector4<T> result;
		result.x = other.x * invLen;
		result.y = other.y * invLen;
		result.z = other.z * invLen;
		result.w = other.w * invLen;
		return result;
		}

	FakeVector4<T> &Lerp(const FakeVector4<T> &other, T t)
		{
		if (t < static_cast<T>(0)) t = static_cast<T>(0);
		if (t > static_cast<T>(1)) t = static_cast<T>(1);

		x = x * (static_cast<T>(1) - t) + other.x * t;
		y = y * (static_cast<T>(1) - t) + other.y * t;
		z = z * (static_cast<T>(1) - t) + other.z * t;
		w = w * (static_cast<T>(1) - t) + other.w * t;

		return *this;
		}

	static FakeVector4<T> Lerp(const FakeVector4<T> &a, const FakeVector4<T> &b, T t)
		{
		if (t < static_cast<T>(0)) t = static_cast<T>(0);
		if (t > static_cast<T>(1)) t = static_cast<T>(1);

		FakeVector4<T> result;
		result.x = a.x * (static_cast<T>(1) - t) + b.x * t;
		result.y = a.y * (static_cast<T>(1) - t) + b.y * t;
		result.z = a.z * (static_cast<T>(1) - t) + b.z * t;
		result.w = a.w * (static_cast<T>(1) - t) + b.w * t;
		return result;
		}

	FakeVector4<T> &Abs()
		{
		x = ABS(x);
		y = ABS(y);
		z = ABS(z);
		w = ABS(w);
		return *this;
		}

	static FakeVector4<T> Abs(FakeVector4<T> &other)
		{
		FakeVector4<T> result;
		result.x = ABS(other.x);
		result.y = ABS(other.y);
		result.z = ABS(other.z);
		result.w = ABS(other.w);
		return result;
		}

	FakeVector4<T> &Clamp(const FakeVector4<T> &min, const FakeVector4<T> &max)
		{
		x = MIN(MAX(x, min.x), max.x);
		y = MIN(MAX(y, min.y), max.y);
		z = MIN(MAX(z, min.z), max.z);
		w = MIN(MAX(w, min.w), max.w);
		return *this;
		}

	static FakeVector4<T> Clamp(FakeVector4<T> &vector, const FakeVector4<T> &min, const FakeVector4<T> &max)
		{
		FakeVector4<T> result;
		result.x = MIN(MAX(vector.x, min.x), max.x);
		result.y = MIN(MAX(vector.y, min.y), max.y);
		result.z = MIN(MAX(vector.z, min.z), max.z);
		result.w = MIN(MAX(vector.w, min.w), max.w);
		return result;
		}

	friend FakeVector4<T> operator-(const FakeVector4<T> &other)
		{
		FakeVector4<T> result;
		result.x = -other.x;
		result.y = -other.y;
		result.z = -other.z;
		result.w = -other.w;
		return result;
		}

	friend FakeVector4<T> &operator+(FakeVector4<T> left, const FakeVector4<T> &right)
		{
		return left.Add(right);
		}

	friend FakeVector4<T> &operator-(FakeVector4<T> left, const FakeVector4<T> &right)
		{
		return left.Subtract(right);
		}

	friend FakeVector4<T> &operator*(FakeVector4<T> left, const FakeVector4<T> &right)
		{
		return left.Multiply(right);
		}

	friend FakeVector4<T> &operator/(FakeVector4<T> left, const FakeVector4<T> &right)
		{
		return left.Divide(right);
		}

	friend FakeVector4<T> &operator+(FakeVector4<T> left, T value)
		{
		return left.AddScalar(value);
		}

	friend FakeVector4<T> &operator-(FakeVector4<T> left, T value)
		{
		return left.SubtractScalar(value);
		}

	friend FakeVector4<T> &operator*(FakeVector4<T> left, T value)
		{
		return left.MultiplyScalar(value);
		}

	friend FakeVector4<T> &operator/(FakeVector4<T> left, T value)
		{
		return left.DivideScalar(value);
		}

	FakeVector4<T> &operator++()
		{
		++x;
		++y;
		++z;
		++w;
		return *this;
		}

	FakeVector4<T> &operator--()
		{
		--x;
		--y;
		--z;
		--w;
		return *this;
		}

	FakeVector4<T> &operator+=(const FakeVector4<T> &other)
		{
		return Add(other);
		}

	FakeVector4<T> &operator-=(const FakeVector4<T> &other)
		{
		return Subtract(other);
		}

	FakeVector4<T> &operator*=(const FakeVector4<T> &other)
		{
		return Multiply(other);
		}

	FakeVector4<T> &operator/=(const FakeVector4<T> &other)
		{
		return Divide(other);
		}

	FakeVector4<T> &operator+=(T value)
		{
		return AddScalar(value);
		}

	FakeVector4<T> &operator-=(T value)
		{
		return SubtractScalar(value);
		}

	FakeVector4<T> &operator*=(T value)
		{
		return MultiplyScalar(value);
		}

	FakeVector4<T> &operator/=(T value)
		{
		return DivideScalar(value);
		}

	bool operator==(const FakeVector4<T> &other)
		{
		return x == other.x && y == other.y && z == other.z && w == other.w;
		}

	bool operator==(const FakeVector4<T> &other) const
		{
		return x == other.x && y == other.y && z == other.z && w == other.w;
		}

	bool operator!=(const FakeVector4<T> &other)
		{
		return !(*this == other);
		}

	bool operator!=(const FakeVector4<T> &other) const
		{
		return !(*this == other);
		}

	bool operator<(const FakeVector4<T> &other)
		{
		return x < other.x && y < other.y && z < other.z && w < other.w;
		}

	bool operator<(const FakeVector4<T> &other) const
		{
		return x < other.x && y < other.y && z < other.z && w < other.w;
		}

	bool operator>(const FakeVector4<T> &other)
		{
		return x > other.x && y > other.y && z > other.z && w > other.w;
		}

	bool operator>(const FakeVector4<T> &other) const
		{
		return x > other.x && y > other.y && z > other.z && w > other.w;
		}

	bool operator<=(const FakeVector4<T> &other)
		{
		return x <= other.x && y <= other.y && z <= other.z && w <= other.w;
		}

	bool operator<=(const FakeVector4<T> &other) const
		{
		return x <= other.x && y <= other.y && z <= other.z && w <= other.w;
		}

	bool operator>=(const FakeVector4<T> &other)
		{
		return x >= other.x && y >= other.y && z >= other.z && w >= other.w;
		}

	bool operator>=(const FakeVector4<T> &other) const
		{
		return x >= other.x && y >= other.y && z >= other.z && w >= other.w;
		}

	T &operator[](uint32_t i)
		{
		return *((T *)this + i);
		}

	const T &operator[](uint32_t i) const
		{
		return *((T *)this + i);
		}

	friend std::ostream &operator<<(std::ostream &stream, const FakeVector4<T> &other)
		{
		return stream << "[ " << other.x << ", " << other.y << ", " << other.z << ", " << other.w << " ]";
		}
	};

typedef FakeVector4<int> FakeVec4i;
typedef FakeVector4<double> FakeVec4d;
typedef FakeVector4<float> FakeVec4f;
typedef FakeVector4<short> FakeVec4s;
typedef FakeVector4<long> FakeVec4l;
typedef FakeVector4<bool> FakeVec4b;