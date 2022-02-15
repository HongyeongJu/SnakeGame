#pragma once

#ifndef TextColor_h
#define TextColor_h
#include <Windows.h>

class TextColor {
public:
	//color ��� ����
	enum COLOR {
		BLACK,
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		BROWN,
		LIGHTGRAY,
		DARKGRAY,
		LIGHTBLUE,
		LIGHTGREEN,
		LIGHTCYAN,
		LIGHTRED,
		LIGHTMAGENTA,
		YELLOW,
		WHITE
	};

	static void changeTextColor(int foreground, int background);
	static void changeText_White();
	static void changeText_SomeColor(int color);
};

#endif
