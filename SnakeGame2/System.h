#pragma once

#ifndef System_h
#define System_h

#include "Sound.h"
#include "KeyBoard.h"
#include <thread>

class System {
private:
	// 프로그램은 총 메뉴모드, 게임모드, 랭킹모드 3가지로 이루어진다.
	enum class MODE {
		MENU,
		GAME,
		RANKING
	};

	// 현재 프로그램 모드
	MODE nowMode;

	// 시스템 상태
	bool playing;

	// 배경음악 객체
	Sound *bgmSound;

	// 키보드 스레드 객체
	std::thread *t_keyboard;

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
};


#endif