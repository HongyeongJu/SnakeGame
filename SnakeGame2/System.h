#pragma once

#ifndef System_h
#define System_h

#include "Sound.h"
#include "KeyBoard.h"
#include "Enum.h"
#include "Menu.h"
#include "Game.h"
#include "GameOver.h"
#include <Windows.h>
#include <thread>
#include <conio.h>

class System {
private:

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

	// ���� ��ü
	Game game;
	
	// ���� ���� ��ü
	GameOver gameover;

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

	// Ŀ�� �� ����
	void CursorView(bool TrueOrFalse);
};


#endif