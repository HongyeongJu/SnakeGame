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

	// 현재 프로그램 모드
	MODE nowMode;

	// 시스템 상태
	bool playing;

	// 배경음악 객체
	Sound *bgmSound;

	// 키보드 스레드 객체
	std::thread *t_keyboard;

	// 메뉴 객체
	Menu menu;

	// 게임 객체
	Game game;
	
	// 게임 오버 객체
	GameOver gameover;

public:
	// 생성자
	System();
	// 모드 설정
	void setMode(MODE nowMode);
	
	// 시스템 start
	void start();
	// 시스템 중지
	void stop();

	// 소멸자
	~System();

	// 시스템 상태
	bool isPlaying();

	// 커서 뷰 설정
	void CursorView(bool TrueOrFalse);
};


#endif