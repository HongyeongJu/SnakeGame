#pragma once

#ifndef System_h
#define System_h

#include "Sound.h"
#include "KeyBoard.h"
#include <thread>

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
};


#endif