#include "System.h"

System::System()
{
	nowMode = MODE::MENU;
	playing = true;
	bgmSound = new Sound("bgm.wav");
	//Ű���� �������� ����
	t_keyboard = new std::thread(KeyBoard::InsertKeyboard);	// �ɹ� ������ �̿��� ������ ���ǹ�
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
	// ������� ����
	// ��������� �����Ű�� ���ؼ� �����带 ����Ѵ�.
	std::thread bgmThread = std::thread(&Sound::play, bgmSound, true);
	bgmThread.join();


	// �ý��� ���� 
	while (playing) {

		// Ű���尪 �Է¹����� ���
		if (nowMode == MODE::MENU) {
			// Ŀ���� �並 �Ⱥ��̰� �����Ѵ�.
			CursorView(false);
			// �޴� ���
			menu.print();
			menu.improve_color_cnt();
			// �޴� â������ ����
			int selected = menu.select();


			// 0: ���� , 1 : ��ŷ , 2. ���� ����
			switch (selected) {
			case 0: nowMode = MODE::GAME; KeyBoard::inputsToZero(); break;
			case 1: nowMode = MODE::RANKING; KeyBoard::inputsToZero(); break;
			case 2: stop(); break;

			}

			// Sleep�� â Ŭ����
			Sleep(100);
			system("cls");
		}
		else if (nowMode == MODE::GAME) {
			// ���� ����
			game.update();
			// �浹 ó�� ����
			if (game.collision() == MODE::GAMEOVER) {
				// �浹 ó������� GAMEOVER���..
				nowMode = MODE::GAMEOVER;

				continue;
			}
			// ����� �� ���� �Լ�
			game.beforePrint();
			// ���� ���
			game.print();
			Sleep(100);
			system("cls");
		}
		else if (nowMode == MODE::RANKING) {
			// ��ŷ ���
			std::cout << "DdD";
		}
		else if (nowMode == MODE::GAMEOVER) {
			gameover.setScore(game.getScore());
			
			// Ű���� �Է°� �ݿ�
			int selected = gameover.inputKeyBoard();
			
			if (selected == MODE::MENU) {
				nowMode = MODE::MENU;
				game.init();
			}
			// �̸� ���ڿ� ����
			gameover.doingName();
			// ���
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
