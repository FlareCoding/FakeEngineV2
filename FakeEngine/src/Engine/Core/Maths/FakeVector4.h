#pragma once

#include "FakeMathFunctions.h"
#include "FakeVector3.h"

template<typename T>
struct FakeVector4
	{
	T x, y, z, w;


	};

typedef FakeVector4<int> FakeVec4i;
typedef FakeVector4<double> FakeVec4d;
typedef FakeVector4<float> FakeVec4f;
typedef FakeVector4<short> FakeVec4s;
typedef FakeVector4<long> FakeVec4l;
typedef FakeVector4<bool> FakeVec4b;