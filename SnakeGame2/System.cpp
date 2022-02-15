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
		std::cout << KeyBoard::input1 << std::endl;

		if (nowMode == MODE::MENU) {
			// �޴� ���
		}
		else if (nowMode == MODE::GAME) {
			// ���� ���
		}
		else if (nowMode == MODE::RANKING) {
			// ��ŷ ���
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