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

void System::start()
{
	// ������� ����
	bgmSound->play(true);

	// �ý��� ���� 
	while (playing) {

		// Ű���尪 �Է¹����� ���
		if (nowMode == MODE::MENU) {
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
			// ���� ���
		}
		else if (nowMode == MODE::RANKING) {
			// ��ŷ ���
			std::cout << "DdD";

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
