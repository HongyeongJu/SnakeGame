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
	// MENU의 입력값
	enum MENU_INPUT {
		GAME_START,
		RANKING,
		EXIT,
		NOTHING
	};

	
	// 화면 출력하는 함수
	void print();
	// 선택할 수 있는 함수
	int select();

	// 텍스트 컬러의 증감 함수 
	void improve_color_cnt();
};

#endif