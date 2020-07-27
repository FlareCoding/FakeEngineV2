#pragma once

#include <memory>
#include <iostream>

#include "Engine/Core/Defines/FakeConsole.h"
#include "Engine/Core/Defines/FakeMouseButtonCodes.h"
#include "Engine/Core/Defines/FakeKeyCodes.h"

#define MAX(A, B) ( ((A)  > (B)) ? (A) :  (B) )
#define MIN(A, B) ( ((A)  < (B)) ? (A) :  (B) )
#define ABS(A)	  ( ((A)  >= 0 ) ? (A) : -(A) )
#define BIT(x) (1 << x)

#define FAKE_BIND_EVENT_FUNCTION(fn) std::bind(&fn, this, std::placeholders::_1)

#define FAKE_VERTEX_SHADER 0x8B31
#define FAKE_FRAGMENT_SHADER 0x8B30

using byte = unsigned char;
using RendererID = uint32_t;
typedef float f32;
typedef double f64;

template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
	{
	return std::make_unique<T>(std::forward<Args>(args)...);
	}

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
	{
	return std::make_shared<T>(std::forward<Args>(args)...);
	}
