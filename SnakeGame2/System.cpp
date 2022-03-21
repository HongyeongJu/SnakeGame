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

void System::CursorView(bool TrueOrFalse) {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = TrueOrFalse;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void System::start()
{
	// 배경음악 실행
	// 배경음악을 재생시키기 위해서 스레드를 사용한다.
	std::thread bgmThread = std::thread(&Sound::play, bgmSound, true);
	bgmThread.join();


	// 시스템 시작 
	while (playing) {

		// 키보드값 입력받은것 출력
		if (nowMode == MODE::MENU) {
			// 커서의 뷰를 안보이게 설정한다.
			CursorView(false);
			// 메뉴 출력
			menu.print();
			menu.improve_color_cnt();
			// 메뉴 창에서의 선택
			int selected = menu.select();


			// 0: 게임 , 1 : 랭킹 , 2. 게임 종료
			switch (selected) {
			case 0: nowMode = MODE::GAME; KeyBoard::inputsToZero(); break;
			case 1: nowMode = MODE::RANKING; KeyBoard::inputsToZero(); break;
			case 2: stop(); break;

			}

			// Sleep과 창 클리어
			Sleep(100);
			system("cls");
		}
		else if (nowMode == MODE::GAME) {
			// 게임 진행
			game.update();
			// 충돌 처리 진행
			if (game.collision() == MODE::GAMEOVER) {
				// 충돌 처리결과가 GAMEOVER라면..
				nowMode = MODE::GAMEOVER;

				continue;
			}
			// 출력전 맵 적용 함수
			game.beforePrint();
			// 게임 출력
			game.print();
			Sleep(100);
			system("cls");
		}
		else if (nowMode == MODE::RANKING) {
			// 랭킹 출력
			std::cout << "DdD";
		}
		else if (nowMode == MODE::GAMEOVER) {
			gameover.setScore(game.getScore());
			
			// 키보드 입력값 반영
			int selected = gameover.inputKeyBoard();
			
			if (selected == MODE::MENU) {
				nowMode = MODE::MENU;
				game.init();
			}
			// 이름 문자열 생성
			gameover.doingName();
			// 출력
			gameover.print();
			Sleep(100);
			system("cls");
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

bool System::isPlaying()
{
	return playing;
}
