#pragma once

#include "FakePch.h"

typedef enum class MouseButtonCodes : uint16_t
	{
	BUTTON_1 = 0,
	BUTTON_2 = 1,
	BUTTON_3 = 2,
	BUTTON_4 = 3,
	BUTTON_5 = 4,
	BUTTON_6 = 5,
	BUTTON_7 = 6,
	BUTTON_8 = 7,
	BUTTON_LAST = 7,
	BUTTON_LEFT = 0,
	BUTTON_RIGHT = 1,
	BUTTON_MIDDLE = 2
	} Mouse;

inline std::ostream &operator<<(std::ostream &stream, MouseButtonCodes code)
	{
	return stream << static_cast<int32_t>(code);
	}

#define FAKE_MOUSE_BUTTON_1 ::Mouse::BUTTON_1
#define FAKE_MOUSE_BUTTON_2 ::Mouse::BUTTON_2
#define FAKE_MOUSE_BUTTON_3 ::Mouse::BUTTON_3
#define FAKE_MOUSE_BUTTON_4 ::Mouse::BUTTON_4
#define FAKE_MOUSE_BUTTON_5 ::Mouse::BUTTON_5
#define FAKE_MOUSE_BUTTON_6 ::Mouse::BUTTON_6
#define FAKE_MOUSE_BUTTON_7 ::Mouse::BUTTON_7
#define FAKE_MOUSE_BUTTON_8 ::Mouse::BUTTON_8
#define FAKE_MOUSE_BUTTON_LAST ::Mouse::BUTTON_LAST
#define FAKE_MOUSE_BUTTON_LEFT ::Mouse::BUTTON_LEFT
#define FAKE_MOUSE_BUTTON_RIGHT ::Mouse::BUTTON_RIGHT
#define FAKE_MOUSE_BUTTON_MIDDLE ::Mouse::BUTTON_MIDDLE