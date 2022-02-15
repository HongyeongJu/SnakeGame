#pragma once

#ifndef System_h
#define System_h

#include "Sound.h"
#include "KeyBoard.h"
#include "Menu.h"
#include <thread>
#include <conio.h>

class System {
private:
	// ���α׷��� �� �޴����, ���Ӹ��, ��ŷ��� 3������ �̷������.
	enum class MODE {
		MENU,
		GAME,
		RANKING
	};

	// ���� ���α׷� ���
	MODE nowMode;

	// �ý��� ����
	bool playing;

	// ������� ��ü
	Sound *bgmSound;

	// Ű���� ������ ��ü
	std::thread *t_keyboard;

	// �޴� ��ü
	Menu menu;

public:
	// ������
	System();
	// ��� ����
	void setMode(MODE nowMode);
	
	// �ý��� start
	void start();
	// �ý��� ����
	void stop();

	// �Ҹ���
	~System();

	// �ý��� ����
	bool isPlaying();
};


#endif