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
	// MENU�� �Է°�
	enum MENU_INPUT {
		GAME_START,
		RANKING,
		EXIT,
		NOTHING
	};

	
	// ȭ�� ����ϴ� �Լ�
	void print();
	// ������ �� �ִ� �Լ�
	int select();

	// �ؽ�Ʈ �÷��� ���� �Լ� 
	void improve_color_cnt();
};

#endif