#include "System.h"

System::System()
{
	nowMode = MODE::MENU;
	playing = true;
	bgmSound = new Sound("bgm.wav");
	//키보드 스레드의 시작
	t_keyboard = new std::thread(KeyBoard::InsertKeyboard);	// 맴버 변수를 이용한 스레드 정의법
	
}

void System::setMode(MODE nowMode)
{
	this->nowMode = nowMode;
}

void System::start()
{
	// 배경음악 실행
	bgmSound->play(true);


	// 시스템 시작 
	while (playing) {

		// 키보드값 입력받은것 출력
		std::cout << KeyBoard::input1 << std::endl;

		if (nowMode == MODE::MENU) {
			// 메뉴 출력
		}
		else if (nowMode == MODE::GAME) {
			// 게임 출력
		}
		else if (nowMode == MODE::RANKING) {
			// 랭킹 출력
		}
	}
}

void System::stop()
{
	playing = false;
}

System::~System() {
	delete bgmSound;
	delete t_keyboard;
}