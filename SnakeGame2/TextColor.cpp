#include "TextColor.h"

void TextColor::changeTextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void TextColor::changeText_White()
{
	int color = COLOR::WHITE + COLOR::BLACK * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void TextColor::changeText_SomeColor(int color)
{
	int _color = color + COLOR::BLACK * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
}
