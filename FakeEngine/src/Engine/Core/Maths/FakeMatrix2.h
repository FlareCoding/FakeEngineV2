#pragma once

#include <FakePch.h>
#include "Engine/Core/Maths/FakeMathFunctions.h"
#include "Engine/Core/Maths/FakeVector2.h"

// TODO:
// Performance Tests

template<typename T>
class FakeMatrix2
	{
	private:
		T Elements[4];

	public:
		FakeMatrix2()
			{
			Elements[0 + 0 * 2] = static_cast<T>(0);
			Elements[1 + 0 * 2] = static_cast<T>(0);
			Elements[0 + 1 * 2] = static_cast<T>(0);
			Elements[1 + 1 * 2] = static_cast<T>(0);
			}

		FakeMatrix2(T value)
			{
			Elements[0 + 0 * 2] = value;
			Elements[1 + 0 * 2] = static_cast<T>(0);
			Elements[0 + 1 * 2] = static_cast<T>(0);
			Elements[1 + 1 * 2] = value;
			}

		FakeMatrix2(T m00, T m01, T m10, T m11)
			{
			Elements[0 + 0 * 2] = m00;
			Elements[1 + 0 * 2] = m01;
			Elements[0 + 1 * 2] = m10;
			Elements[1 + 1 * 2] = m11;
			}

		FakeMatrix2(const FakeVector2<T> &a, const FakeVector2<T> &b)
			{
			Elements[0 + 0 * 2] = a.x;
			Elements[1 + 0 * 2] = a.y;
			Elements[0 + 1 * 2] = b.x;
			Elements[1 + 1 * 2] = b.y;
			}

		FakeMatrix2(const FakeMatrix2<T>&) = default;
		FakeMatrix2<T> &operator=(const FakeMatrix2<T>&) = default;

		FakeMatrix2<T> &Add(const FakeMatrix2<T> &other)
			{
			Elements[0 + 0 * 2] += other[0 + 0 * 2];
			Elements[1 + 0 * 2] += other[1 + 0 * 2];
			Elements[0 + 1 * 2] += other[0 + 1 * 2];
			Elements[1 + 1 * 2] += other[1 + 1 * 2];
			return *this;
			}

		FakeMatrix2<T> &AddScalar(T value)
			{
			Elements[0 + 0 * 2] += value;
			Elements[1 + 0 * 2] += value;
			Elements[0 + 1 * 2] += value;
			Elements[1 + 1 * 2] += value;
			return *this;
			}

		FakeMatrix2<T> &Subtract(const FakeMatrix2<T> &other)
			{
			Elements[0 + 0 * 2] -= other[0 + 0 * 2];
			Elements[1 + 0 * 2] -= other[1 + 0 * 2];
			Elements[0 + 1 * 2] -= other[0 + 1 * 2];
			Elements[1 + 1 * 2] -= other[1 + 1 * 2];
			return *this;
			}

		FakeMatrix2<T> &SubtractScalar(T value)
			{
			Elements[0 + 0 * 2] -= value;
			Elements[1 + 0 * 2] -= value;
			Elements[0 + 1 * 2] -= value;
			Elements[1 + 1 * 2] -= value;
			return *this;
			}

		// TODO
		FakeMatrix2<T> &Multiply(const FakeMatrix2<T> &other)
			{
			int32_t x, y, i;
			T sum;
			T data[4];

			for (y = 0; y < 2; ++y)
				{
				for (x = 0; x < 2; ++x)
					{
					sum = static_cast<T>(0);

					for (i = 0; i < 2; ++i)
						{
						sum += Elements[x + i * 2] * other[i + y * 2];
						}

					data[x + y * 2] = sum;
					}
				}

			memcpy(Elements, data, 4 * sizeof(T));
			return *this;
			}

		FakeMatrix2<T> &MultiplyScalar(T value)
			{
			// TODO

			return *this;
			}

		static FakeMatrix2<T> Identity()
			{
			return FakeMatrix2<T>(1);
			}

		static FakeMatrix2<T> Transpose(const FakeMatrix2<T> &other)
			{
			FakeMatrix2<T> result;
			result[0 + 0 * 2] = other[0 + 0 * 2];
			result[0 + 1 * 2] = other[1 + 0 * 2];
			result[1 + 0 * 2] = other[0 + 1 * 2];
			result[1 + 1 * 2] = other[1 + 1 * 2];
			return result;
			}

		static T Determinant(const FakeMatrix2<T> &other)
			{
			return other[0 + 0 * 2] * other[1 + 1 * 2] - other[1 + 0 * 2] * other[0 + 1 * 2];
			}

		static FakeMatrix2<T> Inverse(const FakeMatrix2<T> &other)
			{
			T oneOverDeterminant = static_cast<T>(1) / (
				+other[0 + 0 * 2] * other[1 + 1 * 2]
				-other[1 + 0 * 2] * other[0 + 1 * 2]);

			FakeMatrix2<T> result(
				+other[1 + 1 * 2] * oneOverDeterminant,
				-other[1 + 0 * 2] * oneOverDeterminant,
				-other[0 + 1 * 2] * oneOverDeterminant,
				+other[0 + 0 * 2] * oneOverDeterminant);

			return result;
			}

		friend FakeMatrix2<T> operator-(const FakeMatrix2<T> &other)
			{
			FakeMatrix2<T> result(
				-other[0 + 0 * 2],
				-other[1 + 0 * 2],
				-other[0 + 1 * 2],
				-other[1 + 1 * 2]);
			return result;
			}

		friend FakeMatrix2<T> operator+(FakeMatrix2<T> left, const FakeMatrix2<T> &right)
			{
			return left.Add(right);
			}

		friend FakeMatrix2<T> operator-(FakeMatrix2<T> left, const FakeMatrix2<T> &right)
			{
			return left.Subtract(right);
			}

		friend FakeMatrix2<T> operator*(FakeMatrix2<T> left, const FakeMatrix2<T> &right)
			{
			return left.Multiply(right);
			}

		friend FakeMatrix2<T> operator+(FakeMatrix2<T> left, T value)
			{
			return left.AddScalar(value);
			}

		friend FakeMatrix2<T> operator-(FakeMatrix2<T> left, T value)
			{
			return left.SubtractScalar(value);
			}

		friend FakeMatrix2<T> operator*(FakeMatrix2<T> left, T value)
			{
			return left.MultiplyScalar(value);
			}

		FakeMatrix2<T> &operator+=(const FakeMatrix2<T> &other)
			{
			return Add(other);
			}

		FakeMatrix2<T> &operator-=(const FakeMatrix2<T> &other)
			{
			return Subtract(other);
			}

		FakeMatrix2<T> &operator*=(const FakeMatrix2<T> &other)
			{
			return Multiply(other);
			}

		FakeMatrix2<T> &operator+=(T value)
			{
			return AddScalar(value);
			}

		FakeMatrix2<T> &operator-=(T value)
			{
			return SubtractScalar(value);
			}

		FakeMatrix2<T> &operator*=(T value)
			{
			return MultiplyScalar(value);
			}

		FakeMatrix2<T> operator++()
			{
			++Elements[0 + 0 * 2];
			++Elements[1 + 0 * 2];
			++Elements[0 + 1 * 2];
			++Elements[1 + 1 * 2];
			return *this;
			}

		FakeMatrix2<T> operator--()
			{
			--Elements[0 + 0 * 2];
			--Elements[1 + 0 * 2];
			--Elements[0 + 1 * 2];
			--Elements[1 + 1 * 2];
			return *this;
			}

		bool operator==(const FakeMatrix2<T> &other)
			{
			if (Elements[0 + 0 * 2] == other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] == other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] == other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] == other[1 + 1 * 2])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator==(const FakeMatrix2<T> &other) const
			{
			if (Elements[0 + 0 * 2] == other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] == other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] == other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] == other[1 + 1 * 2])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator!=(const FakeMatrix2<T> &other)
			{
			return !(*this == other);
			}

		bool operator!=(const FakeMatrix2<T> &other) const
			{
			return !(*this == other);
			}

		bool operator<(const FakeMatrix2<T> &other)
			{
			if (Elements[0 + 0 * 2] < other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] < other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] < other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] < other[1 + 1 * 2])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator<(const FakeMatrix2<T> &other) const
			{
			if (Elements[0 + 0 * 2] < other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] < other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] < other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] < other[1 + 1 * 2])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>(const FakeMatrix2<T> &other)
			{
			if (Elements[0 + 0 * 2] > other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] > other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] > other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] > other[1 + 1 * 2])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>(const FakeMatrix2<T> &other) const
			{
			if (Elements[0 + 0 * 2] > other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] > other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] > other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] > other[1 + 1 * 2])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator<=(const FakeMatrix2<T> &other)
			{
			if (Elements[0 + 0 * 2] <= other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] <= other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] <= other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] <= other[1 + 1 * 2])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator<=(const FakeMatrix2<T> &other) const
			{
			if (Elements[0 + 0 * 2] <= other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] <= other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] <= other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] <= other[1 + 1 * 2])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>=(const FakeMatrix2<T> &other)
			{
			if (Elements[0 + 0 * 2] >= other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] >= other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] >= other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] >= other[1 + 1 * 2])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>=(const FakeMatrix2<T> &other) const
			{
			if (Elements[0 + 0 * 2] >= other[0 + 0 * 2]
			 && Elements[1 + 0 * 2] >= other[1 + 0 * 2]
			 && Elements[0 + 1 * 2] >= other[0 + 1 * 2]
			 && Elements[1 + 1 * 2] >= other[1 + 1 * 2])
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
			FAKE_ASSERT(i < 4, "Index out of bounds");
			return Elements[i];
			}

		const T &operator[](uint32_t i) const
			{
			FAKE_ASSERT(i < 4, "Index out of bounds");
			return Elements[i];
			}

		friend std::ostream &operator<<(std::ostream &stream, const FakeMatrix2<T> &other)
			{
			stream << other[0 + 0 * 2] << ", " << other[1 + 0 * 2] << ", " << std::endl;
			stream << other[0 + 1 * 2] << ", " << other[1 + 1 * 2] << std::endl;
			return stream;
			}
	};

typedef FakeMatrix2<int> FakeMat2i;
typedef FakeMatrix2<double> FakeMat2d;
typedef FakeMatrix2<float> FakeMat2f;
typedef FakeMatrix2<short> FakeMat2s;
typedef FakeMatrix2<long> FakeMat2l;
typedef FakeMatrix2<bool> FakeMat2b;