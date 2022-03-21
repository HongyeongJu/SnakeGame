#pragma once

#ifndef Game_h
#define Game_h
#include "TextColor.h"
#include "Enum.h"
#include "KeyBoard.h"
#include "Snake.h"
#include "Sound.h"
#include <cstdlib>
#include <thread>
#include <ctime>

class Game {
private :
	// 맵 변수
	int** map;
	// 뱀 객체
	Snake* snake;
	// 맵 사이즈
	const int MAPSIZE = 10;
	// 점수
	int score = 0;

	// 점수 상승 함수
	void improveScore();

	// 키보드 입력처리 함수
	void inputKeyBoard();

	// 소리 재생
	Sound* appleSound;

	// 사과 소리 재생 스레드
	std::thread *appleSoundThread;
public:

	// 생성자
	Game();
	// 초기 설정 함수 (여기서 뱀 객체를 설정하고 여러 설정을 한다.)
	void init();
	// update 함수
	void update();
	// 소멸자
	~Game();
	// 맵을 초기화하는 함수
	void mapInit();

	// 점수 셋터 함수
	void setScore(int score);

	// 점수 갯터 함수
	int getScore();

	// 화면 출력
	void print();

	// 출력전 객체 맵 적용
	void beforePrint();
	
	// 충돌처리 함수
	int collision();


	// 사과 랜덤 생성함수
	void makeApple();
};

#endif