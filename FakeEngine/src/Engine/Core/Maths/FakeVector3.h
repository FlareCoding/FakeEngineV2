#pragma once

#include "FakeMathFunctions.h"

template<typename T>
struct FakeQuaternion;

template<typename T>
struct FakeVector4;

template<typename T>
struct FakeVector3
	{
	T x, y, z;

	FakeVector3()
		{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
		}

	FakeVector3(T value)
		{
		x = value;
		y = value;
		z = value;
		}

	FakeVector3(T x, T y, T z)
		{
		this->x = x;
		this->y = y;
		this->z = z;
		}

	FakeVector3(const FakeVector3<T>&) = default;
	FakeVector3<T> &operator=(const FakeVector3<T>&) = default;

	FakeVector3<T> &Add(const FakeVector3<T> &other)
		{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
		}

	FakeVector3<T> &Subtract(const FakeVector3<T> &other)
		{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
		}

	FakeVector3<T> &Multiply(const FakeVector3<T> &other)
		{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
		}

	FakeVector3<T> &Divide(const FakeVector3<T> &other)
		{
		if (other.x > static_cast<T>(0) && other.y > static_cast<T>(0) && other.z > static_cast<T>(0))
			{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			}

		return *this;
		}

	FakeVector3<T> &AddScalar(T value)
		{
		x += value;
		y += value;
		z += value;
		return *this;
		}

	FakeVector3<T> &SubtractScalar(T value)
		{
		x -= value;
		y -= value;
		z -= value;
		return *this;
		}

	FakeVector2<T> &MultiplyScalar(T value)
		{
		x *= value;
		y *= value;
		z *= value;
		return *this;
		}

	FakeVector2<T> &DivideScalar(T value)
		{
		if (value > static_cast<T>(0))
			{
			x /= value;
			y /= value;
			z /= value;
			}

		return *this;
		}

	T Length()
		{
		return fake_sqrt(x * x + y * y + z * z);
		}

	T InverseLength()
		{
		return static_cast<T>(1) / fake_sqrt(x * x + y * y + z * z);
		}

	static T InverseLength(const FakeVector3<T> &other)
		{
		return static_cast<T>(1) / fake_sqrt(other.x * other.x + other.y * other.y + other.z * other.z);
		}

	T Dot(const FakeVector3<T> &other)
		{
		return x * other.x + y * other.y + z * other.z;
		}

	static T Dot(const FakeVector3<T> &left, const FakeVector3<T> &right)
		{
		return left.x * right.x + left.y * right.y + left.z * right.z;
		}

	FakeVector3<T> &Cross(const FakeVector3<T> &other)
		{
		x = y * other.z - other.y * z;
		y = z * other.x - other.z * x;
		z = x * other.y - other.x * y;
		return *this;
		}

	static FakeVector3<T> Cross(FakeVector3<T> &left, const FakeVector3<T> &right)
		{
		FakeVector3<T> result;
		result.x = left.y * right.z - right.y * left.z;
		result.y = left.z * right.x - right.z * left.x;
		result.z = left.x * right.y - right.x * left.y;
		return result;
		}

	FakeVector3<T> &Normalize()
		{
		T invLen = InverseLength();
		x *= invLen;
		y *= invLen;
		z *= invLen;
		return *this;
		}

	static FakeVector3<T> Normalize(const FakeVector3<T> &other)
		{
		T invLen = FakeVector3<T>::InverseLength(other);

		FakeVector3<T> result;
		result.x = other.x * invLen;
		result.y = other.y * invLen;
		result.z = other.z * invLen;
		return result;
		}

	FakeVector3<T> &Lerp(const FakeVector3<T> &other, T t)
		{
		if (t < static_cast<T>(0)) t = static_cast<T>(0);
		if (t > static_cast<T>(1)) t = static_cast<T>(1);

		x = x * (static_cast<T>(1) - t) + other.x * t;
		y = y * (static_cast<T>(1) - t) + other.y * t;
		z = z * (static_cast<T>(1) - t) + other.z * t;

		return *this;
		}

	static FakeVector3<T> Lerp(const FakeVector3<T> &a, const FakeVector3<T> &b, T t)
		{
		if (t < static_cast<T>(0)) t = static_cast<T>(0);
		if (t > static_cast<T>(1)) t = static_cast<T>(1);

		FakeVector3<T> result;
		result.x = a.x * (static_cast<T>(1) - t) + b.x * t;
		result.y = a.y * (static_cast<T>(1) - t) + b.y * t;
		result.z = a.z * (static_cast<T>(1) - t) + b.z * t;
		return result;
		}

	FakeVector3<T> &Abs()
		{
		x = ABS(x);
		y = ABS(y);
		z = ABS(z);
		return *this;
		}

	static FakeVector3<T> Abs(FakeVector3<T> &other)
		{
		FakeVector3<T> result;
		result.x = ABS(other.x);
		result.y = ABS(other.y);
		result.z = ABS(other.z);
		return result;
		}

	FakeVector3<T> &Clamp(const FakeVector3<T> &min, const FakeVector3<T> &max)
		{
		x = MIN(MAX(x, min.x), max.x);
		y = MIN(MAX(y, min.y), max.y);
		z = MIN(MAX(z, min.z), max.z);
		return *this;
		}

	static FakeVector3<T> Clamp(FakeVector3<T> &vector, const FakeVector3<T> &min, const FakeVector3<T> &max)
		{
		FakeVector3<T> result;
		result.x = MIN(MAX(vector.x, min.x), max.x);
		result.y = MIN(MAX(vector.y, min.y), max.y);
		result.z = MIN(MAX(vector.z, min.z), max.z);
		return result;
		}

	static T Distance(const FakeVector3<T> &left, const FakeVector3<T> &right)
		{
		FakeVector3<T> delta = right - left;
		return delta.Length();
		}

	static FakeVector3<T> Rotate(FakeQuaternion<T> &quat, const FakeVector3<T> &axis)
		{
		// TODO
		return FakeVector3<T>(0);
		// return quat * axis;
		}

	static FakeVector3<T> Up()
		{
		return FakeVector3<T>(0, 1, 0);
		}

	static FakeVector3<T> Down()
		{
		return FakeVector3<T>(0, -1, 0);
		}

	static FakeVector3<T> Left()
		{
		return FakeVector3<T>(-1, 0, 0);
		}

	static FakeVector3<T> Right()
		{
		return FakeVector3<T>(1, 0, 0);
		}

	static FakeVector3<T> Zero()
		{
		return FakeVector3<T>(0, 0, 0);
		}

	static FakeVector3<T> XAxis()
		{
		return FakeVector3<T>(1, 0, 0);
		}

	static FakeVector3<T> YAxis()
		{
		return FakeVector3<T>(0, 1, 0);
		}

	static FakeVector3<T> ZAxis()
		{
		return FakeVector3<T>(0, 0, 1);
		}

	friend FakeVector3<T> operator-(const FakeVector3<T> &other)
		{
		FakeVector3<T> result;
		result.x = -other.x;
		result.y = -other.y;
		result.z = -other.z;
		return result;
		}

	friend FakeVector3<T> &operator+(FakeVector3<T> left, const FakeVector3<T> &right)
		{
		return left.Add(right);
		}

	friend FakeVector3<T> &operator-(FakeVector3<T> left, const FakeVector3<T> &right)
		{
		return left.Subtract(right);
		}

	friend FakeVector3<T> &operator*(FakeVector3<T> left, const FakeVector3<T> &right)
		{
		return left.Multiply(right);
		}

	friend FakeVector3<T> &operator/(FakeVector3<T> left, const FakeVector3<T> &right)
		{
		return left.Divide(right);
		}

	friend FakeVector3<T> &operator+(FakeVector3<T> left, T value)
		{
		return left.AddScalar(value);
		}

	friend FakeVector3<T> &operator-(FakeVector3<T> left, T value)
		{
		return left.SubtractScalar(value);
		}

	friend FakeVector3<T> &operator*(FakeVector3<T> left, T value)
		{
		return left.MultiplyScalar(value);
		}

	friend FakeVector3<T> &operator/(FakeVector3<T> left, T value)
		{
		return left.DivideScalar(value);
		}

	FakeVector3<T> &operator++()
		{
		++x;
		++y;
		++z;
		return *this;
		}

	FakeVector3<T> &operator--()
		{
		--x;
		--y;
		--z;
		return *this;
		}

	FakeVector3<T> &operator+=(const FakeVector3<T> &other)
		{
		return Add(other);
		}

	FakeVector3<T> &operator-=(const FakeVector3<T> &other)
		{
		return Subtract(other);
		}

	FakeVector3<T> &operator*=(const FakeVector3<T> &other)
		{
		return Multiply(other);
		}

	FakeVector3<T> &operator/=(const FakeVector3<T> &other)
		{
		return Divide(other);
		}

	FakeVector3<T> &operator+=(T value)
		{
		return AddScalar(value);
		}

	FakeVector3<T> &operator-=(T value)
		{
		return SubtractScalar(value);
		}

	FakeVector3<T> &operator*=(T value)
		{
		return MultiplyScalar(value);
		}

	FakeVector3<T> &operator/=(T value)
		{
		return DivideScalar(value);
		}

	bool operator==(const FakeVector3<T> &other)
		{
		return x == other.x && y == other.y && z == other.z;
		}

	bool operator==(const FakeVector3<T> &other) const
		{
		return x == other.x && y == other.y && z == other.z;
		}

	bool operator!=(const FakeVector3<T> &other)
		{
		return !(*this == other);
		}

	bool operator!=(const FakeVector3<T> &other) const
		{
		return !(*this == other);
		}

	bool operator<(const FakeVector3<T> &other)
		{
		return x < other.x && y < other.y && z < other.z;
		}

	bool operator<(const FakeVector3<T> &other) const
		{
		return x < other.x && y < other.y && z < other.z;
		}

	bool operator>(const FakeVector3<T> &other)
		{
		return x > other.x && y > other.y && z > other.z;
		}

	bool operator>(const FakeVector3<T> &other) const
		{
		return x > other.x && y > other.y && z > other.z;
		}

	bool operator<=(const FakeVector3<T> &other)
		{
		return x <= other.x && y <= other.y && z <= other.z;
		}

	bool operator<=(const FakeVector3<T> &other) const
		{
		return x <= other.x && y <= other.y && z <= other.z;
		}

	bool operator>=(const FakeVector3<T> &other)
		{
		return x >= other.x && y >= other.y && z >= other.z;
		}

	bool operator>=(const FakeVector3<T> &other) const
		{
		return x >= other.x && y >= other.y && z >= other.z;
		}

	FakeVector3<T> &operator=(const FakeVector4<T> &other)
		{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
		}

	T &operator[](uint32_t i)
		{
		return *((T*)this + i);
		}

	const T &operator[](uint32_t i) const
		{
		return *((T*)this + i);
		}

	friend std::ostream &operator<<(std::ostream &stream, const FakeVector3<T> &other)
		{
		return stream << "[ " << other.x << ", " << other.y << ", " << other.z << " ]";
		}
	};

typedef FakeVector3<int> FakeVec3i;
typedef FakeVector3<double> FakeVec3d;
typedef FakeVector3<float> FakeVec3f;
typedef FakeVector3<short> FakeVec3s;
typedef FakeVector3<long> FakeVec3l;
typedef FakeVector3<bool> FakeVec3b;
