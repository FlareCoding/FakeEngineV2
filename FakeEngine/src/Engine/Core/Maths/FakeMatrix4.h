#pragma once

#include <FakePch.h>
#include "Engine/Core/Maths/FakeMathFunctions.h"
#include "Engine/Core/Maths/FakeVector4.h"
#include "Engine/Core/Maths/FakeMatrix2.h"
#include "Engine/Core/Maths/FakeMatrix3.h"

// TODO für nächsten Stream:
// - Multiplication von allen Matrizen
// - Quaternionen
// - EulerAngles

template<typename T>
class FakeMatrix4
	{
	private:
		T Elements[16];

	public:
		FakeMatrix4()
			{
			Elements[0 + 0 * 4] = static_cast<T>(0);
			Elements[1 + 0 * 4] = static_cast<T>(0);
			Elements[2 + 0 * 4] = static_cast<T>(0);
			Elements[3 + 0 * 4] = static_cast<T>(0);

			Elements[1 + 1 * 4] = static_cast<T>(0);
			Elements[2 + 1 * 4] = static_cast<T>(0);
			Elements[3 + 1 * 4] = static_cast<T>(0);
			Elements[4 + 1 * 4] = static_cast<T>(0);

			Elements[0 + 2 * 4] = static_cast<T>(0);
			Elements[1 + 2 * 4] = static_cast<T>(0);
			Elements[2 + 2 * 4] = static_cast<T>(0);
			Elements[3 + 2 * 4] = static_cast<T>(0);

			Elements[0 + 3 * 4] = static_cast<T>(0);
			Elements[1 + 3 * 4] = static_cast<T>(0);
			Elements[2 + 3 * 4] = static_cast<T>(0);
			Elements[3 + 3 * 4] = static_cast<T>(0);
			}

		FakeMatrix4(T value)
			{
			Elements[0 + 0 * 4] = value;
			Elements[1 + 0 * 4] = static_cast<T>(0);
			Elements[2 + 0 * 4] = static_cast<T>(0);
			Elements[3 + 0 * 4] = static_cast<T>(0);

			Elements[0 + 1 * 4] = static_cast<T>(0);
			Elements[1 + 1 * 4] = value;
			Elements[2 + 1 * 4] = static_cast<T>(0);
			Elements[3 + 1 * 4] = static_cast<T>(0);

			Elements[0 + 2 * 4] = static_cast<T>(0);
			Elements[1 + 2 * 4] = static_cast<T>(0);
			Elements[2 + 2 * 4] = value;
			Elements[3 + 2 * 4] = static_cast<T>(0);

			Elements[0 + 3 * 4] = static_cast<T>(0);
			Elements[1 + 3 * 4] = static_cast<T>(0);
			Elements[2 + 3 * 4] = static_cast<T>(0);
			Elements[3 + 3 * 4] = value;
			}

		FakeMatrix4(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33)
			{
			Elements[0 + 0 * 4] = m00;
			Elements[1 + 0 * 4] = m01;
			Elements[2 + 0 * 4] = m02;
			Elements[3 + 0 * 4] = m03;

			Elements[0 + 1 * 4] = m10;
			Elements[1 + 1 * 4] = m11;
			Elements[2 + 1 * 4] = m12;
			Elements[3 + 1 * 4] = m13;

			Elements[0 + 2 * 4] = m20;
			Elements[1 + 2 * 4] = m21;
			Elements[2 + 2 * 4] = m22;
			Elements[3 + 2 * 4] = m23;

			Elements[0 + 3 * 4] = m30;
			Elements[1 + 3 * 4] = m31;
			Elements[2 + 3 * 4] = m32;
			Elements[3 + 3 * 4] = m33;
			}

		FakeMatrix4(const FakeVector4<T> &a, const FakeVector4<T> &b, const FakeVector4<T> &c, const FakeVector4<T> &d)
			{
			Elements[0 + 0 * 4] = a.x;
			Elements[1 + 0 * 4] = a.y;
			Elements[2 + 0 * 4] = a.z;
			Elements[3 + 0 * 4] = a.w;

			Elements[0 + 1 * 4] = b.x;
			Elements[1 + 1 * 4] = b.y;
			Elements[2 + 1 * 4] = b.z;
			Elements[3 + 1 * 4] = b.w;

			Elements[0 + 2 * 4] = c.x;
			Elements[1 + 2 * 4] = c.y;
			Elements[2 + 2 * 4] = c.z;
			Elements[3 + 2 * 4] = c.w;

			Elements[0 + 3 * 4] = d.x;
			Elements[1 + 3 * 4] = d.y;
			Elements[2 + 3 * 4] = d.z;
			Elements[3 + 3 * 4] = d.w;
			}

		FakeMatrix4(const FakeMatrix2<T> &other)
			{
			Elements[0 + 0 * 4] = other[0 + 0 * 2];
			Elements[1 + 0 * 4] = other[1 + 0 * 2];
			Elements[2 + 0 * 4] = static_cast<T>(0);
			Elements[3 + 0 * 4] = static_cast<T>(0);

			Elements[0 + 1 * 4] = other[0 + 1 * 2];
			Elements[1 + 1 * 4] = other[1 + 1 * 2];
			Elements[2 + 1 * 4] = static_cast<T>(0);
			Elements[3 + 1 * 4] = static_cast<T>(0);

			Elements[0 + 2 * 4] = static_cast<T>(0);
			Elements[1 + 2 * 4] = static_cast<T>(0);
			Elements[2 + 2 * 4] = static_cast<T>(0);
			Elements[3 + 2 * 4] = static_cast<T>(0);

			Elements[0 + 3 * 4] = static_cast<T>(0);
			Elements[1 + 3 * 4] = static_cast<T>(0);
			Elements[2 + 3 * 4] = static_cast<T>(0);
			Elements[3 + 3 * 4] = static_cast<T>(0);
			}

		FakeMatrix4(const FakeMatrix3<T> &other)
			{
			Elements[0 + 0 * 4] = other[0 + 0 * 3];
			Elements[1 + 0 * 4] = other[1 + 0 * 3];
			Elements[2 + 0 * 4] = other[2 + 0 * 3];
			Elements[3 + 0 * 4] = static_cast<T>(0);

			Elements[0 + 1 * 4] = other[0 + 1 * 3];
			Elements[1 + 1 * 4] = other[1 + 1 * 3];
			Elements[2 + 1 * 4] = other[2 + 1 * 3];
			Elements[3 + 1 * 4] = static_cast<T>(0);

			Elements[0 + 2 * 4] = other[0 + 2 * 3];
			Elements[1 + 2 * 4] = other[1 + 2 * 3];
			Elements[2 + 2 * 4] = other[2 + 2 * 3];
			Elements[3 + 2 * 4] = static_cast<T>(0);

			Elements[0 + 3 * 4] = static_cast<T>(0);
			Elements[1 + 3 * 4] = static_cast<T>(0);
			Elements[2 + 3 * 4] = static_cast<T>(0);
			Elements[3 + 3 * 4] = static_cast<T>(0);
			}

		FakeMatrix4(const FakeMatrix4<T>&) = default;
		FakeMatrix4<T> &operator=(const FakeMatrix4<T>&) = default;

		FakeMatrix4<T> &Add(const FakeMatrix4<T> &other)
			{
			Elements[0 + 0 * 4] += other[0 + 0 * 4];
			Elements[1 + 0 * 4] += other[1 + 0 * 4];
			Elements[2 + 0 * 4] += other[2 + 0 * 4];
			Elements[3 + 0 * 4] += other[3 + 0 * 4];

			Elements[0 + 1 * 4] += other[0 + 1 * 4];
			Elements[1 + 1 * 4] += other[1 + 1 * 4];
			Elements[2 + 1 * 4] += other[2 + 1 * 4];
			Elements[3 + 1 * 4] += other[3 + 1 * 4];

			Elements[0 + 2 * 4] += other[0 + 2 * 4];
			Elements[1 + 2 * 4] += other[1 + 2 * 4];
			Elements[2 + 2 * 4] += other[2 + 2 * 4];
			Elements[3 + 2 * 4] += other[3 + 2 * 4];

			Elements[0 + 3 * 4] += other[0 + 3 * 4];
			Elements[1 + 3 * 4] += other[1 + 3 * 4];
			Elements[2 + 3 * 4] += other[2 + 3 * 4];
			Elements[3 + 3 * 4] += other[3 + 3 * 4];

			return *this;
			}

		FakeMatrix4<T> &AddScalar(T value)
			{
			Elements[0 + 0 * 4] += value;
			Elements[1 + 0 * 4] += value;
			Elements[2 + 0 * 4] += value;
			Elements[3 + 0 * 4] += value;

			Elements[0 + 1 * 4] += value;
			Elements[1 + 1 * 4] += value;
			Elements[2 + 1 * 4] += value;
			Elements[3 + 1 * 4] += value;

			Elements[0 + 2 * 4] += value;
			Elements[1 + 2 * 4] += value;
			Elements[2 + 2 * 4] += value;
			Elements[3 + 2 * 4] += value;

			Elements[0 + 3 * 4] += value;
			Elements[1 + 3 * 4] += value;
			Elements[2 + 3 * 4] += value;
			Elements[3 + 3 * 4] += value;

			return *this;
			}

		FakeMatrix4<T> &Subtract(const FakeMatrix4<T> &other)
			{
			Elements[0 + 0 * 4] -= other[0 + 0 * 4];
			Elements[1 + 0 * 4] -= other[1 + 0 * 4];
			Elements[2 + 0 * 4] -= other[2 + 0 * 4];
			Elements[3 + 0 * 4] -= other[3 + 0 * 4];

			Elements[0 + 1 * 4] -= other[0 + 1 * 4];
			Elements[1 + 1 * 4] -= other[1 + 1 * 4];
			Elements[2 + 1 * 4] -= other[2 + 1 * 4];
			Elements[3 + 1 * 4] -= other[3 + 1 * 4];

			Elements[0 + 2 * 4] -= other[0 + 2 * 4];
			Elements[1 + 2 * 4] -= other[1 + 2 * 4];
			Elements[2 + 2 * 4] -= other[2 + 2 * 4];
			Elements[3 + 2 * 4] -= other[3 + 2 * 4];

			Elements[0 + 3 * 4] -= other[0 + 3 * 4];
			Elements[1 + 3 * 4] -= other[1 + 3 * 4];
			Elements[2 + 3 * 4] -= other[2 + 3 * 4];
			Elements[3 + 3 * 4] -= other[3 + 3 * 4];

			return *this;
			}

		FakeMatrix4<T> &SubtractScalar(T value)
			{
			Elements[0 + 0 * 4] -= value;
			Elements[1 + 0 * 4] -= value;
			Elements[2 + 0 * 4] -= value;
			Elements[3 + 0 * 4] -= value;

			Elements[0 + 1 * 4] -= value;
			Elements[1 + 1 * 4] -= value;
			Elements[2 + 1 * 4] -= value;
			Elements[3 + 1 * 4] -= value;

			Elements[0 + 2 * 4] -= value;
			Elements[1 + 2 * 4] -= value;
			Elements[2 + 2 * 4] -= value;
			Elements[3 + 2 * 4] -= value;

			Elements[0 + 3 * 4] -= value;
			Elements[1 + 3 * 4] -= value;
			Elements[2 + 3 * 4] -= value;
			Elements[3 + 3 * 4] -= value;

			return *this;
			}

		FakeMatrix4<T> &Multiply(const FakeMatrix4<T> &other)
			{
			int32_t x, y, i;
			T sum;
			T data[16];

			for (y = 0; y < 4; ++y)
				{
				for (x = 0; x < 4; ++x)
					{
					sum = static_cast<T>(0);

					for (i = 0; i < 4; ++i)
						{
						sum += Elements[x + i * 4] * other[i + y * 4];
						}

					data[x + y * 4] = sum;
					}
				}

			memcpy(Elements, data, 16 * sizeof(T));
			return *this;
			}

		FakeMatrix4<T> &MultiplyScalar(T value)
			{
			// TODO
			return *this;
			}

		static FakeMatrix4<T> Identity()
			{
			return FakeMatrix4<T>(1);
			}

		static FakeMatrix4<T> Transpose(const FakeMatrix4<T> &other)
			{
			FakeMatrix4<T> result;
			result[0 + 0 * 4] = other[0 + 0 * 4];
			result[0 + 1 * 4] = other[1 + 0 * 4];
			result[0 + 2 * 4] = other[2 + 0 * 4];
			result[0 + 3 * 4] = other[3 + 0 * 4];

			result[1 + 0 * 4] = other[0 + 1 * 4];
			result[1 + 1 * 4] = other[1 + 1 * 4];
			result[1 + 2 * 4] = other[2 + 1 * 4];
			result[1 + 3 * 4] = other[3 + 1 * 4];

			result[2 + 0 * 4] = other[0 + 2 * 4];
			result[2 + 1 * 4] = other[1 + 2 * 4];
			result[2 + 2 * 4] = other[2 + 2 * 4];
			result[2 + 3 * 4] = other[3 + 2 * 4];

			result[3 + 0 * 4] = other[0 + 3 * 4];
			result[3 + 1 * 4] = other[1 + 3 * 4];
			result[3 + 2 * 4] = other[2 + 3 * 4];
			result[3 + 3 * 4] = other[3 + 3 * 4];
			return result;
			}

		static T Determinant(const FakeMatrix4<T> &other)
			{
			T subFactor00 = other[2 + 2 * 4] * other[3 + 3 * 4] - other[3 + 2 * 4] * other[2 + 3 * 4];
			T subFactor01 = other[2 + 1 * 4] * other[3 + 3 * 4] - other[3 + 1 * 4] * other[2 + 3 * 4];
			T subFactor02 = other[2 + 1 * 4] * other[3 + 2 * 4] - other[3 + 1 * 4] * other[2 + 2 * 4];
			T subFactor03 = other[2 + 0 * 4] * other[3 + 3 * 4] - other[3 + 0 * 4] * other[2 + 3 * 4];
			T subFactor04 = other[2 + 0 * 4] * other[3 + 2 * 4] - other[3 + 0 * 4] * other[2 + 2 * 4];
			T subFactor05 = other[2 + 0 * 4] * other[3 + 1 * 4] - other[3 + 0 * 4] * other[2 + 1 * 4];

			FakeVector4<T> detCof(
				+(other[1 + 1 * 4] * subFactor00 - other[1 + 2 * 4] * subFactor01 + other[1 + 3 * 4] * subFactor02),
				-(other[1 + 0 * 4] * subFactor00 - other[1 + 2 * 4] * subFactor03 + other[1 + 3 * 4] * subFactor04),
				+(other[1 + 0 * 4] * subFactor01 - other[1 + 1 * 4] * subFactor03 + other[1 + 3 * 4] * subFactor05),
				-(other[1 + 0 * 4] * subFactor02 - other[1 + 1 * 4] * subFactor04 + other[1 + 2 * 4] * subFactor05));

			return
				other[0 + 0 * 4] * detCof[0] + other[0 + 1 * 4] * detCof[1] +
				other[0 + 2 * 4] * detCof[2] + other[0 + 3 * 4] * detCof[3];
			}

		static FakeMatrix4<T> Inverse(const FakeMatrix4<T> &other)
			{
			FakeMatrix4<T> result;
			T det;
			int i;

			result[0] = other[5] * other[10] * other[15] -
				other[5] * other[11] * other[14] -
				other[9] * other[6] * other[15] +
				other[9] * other[7] * other[14] +
				other[13] * other[6] * other[11] -
				other[13] * other[7] * other[10];

			result[4] = -other[4] * other[10] * other[15] +
				other[4] * other[11] * other[14] +
				other[8] * other[6] * other[15] -
				other[8] * other[7] * other[14] -
				other[12] * other[6] * other[11] +
				other[12] * other[7] * other[10];

			result[8] = other[4] * other[9] * other[15] -
				other[4] * other[11] * other[13] -
				other[8] * other[5] * other[15] +
				other[8] * other[7] * other[13] +
				other[12] * other[5] * other[11] -
				other[12] * other[7] * other[9];

			result[12] = -other[4] * other[9] * other[14] +
				other[4] * other[10] * other[13] +
				other[8] * other[5] * other[14] -
				other[8] * other[6] * other[13] -
				other[12] * other[5] * other[10] +
				other[12] * other[6] * other[9];

			result[1] = -other[1] * other[10] * other[15] +
				other[1] * other[11] * other[14] +
				other[9] * other[2] * other[15] -
				other[9] * other[3] * other[14] -
				other[13] * other[2] * other[11] +
				other[13] * other[3] * other[10];

			result[5] = other[0] * other[10] * other[15] -
				other[0] * other[11] * other[14] -
				other[8] * other[2] * other[15] +
				other[8] * other[3] * other[14] +
				other[12] * other[2] * other[11] -
				other[12] * other[3] * other[10];

			result[9] = -other[0] * other[9] * other[15] +
				other[0] * other[11] * other[13] +
				other[8] * other[1] * other[15] -
				other[8] * other[3] * other[13] -
				other[12] * other[1] * other[11] +
				other[12] * other[3] * other[9];

			result[13] = other[0] * other[9] * other[14] -
				other[0] * other[10] * other[13] -
				other[8] * other[1] * other[14] +
				other[8] * other[2] * other[13] +
				other[12] * other[1] * other[10] -
				other[12] * other[2] * other[9];

			result[2] = other[1] * other[6] * other[15] -
				other[1] * other[7] * other[14] -
				other[5] * other[2] * other[15] +
				other[5] * other[3] * other[14] +
				other[13] * other[2] * other[7] -
				other[13] * other[3] * other[6];

			result[6] = -other[0] * other[6] * other[15] +
				other[0] * other[7] * other[14] +
				other[4] * other[2] * other[15] -
				other[4] * other[3] * other[14] -
				other[12] * other[2] * other[7] +
				other[12] * other[3] * other[6];

			result[10] = other[0] * other[5] * other[15] -
				other[0] * other[7] * other[13] -
				other[4] * other[1] * other[15] +
				other[4] * other[3] * other[13] +
				other[12] * other[1] * other[7] -
				other[12] * other[3] * other[5];

			result[14] = -other[0] * other[5] * other[14] +
				other[0] * other[6] * other[13] +
				other[4] * other[1] * other[14] -
				other[4] * other[2] * other[13] -
				other[12] * other[1] * other[6] +
				other[12] * other[2] * other[5];

			result[3] = -other[1] * other[6] * other[11] +
				other[1] * other[7] * other[10] +
				other[5] * other[2] * other[11] -
				other[5] * other[3] * other[10] -
				other[9] * other[2] * other[7] +
				other[9] * other[3] * other[6];

			result[7] = other[0] * other[6] * other[11] -
				other[0] * other[7] * other[10] -
				other[4] * other[2] * other[11] +
				other[4] * other[3] * other[10] +
				other[8] * other[2] * other[7] -
				other[8] * other[3] * other[6];

			result[11] = -other[0] * other[5] * other[11] +
				other[0] * other[7] * other[9] +
				other[4] * other[1] * other[11] -
				other[4] * other[3] * other[9] -
				other[8] * other[1] * other[7] +
				other[8] * other[3] * other[5];

			result[15] = other[0] * other[5] * other[10] -
				other[0] * other[6] * other[9] -
				other[4] * other[1] * other[10] +
				other[4] * other[2] * other[9] +
				other[8] * other[1] * other[6] -
				other[8] * other[2] * other[5];

			det = other[0] * result[0] + other[1] * result[4] + other[2] * result[8] + other[3] * result[12];

			if (0 == det)
				{
				FAKE_ASSERT(false, "Ich habe wirklich versucht die Inverse zu berechnen ... aber an deiner Dummheit kann ich leider nichts machen.. bin ja kein Zauberer :-)");
				}

			if (static_cast<T>(1) == det || static_cast<T>(-1) == det)
				{
				return Transpose(other);
				}

			det = static_cast<T>(1) / det;

			for (i = 0; i < 16; i++)
				result[i] = result[i] * det;

			return result;
			}

		static FakeMatrix4<T> Ortho(T left, T right, T bottom, T top, T zNear, T zFar)
			{
			FakeMatrix4<T> result(1);
			result[0 + 0 * 4] = static_cast<T>(2) / (right - left);
			result[1 + 1 * 4] = static_cast<T>(2) / (top - bottom);
			result[2 + 2 * 4] = static_cast<T>(-2) / (zFar - zNear);

			result[3 + 0 * 4] = -(right + left) / (right - left);
			result[3 + 1 * 4] = -(top + bottom) / (top - bottom);
			result[3 + 2 * 4] = -(zFar + zNear) / (zFar - zNear);
			return result;
			}

		static FakeMatrix4<T> Perspective(T fov, T aspectRatio, T zNear, T zFar)
			{
			T q = static_cast<T>(1) / static_cast<T>(tan(fake_radians(0.5 * fov)));
			T a = q / aspectRatio;
			T b = (zNear + zFar) / (zNear - zFar);
			T c = (static_cast<T>(2) * zNear * zFar) / (zNear - zFar);

			FakeMatrix4<T> result(1);
			result[0 + 0 * 4] = a;
			result[1 + 1 * 4] = q;
			result[2 + 2 * 4] = b;
			result[3 + 2 * 4] = static_cast<T>(-1);
			result[2 + 3 * 4] = c;
			result[3 + 3 * 4] = static_cast<T>(0);
			return result;
			}

		static FakeMatrix4<T> PerspectiveFOV(T fov, T width, T height, T zNear, T zFar)
			{
			FAKE_ASSERT(width > static_cast<T>(0), "Width is less than 0!");
			FAKE_ASSERT(height > static_cast<T>(0), "Height is less than 0!");
			FAKE_ASSERT(fov > static_cast<T>(0), "FOV is less than 0!");

			T const rad = fov;
			T const h = cos(static_cast<T>(0.5) * rad) / sin(static_cast<T>(0.5) * rad);
			T const w = h * height / width;

			FakeMatrix4<T> result;
			result[0 + 0 * 4] = w;
			result[1 + 1 * 4] = h;
			result[2 + 2 * 4] = (zFar + zNear) / (zFar - zNear);
			result[2 + 3 * 4] = static_cast<T>(1);
			result[3 + 2 * 4] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
			return result;
			}

		static FakeMatrix4<T> Translate(const FakeVector3<T> &translation)
			{
			FakeMatrix4<T> result(1);
			result[3] = result[0] * translation[0] + result[1] * translation[1] + result[2] * translation[2] + result[3];
			return result;
			}

		static FakeMatrix4<T> Scale(const FakeVector3<T> &scale)
			{
			FakeMatrix4<T> result(1);
			result[0 + 0 * 4] = scale.x;
			result[1 + 1 * 4] = scale.y;
			result[2 + 2 * 4] = scale.z;
			return result;
			}

		static FakeMatrix4<T> Rotate(T radians, const FakeVector3<T> &axis)
			{
			T c = cos(radians);
			T s = sin(radians);
			T oneOverCos = static_cast<T>(1) - c;

			T x = axis.x;
			T y = axis.y;
			T z = axis.z;

			FakeMatrix4<T> result(1);
			result[0 + 0 * 4] = x * oneOverCos + c;
			result[1 + 0 * 4] = y * x * oneOverCos + z * s;
			result[2 + 0 * 4] = x * z * oneOverCos - y * s;

			result[0 + 1 * 4] = x * y * oneOverCos - z * s;
			result[1 + 1 * 4] = y * oneOverCos + c;
			result[2 + 1 * 4] = y * z * oneOverCos + x * s;

			result[0 + 2 * 4] = x * z * oneOverCos + y * s;
			result[1 + 2 * 4] = y * z * oneOverCos - x * s;
			result[2 + 2 * 4] = z * oneOverCos + c;
			return result;
			}

		static FakeMatrix4<T> LookAt(const FakeVector3<T> &camera, const FakeVector3<T> &object, const FakeVector3<T> &up)
			{
			FakeVector3<T> f = (object - camera).Normalize();
			FakeVector3<T> s = f.Cross(up.Normalize());
			FakeVector3<T> u = s.Cross(f);

			FakeMatrix4<T> result(1);
			result[0 + 0 * 4] = s.x;
			result[0 + 1 * 4] = s.y;
			result[0 + 2 * 4] = s.z;

			result[1 + 0 * 4] = u.x;
			result[1 + 1 * 4] = u.y;
			result[1 + 2 * 4] = u.z;

			result[2 + 0 * 4] = -f.x;
			result[2 + 1 * 4] = -f.y;
			result[2 + 2 * 4] = -f.z;
			return result * Translate(FakeVector3<T>(-camera.x, -camera.y, -camera.z));
			}

		friend FakeMatrix4<T> operator-(const FakeMatrix4<T> &other)
			{
			FakeMatrix4<T> result(
				-other[0 + 0 * 4],
				-other[1 + 0 * 4],
				-other[2 + 0 * 4],
				-other[3 + 0 * 4],
				-other[0 + 1 * 4],
				-other[1 + 1 * 4],
				-other[2 + 1 * 4],
				-other[3 + 1 * 4],
				-other[0 + 2 * 4],
				-other[1 + 2 * 4],
				-other[2 + 2 * 4],
				-other[3 + 2 * 4],
				-other[0 + 3 * 4],
				-other[1 + 3 * 4],
				-other[2 + 3 * 4],
				-other[3 + 3 * 4]);
			return result;
			}

		friend FakeMatrix4<T> operator+(FakeMatrix4<T> left, const FakeMatrix4<T> &right)
			{
			return left.Add(right);
			}

		friend FakeMatrix4<T> operator-(FakeMatrix4<T> left, const FakeMatrix4<T> &right)
			{
			return left.Subtract(right);
			}

		friend FakeMatrix4<T> operator*(FakeMatrix4<T> left, const FakeMatrix4<T> &right)
			{
			return left.Multiply(right);
			}

		friend FakeMatrix4<T> operator+(FakeMatrix4<T> left, T value)
			{
			return left.AddScalar(value);
			}

		friend FakeMatrix4<T> operator-(FakeMatrix4<T> left, T value)
			{
			return left.SubtractScalar(value);
			}

		friend FakeMatrix4<T> operator*(FakeMatrix4<T> left, T value)
			{
			return left.MultiplyScalar(value);
			}

		FakeMatrix4<T> &operator+=(const FakeMatrix4<T> &other)
			{
			return Add(other);
			}

		FakeMatrix4<T> &operator-=(const FakeMatrix4<T> &other)
			{
			return Subtract(other);
			}

		FakeMatrix4<T> &operator*=(const FakeMatrix4<T> &other)
			{
			return Multiply(other);
			}

		FakeMatrix4<T> &operator+=(T value)
			{
			return AddScalar(value);
			}

		FakeMatrix4<T> &operator-=(T value)
			{
			return SubtractScalar(value);
			}

		FakeMatrix4<T> &operator*=(T value)
			{
			return MultiplyScalar(value);
			}

		FakeMatrix3<T> operator++()
			{
			++Elements[0 + 0 * 4];
			++Elements[1 + 0 * 4];
			++Elements[2 + 0 * 4];
			++Elements[3 + 0 * 4];
			++Elements[0 + 1 * 4];
			++Elements[1 + 1 * 4];
			++Elements[2 + 1 * 4];
			++Elements[3 + 1 * 4];
			++Elements[0 + 2 * 4];
			++Elements[1 + 2 * 4];
			++Elements[2 + 2 * 4];
			++Elements[3 + 2 * 4];
			++Elements[0 + 3 * 4];
			++Elements[1 + 3 * 4];
			++Elements[2 + 3 * 4];
			++Elements[3 + 3 * 4];
			return *this;
			}

		FakeMatrix3<T> operator--()
			{
			--Elements[0 + 0 * 4];
			--Elements[1 + 0 * 4];
			--Elements[2 + 0 * 4];
			--Elements[3 + 0 * 4];
			--Elements[0 + 1 * 4];
			--Elements[1 + 1 * 4];
			--Elements[2 + 1 * 4];
			--Elements[3 + 1 * 4];
			--Elements[0 + 2 * 4];
			--Elements[1 + 2 * 4];
			--Elements[2 + 2 * 4];
			--Elements[3 + 2 * 4];
			--Elements[0 + 3 * 4];
			--Elements[1 + 3 * 4];
			--Elements[2 + 3 * 4];
			--Elements[3 + 3 * 4];
			return *this;
			}

		bool operator==(const FakeMatrix4<T> &other)
			{
			if (Elements[0 + 0 * 4] == other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] == other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] == other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] == other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] == other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] == other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] == other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] == other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] == other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] == other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] == other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] == other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] == other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] == other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] == other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] == other[3 + 3 * 4])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator==(const FakeMatrix4<T> &other) const
			{
			if (Elements[0 + 0 * 4] == other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] == other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] == other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] == other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] == other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] == other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] == other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] == other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] == other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] == other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] == other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] == other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] == other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] == other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] == other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] == other[3 + 3 * 4])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator!=(const FakeMatrix4<T> &other)
			{
			return !(*this == other);
			}

		bool operator!=(const FakeMatrix4<T> &other) const
			{
			return !(*this == other);
			}

		bool operator<(const FakeMatrix4<T> &other)
			{
			if (Elements[0 + 0 * 4] < other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] < other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] < other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] < other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] < other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] < other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] < other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] < other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] < other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] < other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] < other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] < other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] < other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] < other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] < other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] < other[3 + 3 * 4])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator<(const FakeMatrix4<T> &other) const
			{
			if (Elements[0 + 0 * 4] < other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] < other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] < other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] < other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] < other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] < other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] < other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] < other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] < other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] < other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] < other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] < other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] < other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] < other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] < other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] < other[3 + 3 * 4])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>(const FakeMatrix4<T> &other)
			{
			if (Elements[0 + 0 * 4] > other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] > other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] > other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] > other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] > other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] > other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] > other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] > other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] > other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] > other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] > other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] > other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] > other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] > other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] > other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] > other[3 + 3 * 4])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>(const FakeMatrix4<T> &other) const
			{
			if (Elements[0 + 0 * 4] > other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] > other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] > other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] > other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] > other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] > other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] > other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] > other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] > other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] > other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] > other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] > other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] > other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] > other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] > other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] > other[3 + 3 * 4])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator<=(const FakeMatrix4<T> &other)
			{
			if (Elements[0 + 0 * 4] <= other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] <= other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] <= other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] <= other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] <= other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] <= other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] <= other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] <= other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] <= other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] <= other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] <= other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] <= other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] <= other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] <= other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] <= other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] <= other[3 + 3 * 4])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator<=(const FakeMatrix4<T> &other) const
			{
			if (Elements[0 + 0 * 4] <= other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] <= other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] <= other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] <= other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] <= other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] <= other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] <= other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] <= other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] <= other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] <= other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] <= other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] <= other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] <= other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] <= other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] <= other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] <= other[3 + 3 * 4])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>=(const FakeMatrix4<T> &other)
			{
			if (Elements[0 + 0 * 4] >= other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] >= other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] >= other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] >= other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] >= other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] >= other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] >= other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] >= other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] >= other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] >= other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] >= other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] >= other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] >= other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] >= other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] >= other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] >= other[3 + 3 * 4])
				{
				return true;
				}
			else
				{
				return false;
				}
			}

		bool operator>=(const FakeMatrix4<T> &other) const
			{
			if (Elements[0 + 0 * 4] >= other[0 + 0 * 4]
			 && Elements[1 + 0 * 4] >= other[1 + 0 * 4]
			 && Elements[2 + 0 * 4] >= other[2 + 0 * 4]
			 && Elements[3 + 0 * 4] >= other[3 + 0 * 4]
			 && Elements[0 + 1 * 4] >= other[0 + 1 * 4]
			 && Elements[1 + 1 * 4] >= other[1 + 1 * 4]
			 && Elements[2 + 1 * 4] >= other[2 + 1 * 4]
			 && Elements[3 + 1 * 4] >= other[3 + 1 * 4]
			 && Elements[0 + 2 * 4] >= other[0 + 2 * 4]
			 && Elements[1 + 2 * 4] >= other[1 + 2 * 4]
			 && Elements[2 + 2 * 4] >= other[2 + 2 * 4]
			 && Elements[3 + 2 * 4] >= other[3 + 2 * 4]
			 && Elements[0 + 3 * 4] >= other[0 + 3 * 4]
			 && Elements[1 + 3 * 4] >= other[1 + 3 * 4]
			 && Elements[2 + 3 * 4] >= other[2 + 3 * 4]
			 && Elements[3 + 3 * 4] >= other[3 + 3 * 4])
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
			FAKE_ASSERT(i < 16, "Index out of bounds");
			return Elements[i];
			}

		const T &operator[](uint32_t i) const
			{
			FAKE_ASSERT(i < 16, "Index out of bounds");
			return Elements[i];
			}

		friend std::ostream &operator<<(std::ostream &stream, const FakeMatrix4<T> &other)
			{
			stream << other[0 + 0 * 4] << ", " << other[1 + 0 * 4] << ", " << other[2 + 0 * 4] << ", " << other[3 + 0 * 4] << ", " << std::endl;
			stream << other[0 + 1 * 4] << ", " << other[1 + 1 * 4] << ", " << other[2 + 1 * 4] << ", " << other[3 + 1 * 4] << ", " << std::endl;
			stream << other[0 + 2 * 4] << ", " << other[1 + 2 * 4] << ", " << other[2 + 2 * 4] << ", " << other[3 + 2 * 4] << ", " << std::endl;
			stream << other[0 + 3 * 4] << ", " << other[1 + 3 * 4] << ", " << other[2 + 3 * 4] << ", " << other[3 + 3 * 4] << std::endl;
			return stream;
			}
	};

typedef FakeMatrix4<int> FakeMat4i;
typedef FakeMatrix4<double> FakeMat4d;
typedef FakeMatrix4<float> FakeMat4f;
typedef FakeMatrix4<short> FakeMat4s;
typedef FakeMatrix4<long> FakeMat4l;
typedef FakeMatrix4<bool> FakeMat4b;
