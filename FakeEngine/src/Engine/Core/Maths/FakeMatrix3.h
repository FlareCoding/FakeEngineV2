#pragma once

#include <FakePch.h>
#include "Engine/Core/Maths/FakeMathFunctions.h"
#include "Engine/Core/Maths/FakeVector3.h"
#include "Engine/Core/Maths/FakeMatrix2.h"

template<typename T>
class FakeMatrix3
	{
	private:
		T Elements[9];

	public:
		FakeMatrix3()
			{
			Elements[0 + 0 * 3] = static_cast<T>(0);
			Elements[1 + 0 * 3] = static_cast<T>(0);
			Elements[2 + 0 * 3] = static_cast<T>(0);
			Elements[0 + 1 * 3] = static_cast<T>(0);
			Elements[1 + 1 * 3] = static_cast<T>(0);
			Elements[2 + 1 * 3] = static_cast<T>(0);
			Elements[0 + 2 * 3] = static_cast<T>(0);
			Elements[1 + 2 * 3] = static_cast<T>(0);
			Elements[2 + 2 * 3] = static_cast<T>(0);
			}

		FakeMatrix3(T value)
			{
			Elements[0 + 0 * 3] = value;
			Elements[1 + 0 * 3] = static_cast<T>(0);
			Elements[2 + 0 * 3] = static_cast<T>(0);
			Elements[0 + 1 * 3] = static_cast<T>(0);
			Elements[1 + 1 * 3] = value;
			Elements[2 + 1 * 3] = static_cast<T>(0);
			Elements[0 + 2 * 3] = static_cast<T>(0);
			Elements[1 + 2 * 3] = static_cast<T>(0);
			Elements[2 + 2 * 3] = value;
			}

		FakeMatrix3(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22)
			{
			Elements[0 + 0 * 3] = m00;
			Elements[1 + 0 * 3] = m01;
			Elements[1 + 0 * 3] = m02;
			Elements[0 + 1 * 3] = m10;
			Elements[1 + 1 * 3] = m11;
			Elements[2 + 1 * 3] = m12;
			Elements[0 + 2 * 3] = m20;
			Elements[1 + 2 * 3] = m21;
			Elements[2 + 2 * 3] = m22;
			}

		FakeMatrix3(const FakeVector3<T> &a, const FakeVector3<T> &b, const FakeVector3<T> &c)
			{
			Elements[0 + 0 * 3] = a.x;
			Elements[1 + 0 * 3] = a.y;
			Elements[1 + 0 * 3] = a.z;
			Elements[0 + 1 * 3] = b.x;
			Elements[1 + 1 * 3] = b.y;
			Elements[2 + 1 * 3] = b.z;
			Elements[0 + 2 * 3] = c.x;
			Elements[1 + 2 * 3] = c.y;
			Elements[2 + 2 * 3] = c.z;
			}

		FakeMatrix3(const FakeMatrix2<T> &other)
			{
			Elements[0 + 0 * 3] = other[0 + 0 * 2];
			Elements[1 + 0 * 3] = other[1 + 0 * 2];
			Elements[1 + 0 * 3] = static_cast<T>(0);

			Elements[0 + 1 * 3] = other[0 + 1 * 2];
			Elements[1 + 1 * 3] = other[1 + 1 * 2];
			Elements[2 + 1 * 3] = static_cast<T>(0);

			Elements[0 + 2 * 3] = static_cast<T>(0);
			Elements[1 + 2 * 3] = static_cast<T>(0);
			Elements[2 + 2 * 3] = static_cast<T>(0);
			}

		FakeMatrix3(const FakeMatrix3<T>&) = default;
		FakeMatrix3<T> &operator=(const FakeMatrix3<T>&) = default;

		FakeMatrix3<T> &Add(const FakeMatrix3<T> &other)
			{
			Elements[0 + 0 * 3] += other[0 + 0 * 3];
			Elements[1 + 0 * 3] += other[1 + 0 * 3];
			Elements[2 + 0 * 3] += other[2 + 0 * 3];
			Elements[0 + 1 * 3] += other[0 + 1 * 3];
			Elements[1 + 1 * 3] += other[1 + 1 * 3];
			Elements[2 + 1 * 3] += other[2 + 1 * 3];
			Elements[0 + 2 * 3] += other[0 + 2 * 3];
			Elements[1 + 2 * 3] += other[1 + 2 * 3];
			Elements[2 + 2 * 3] += other[2 + 2 * 3];
			return *this;
			}

		FakeMatrix3<T> &AddScalar(T value)
			{
			Elements[0 + 0 * 3] += value;
			Elements[1 + 0 * 3] += value;
			Elements[2 + 0 * 3] += value;
			Elements[0 + 1 * 3] += value;
			Elements[1 + 1 * 3] += value;
			Elements[2 + 1 * 3] += value;
			Elements[0 + 2 * 3] += value;
			Elements[1 + 2 * 3] += value;
			Elements[2 + 2 * 3] += value;
			return *this;
			}

		FakeMatrix3<T> &Subtract(const FakeMatrix3<T> &other)
			{
			Elements[0 + 0 * 3] -= other[0 + 0 * 3];
			Elements[1 + 0 * 3] -= other[1 + 0 * 3];
			Elements[2 + 0 * 3] -= other[2 + 0 * 3];
			Elements[0 + 1 * 3] -= other[0 + 1 * 3];
			Elements[1 + 1 * 3] -= other[1 + 1 * 3];
			Elements[2 + 1 * 3] -= other[2 + 1 * 3];
			Elements[0 + 2 * 3] -= other[0 + 2 * 3];
			Elements[1 + 2 * 3] -= other[1 + 2 * 3];
			Elements[2 + 2 * 3] -= other[2 + 2 * 3];
			return *this;
			}

		FakeMatrix3<T> &SubtractScalar(T value)
			{
			Elements[0 + 0 * 3] -= value;
			Elements[1 + 0 * 3] -= value;
			Elements[2 + 0 * 3] -= value;
			Elements[0 + 1 * 3] -= value;
			Elements[1 + 1 * 3] -= value;
			Elements[2 + 1 * 3] -= value;
			Elements[0 + 2 * 3] -= value;
			Elements[1 + 2 * 3] -= value;
			Elements[2 + 2 * 3] -= value;
			return *this;
			}

		// TODO
		FakeMatrix3<T> &Multiply(const FakeMatrix3<T> &other)
			{
			int32_t x, y, i;
			T sum;
			T data[9];

			for (y = 0; y < 3; ++y)
				{
				for (x = 0; x < 3; ++x)
					{
					sum = static_cast<T>(0);

					for (i = 0; i < 3; ++i)
						{
						sum += Elements[x + i * 3] * other[i + y * 3];
						}

					data[x + y * 3] = sum;
					}
				}

			memcpy(Elements, data, 9 * sizeof(T));
			return *this;
			}

		FakeMatrix3<T> &MultiplyScalar(T value)
			{
			// TODO
			return *this;
			}

		static FakeMatrix3<T> Identity()
			{
			return FakeMatrix3<T>(1);
			}

		static FakeMatrix3<T> Transpose(const FakeMatrix3<T> &other)
			{
			FakeMatrix3<T> result;
			result[0 + 0 * 3] = other[0 + 0 * 3];
			result[0 + 1 * 3] = other[1 + 0 * 3];
			result[0 + 2 * 3] = other[2 + 0 * 3];
			result[1 + 0 * 3] = other[0 + 1 * 3];
			result[1 + 1 * 3] = other[1 + 1 * 3];
			result[1 + 2 * 3] = other[2 + 1 * 3];
			result[2 + 0 * 3] = other[0 + 2 * 3];
			result[2 + 1 * 3] = other[1 + 2 * 3];
			result[2 + 2 * 3] = other[2 + 2 * 3];
			return result;
			}

		static T Determinant(const FakeMatrix3<T> &other)
			{
			return 
				+ other[0 + 0 * 3] * (other[1 + 1 * 3] * other[2 + 2 * 3] - other[2 + 1 * 3] * other[1 + 2 * 3])
				- other[1 + 0 * 3] * (other[0 + 1 * 3] * other[2 + 2 * 3] - other[2 + 1 * 3] * other[0 + 2 * 3])
				+ other[2 + 0 * 3] * (other[0 + 1 * 3] * other[1 + 2 * 3] - other[1 + 1 * 3] * other[0 + 2 * 3]);
			}

		static FakeMatrix3<T> Inverse(const FakeMatrix3<T> &other)
			{
			T determinant, invDeterminant;
			T tmp[9];

			tmp[0] = other[4] * other[8] - other[5] * other[7];
			tmp[1] = other[7] * other[2] - other[8] * other[1];
			tmp[2] = other[1] * other[5] - other[2] * other[4];
			tmp[3] = other[5] * other[6] - other[3] * other[8];
			tmp[4] = other[0] * other[8] - other[2] * other[6];
			tmp[5] = other[2] * other[3] - other[0] * other[5];
			tmp[6] = other[3] * other[7] - other[4] * other[6];
			tmp[7] = other[6] * other[1] - other[7] * other[0];
			tmp[8] = other[0] * other[4] - other[1] * other[3];

			determinant = other[0] * tmp[0] + other[1] * tmp[3] + other[2] * tmp[6];
			invDeterminant = static_cast<T>(1) / determinant;

			FakeMatrix3<T> result;
			result[0] = invDeterminant * tmp[0];
			result[1] = invDeterminant * tmp[1];
			result[2] = invDeterminant * tmp[2];
			result[3] = invDeterminant * tmp[3];
			result[4] = invDeterminant * tmp[4];
			result[5] = invDeterminant * tmp[5];
			result[6] = invDeterminant * tmp[6];
			result[7] = invDeterminant * tmp[7];
			result[8] = invDeterminant * tmp[8];
			return result;
			}

		friend FakeMatrix3<T> operator-(const FakeMatrix3<T> &other)
			{
			FakeMatrix3<T> result(
				-other[0 + 0 * 3],
				-other[1 + 0 * 3],
				-other[2 + 0 * 3],
				-other[1 + 1 * 3],
				-other[1 + 1 * 3],
				-other[2 + 1 * 3],
				-other[0 + 2 * 3],
				-other[1 + 2 * 3],
				-other[2 + 2 * 3]);
			return result;
			}

		friend FakeMatrix3<T> operator+(FakeMatrix3<T> left, const FakeMatrix3<T> &right)
			{
			return left.Add(right);
			}

		friend FakeMatrix3<T> operator-(FakeMatrix3<T> left, const FakeMatrix3<T> &right)
			{
			return left.Subtract(right);
			}

		friend FakeMatrix3<T> operator*(FakeMatrix3<T> left, const FakeMatrix3<T> &right)
			{
			return left.Multiply(right);
			}

		friend FakeMatrix3<T> operator+(FakeMatrix3<T> left, T value)
			{
			return left.AddScalar(value);
			}

		friend FakeMatrix3<T> operator-(FakeMatrix3<T> left, T value)
			{
			return left.SubtractScalar(value);
			}

		friend FakeMatrix3<T> operator*(FakeMatrix3<T> left, T value)
			{
			return left.MultiplyScalar(value);
			}

		FakeMatrix3<T> &operator+=(const FakeMatrix3<T> &other)
			{
			return Add(other);
			}

		FakeMatrix3<T> &operator-=(const FakeMatrix3<T> &other)
			{
			return Subtract(other);
			}

		FakeMatrix3<T> &operator*=(const FakeMatrix3<T> &other)
			{
			return Multiply(other);
			}

		FakeMatrix3<T> &operator+=(T value)
			{
			return AddScalar(value);
			}

		FakeMatrix3<T> &operator-=(T value)
			{
			return SubtractScalar(value);
			}

		FakeMatrix3<T> &operator*=(T value)
			{
			return MultiplyScalar(value);
			}

		FakeMatrix3<T> operator++()
			{
			++Elements[0 + 0 * 3];
			++Elements[1 + 0 * 3];
			++Elements[2 + 0 * 3];
			++Elements[0 + 1 * 3];
			++Elements[1 + 1 * 3];
			++Elements[2 + 1 * 3];
			++Elements[0 + 2 * 3];
			++Elements[1 + 2 * 3];
			++Elements[2 + 2 * 3];
			return *this;
			}

		FakeMatrix3<T> operator--()
			{
			--Elements[0 + 0 * 3];
			--Elements[1 + 0 * 3];
			--Elements[2 + 0 * 3];
			--Elements[0 + 1 * 3];
			--Elements[1 + 1 * 3];
			--Elements[2 + 1 * 3];
			--Elements[0 + 2 * 3];
			--Elements[1 + 2 * 3];
			--Elements[2 + 2 * 3];
			return *this;
			}

		bool operator==(const FakeMatrix3<T> &other)
			{
			if (Elements[0 + 0 * 3] == other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] == other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] == other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] == other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] == other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] == other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] == other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] == other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] == other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator==(const FakeMatrix3<T> &other) const
			{
			if (Elements[0 + 0 * 3] == other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] == other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] == other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] == other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] == other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] == other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] == other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] == other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] == other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator!=(const FakeMatrix3<T> &other)
			{
			return !(*this == other);
			}

		bool operator!=(const FakeMatrix3<T> &other) const
			{
			return !(*this == other);
			}

		bool operator<(const FakeMatrix3<T> &other)
			{
			if (Elements[0 + 0 * 3] < other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] < other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] < other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] < other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] < other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] < other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] < other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] < other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] < other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator<(const FakeMatrix3<T> &other) const
			{
			if (Elements[0 + 0 * 3] < other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] < other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] < other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] < other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] < other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] < other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] < other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] < other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] < other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>(const FakeMatrix3<T> &other)
			{
			if (Elements[0 + 0 * 3] > other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] > other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] > other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] > other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] > other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] > other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] > other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] > other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] > other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>(const FakeMatrix3<T> &other) const
			{
			if (Elements[0 + 0 * 3] > other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] > other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] > other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] > other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] > other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] > other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] > other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] > other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] > other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator<=(const FakeMatrix3<T> &other)
			{
			if (Elements[0 + 0 * 3] <= other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] <= other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] <= other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] <= other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] <= other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] <= other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] <= other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] <= other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] <= other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator<=(const FakeMatrix3<T> &other) const
			{
			if (Elements[0 + 0 * 3] <= other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] <= other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] <= other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] <= other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] <= other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] <= other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] <= other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] <= other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] <= other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>=(const FakeMatrix3<T> &other)
			{
			if (Elements[0 + 0 * 3] >= other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] >= other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] >= other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] >= other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] >= other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] >= other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] >= other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] >= other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] >= other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>=(const FakeMatrix3<T> &other) const
			{
			if (Elements[0 + 0 * 3] >= other[0 + 0 * 3]
			 && Elements[1 + 0 * 3] >= other[1 + 0 * 3]
			 && Elements[2 + 0 * 3] >= other[2 + 0 * 3]
			 && Elements[0 + 1 * 3] >= other[0 + 1 * 3]
			 && Elements[1 + 1 * 3] >= other[1 + 1 * 3]
			 && Elements[2 + 1 * 3] >= other[2 + 1 * 3]
			 && Elements[0 + 2 * 3] >= other[0 + 2 * 3]
			 && Elements[1 + 2 * 3] >= other[1 + 2 * 3]
			 && Elements[2 + 2 * 3] >= other[2 + 2 * 3])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		T &operator[](uint32_t i)
			{
			FAKE_ASSERT(i < 9, "Index out of bounds");
			return Elements[i];
			}

		const T &operator[](uint32_t i) const
			{
			FAKE_ASSERT(i < 9, "Index out of bounds");
			return Elements[i];
			}

		friend std::ostream &operator<<(std::ostream &stream, const FakeMatrix3<T> &other)
			{
			stream << other[0 + 0 * 3] << ", " << other[1 + 0 * 3] << ", " << other[2 + 0 * 3] << ", " << std::endl;
			stream << other[0 + 1 * 3] << ", " << other[1 + 1 * 3] << ", " << other[2 + 1 * 3] << ", " << std::endl;
			stream << other[0 + 2 * 3] << ", " << other[1 + 2 * 3] << ", " << other[2 + 2 * 3] << std::endl;
			return stream;
			}
	};

typedef FakeMatrix3<int> FakeMat3i;
typedef FakeMatrix3<double> FakeMat3d;
typedef FakeMatrix3<float> FakeMat3f;
typedef FakeMatrix3<short> FakeMat3s;
typedef FakeMatrix3<long> FakeMat3l;
typedef FakeMatrix3<bool> FakeMat3b;
