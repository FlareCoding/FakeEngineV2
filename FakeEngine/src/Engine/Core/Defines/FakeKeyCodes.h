#pragma once

#include "FakePch.h"

typedef enum class KeyCode : uint16_t
	{
	/* Printable keys */
	SPACE = 32,
	APOSTROPHE = 39,  /* ' */
	COMMA = 44,  /* , */
	MINUS = 45,  /* - */
	PERIOD = 46,  /* . */
	SLASH = 47,  /* / */
	SEMICOLON = 59,  /* ; */
	EQUAL = 61,  /* = */
	LEFT_BRACKET = 91,  /* [ */
	BACKSLASH = 92,  /* \ */
	RIGHT_BRACKET = 93,  /* ] */
	GRAVE_ACCENT = 96,  /* ` */
	WORLD_1 = 161, /* non-US #1 */
	WORLD_2 = 162, /* non-US #2 */

	K_0 = 48,
	K_1 = 49,
	K_2 = 50,
	K_3 = 51,
	K_4 = 52,
	K_5 = 53,
	K_6 = 54,
	K_7 = 55,
	K_8 = 56,
	K_9 = 57,

	A = 65,
	B = 66,
	C = 67,
	D = 68,
	E = 69,
	F = 70,
	G = 71,
	H = 72,
	I = 73,
	J = 74,
	K = 75,
	L = 76,
	M = 77,
	N = 78,
	O = 79,
	P = 80,
	Q = 81,
	R = 82,
	S = 83,
	T = 84,
	U = 85,
	V = 86,
	W = 87,
	X = 88,
	Y = 89,
	Z = 90,

	/* Function keys */
	ESCAPE = 256,
	ENTER = 257,
	TAB = 258,
	BACKSPACE = 259,
	INSERT = 260,
	KEY_DELETE = 261,
	RIGHT = 262,
	LEFT = 263,
	DOWN = 264,
	UP = 265,
	PAGE_UP = 266,
	PAGE_DOWN = 267,
	HOME = 268,
	END = 269,
	CAPS_LOCK = 280,
	SCROLL_LOCK = 281,
	NUM_LOCK = 282,
	PRINT_SCREEN = 283,
	PAUSE = 284,
	F1 = 290,
	F2 = 291,
	F3 = 292,
	F4 = 293,
	F5 = 294,
	F6 = 295,
	F7 = 296,
	F8 = 297,
	F9 = 298,
	F10 = 299,
	F11 = 300,
	F12 = 301,
	F13 = 302,
	F14 = 303,
	F15 = 304,
	F16 = 305,
	F17 = 306,
	F18 = 307,
	F19 = 308,
	F20 = 309,
	F21 = 310,
	F22 = 311,
	F23 = 312,
	F24 = 313,
	F25 = 314,

	KP_0 = 320,
	KP_1 = 321,
	KP_2 = 322,
	KP_3 = 323,
	KP_4 = 324,
	KP_5 = 325,
	KP_6 = 326,
	KP_7 = 327,
	KP_8 = 328,
	KP_9 = 329,
	KP_DECIMAL = 330,
	KP_DIVIDE = 331,
	KP_MULTIPLY = 332,
	KP_SUBTRACT = 333,
	KP_ADD = 334,
	KP_ENTER = 335,
	KP_EQUAL = 336,
	LEFT_SHIFT = 340,
	LEFT_CONTROL = 341,
	LEFT_ALT = 342,
	LEFT_SUPER = 343,
	RIGHT_SHIFT = 344,
	RIGHT_CONTROL = 345,
	RIGHT_ALT = 346,
	RIGHT_SUPER = 347,
	MENU = 348
	} Key;

inline std::ostream &operator<<(std::ostream &stream, KeyCode code)
	{
	return stream << static_cast<int32_t>(code);
	}


/* Printable keys */
#define FAKE_KEY_SPACE              ::Key::SPACE
#define FAKE_KEY_APOSTROPHE         ::Key::APOSTROPHE   /* ' */
#define FAKE_KEY_COMMA              ::Key::COMMA		/* , */
#define FAKE_KEY_MINUS              ::Key::MINUS		/* - */
#define FAKE_KEY_PERIOD             ::Key::PERIOD       /* . */
#define FAKE_KEY_SLASH              ::Key::SLASH        /* / */
#define FAKE_KEY_0                  ::Key::K_0
#define FAKE_KEY_1                  ::Key::K_1
#define FAKE_KEY_2                  ::Key::K_2
#define FAKE_KEY_3                  ::Key::K_3
#define FAKE_KEY_4                  ::Key::K_4
#define FAKE_KEY_5                  ::Key::K_5
#define FAKE_KEY_6                  ::Key::K_6
#define FAKE_KEY_7                  ::Key::K_7
#define FAKE_KEY_8                  ::Key::K_8
#define FAKE_KEY_9                  ::Key::K_9
#define FAKE_KEY_SEMICOLON          ::Key::SEMICOLON     /* ; */
#define FAKE_KEY_EQUAL              ::Key::EQUAL         /* = */
#define FAKE_KEY_A                  ::Key::A
#define FAKE_KEY_B                  ::Key::B
#define FAKE_KEY_C                  ::Key::C
#define FAKE_KEY_D                  ::Key::D
#define FAKE_KEY_E                  ::Key::E
#define FAKE_KEY_F                  ::Key::F
#define FAKE_KEY_G                  ::Key::G
#define FAKE_KEY_H                  ::Key::H
#define FAKE_KEY_I                  ::Key::I
#define FAKE_KEY_J                  ::Key::J
#define FAKE_KEY_K                  ::Key::K
#define FAKE_KEY_L                  ::Key::L
#define FAKE_KEY_M                  ::Key::M
#define FAKE_KEY_N                  ::Key::N
#define FAKE_KEY_O                  ::Key::O
#define FAKE_KEY_P                  ::Key::P
#define FAKE_KEY_Q                  ::Key::Q
#define FAKE_KEY_R                  ::Key::R
#define FAKE_KEY_S                  ::Key::S
#define FAKE_KEY_T                  ::Key::T
#define FAKE_KEY_U                  ::Key::U
#define FAKE_KEY_V                  ::Key::V
#define FAKE_KEY_W                  ::Key::W
#define FAKE_KEY_X                  ::Key::X
#define FAKE_KEY_Y                  ::Key::Y
#define FAKE_KEY_Z                  ::Key::Z
#define FAKE_KEY_LEFT_BRACKET       ::Key::LEFT_BRACKET  /* [ */
#define FAKE_KEY_BACKSLASH          ::Key::BACKSLASH  /* \ */
#define FAKE_KEY_RIGHT_BRACKET      ::Key::RIGHT_BRACKET  /* ] */
#define FAKE_KEY_GRAVE_ACCENT       ::Key::GRAVE_ACCENT  /* ` */
#define FAKE_KEY_WORLD_1            ::Key::WORLD_1 /* non-US #1 */
#define FAKE_KEY_WORLD_2            ::Key::WORLD_2 /* non-US #2 */

/* Function keys */
#define FAKE_KEY_ESCAPE             ::Key::ESCAPE
#define FAKE_KEY_ENTER              ::Key::ENTER
#define FAKE_KEY_TAB                ::Key::TAB
#define FAKE_KEY_BACKSPACE          ::Key::BACKSPACE
#define FAKE_KEY_INSERT             ::Key::INSERT
#define FAKE_KEY_DELETE             ::Key::KEY_DELETE
#define FAKE_KEY_RIGHT              ::Key::RIGHT
#define FAKE_KEY_LEFT               ::Key::LEFT
#define FAKE_KEY_DOWN               ::Key::DOWN
#define FAKE_KEY_UP                 ::Key::UP
#define FAKE_KEY_PAGE_UP            ::Key::PAGE_UP
#define FAKE_KEY_PAGE_DOWN          ::Key::PAGE_DOWN
#define FAKE_KEY_HOME               ::Key::HOME
#define FAKE_KEY_END                ::Key::END
#define FAKE_KEY_CAPS_LOCK          ::Key::CAPS_LOCK
#define FAKE_KEY_SCROLL_LOCK        ::Key::SCROLL_LOCK
#define FAKE_KEY_NUM_LOCK           ::Key::NUM_LOCK
#define FAKE_KEY_PRINT_SCREEN       ::Key::PRINT_SCREEN
#define FAKE_KEY_PAUSE              ::Key::PAUSE
#define FAKE_KEY_F1                 ::Key::F1
#define FAKE_KEY_F2                 ::Key::F2
#define FAKE_KEY_F3                 ::Key::F3
#define FAKE_KEY_F4                 ::Key::F4
#define FAKE_KEY_F5                 ::Key::F5
#define FAKE_KEY_F6                 ::Key::F6
#define FAKE_KEY_F7                 ::Key::F7
#define FAKE_KEY_F8                 ::Key::F8
#define FAKE_KEY_F9                 ::Key::F9
#define FAKE_KEY_F10                ::Key::F10
#define FAKE_KEY_F11                ::Key::F11
#define FAKE_KEY_F12                ::Key::F12
#define FAKE_KEY_F13                ::Key::F13
#define FAKE_KEY_F14                ::Key::F14
#define FAKE_KEY_F15                ::Key::F15
#define FAKE_KEY_F16                ::Key::F16
#define FAKE_KEY_F17                ::Key::F17
#define FAKE_KEY_F18                ::Key::F18
#define FAKE_KEY_F19                ::Key::F19
#define FAKE_KEY_F20                ::Key::F20
#define FAKE_KEY_F21                ::Key::F21
#define FAKE_KEY_F22                ::Key::F22
#define FAKE_KEY_F23                ::Key::F23
#define FAKE_KEY_F24                ::Key::F24
#define FAKE_KEY_F25                ::Key::F25
#define FAKE_KEY_KP_0               ::Key::KP_0
#define FAKE_KEY_KP_1               ::Key::KP_1
#define FAKE_KEY_KP_2               ::Key::KP_2
#define FAKE_KEY_KP_3               ::Key::KP_3
#define FAKE_KEY_KP_4               ::Key::KP_4
#define FAKE_KEY_KP_5               ::Key::KP_5
#define FAKE_KEY_KP_6               ::Key::KP_6
#define FAKE_KEY_KP_7               ::Key::KP_7
#define FAKE_KEY_KP_8               ::Key::KP_8
#define FAKE_KEY_KP_9               ::Key::KP_9
#define FAKE_KEY_KP_DECIMAL         ::Key::KP_DECIMAL
#define FAKE_KEY_KP_DIVIDE          ::Key::KP_DIVIDE
#define FAKE_KEY_KP_MULTIPLY        ::Key::KP_MULTIPLY
#define FAKE_KEY_KP_SUBTRACT        ::Key::KP_SUBTRACT
#define FAKE_KEY_KP_ADD             ::Key::KP_ADD
#define FAKE_KEY_KP_ENTER           ::Key::KP_ENTER
#define FAKE_KEY_KP_EQUAL           ::Key::KP_EQUAL
#define FAKE_KEY_LEFT_SHIFT         ::Key::LEFT_SHIFT
#define FAKE_KEY_LEFT_CONTROL       ::Key::LEFT_CONTROL
#define FAKE_KEY_LEFT_ALT           ::Key::LEFT_ALT
#define FAKE_KEY_LEFT_SUPER         ::Key::LEFT_SUPER
#define FAKE_KEY_RIGHT_SHIFT        ::Key::RIGHT_SHIFT
#define FAKE_KEY_RIGHT_CONTROL      ::Key::RIGHT_CONTROL
#define FAKE_KEY_RIGHT_ALT          ::Key::RIGHT_ALT
#define FAKE_KEY_RIGHT_SUPER        ::Key::RIGHT_SUPER
#define FAKE_KEY_MENU               ::Key::MENU