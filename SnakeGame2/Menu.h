#pragma once

#ifndef Menu_h
#define Menu_h
#include "TextColor.h"
#include "KeyBoard.h"
#include <iostream>
class Menu {
private:
	int text_color_cnt = 0;
	int colors[3] = { TextColor::WHITE, TextColor::BLUE, TextColor::GREEN };

public:
	enum MENU_INPUT {
		GAME_START,
		RANKING,
		EXIT,
		NOTHING
	};

	
	void print();
	int select();

	void improve_color_cnt();
};

#endif