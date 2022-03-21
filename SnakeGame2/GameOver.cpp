#include "GameOver.h"
#include "Enum.h"

GameOver::GameOver() {
	Cname = new char[10];
}

GameOver::~GameOver() {
	delete[] Cname;
}

void GameOver::setScore(int score)
{
	this->score = score;
}

void GameOver::print() {

	printf("**********************************\n");
	printf("*                                *\n");
	printf("*                                *\n");
	printf("*       ");
	printf(" Name: ");
	TextColor::changeText_SomeColor(TextColor::BLUE);
	printf("%10s",Cname);
	TextColor::changeText_White();
	if (isPointer) {
		printf("_       *\n");
	}
	else {
		printf("        *\n");
	}
	isPointer = !isPointer;
	
	printf("*                                *\n");
	printf("*       Score:  %10d       *\n", score);
	printf("*                                *\n");
	printf("**********************************\n");

}

void GameOver::doingName() {
	if (name.empty()) {
		Cname[0] = '\0';
	}
	else {
		for (int i = 0; i < name.size(); i++) {
			Cname[i] = name[i];
		}
		Cname[name.size()] = '\0';
	}

}

int GameOver::inputKeyBoard() {
	int result = MODE::GAMEOVER;

	// ���� 
	if (KeyBoard::input1 >= 'a' && KeyBoard::input1 <= 'z'){
		if (name.size() < 10) {
			name.push_back(KeyBoard::input1);
			KeyBoard::inputsToZero();
		}
	}
	else if (KeyBoard::input1 >= 'A' && KeyBoard::input1 <= 'Z') {
		if (name.size() < 10) {
			name.push_back(KeyBoard::input1);
			KeyBoard::inputsToZero();
		}
	}
	// ����
	else if (KeyBoard::input1 == 13 && KeyBoard::input2 == 0) {
		if (!name.empty()) {

			// DB ���� 
			
			// name �ʱ�ȭ
			name.clear();

			result = MODE::MENU;
		}
	}
	// �������̽�
	else if (KeyBoard::input1 == 8)
	{
		if (!name.empty()) {
			name.pop_back();
			KeyBoard::inputsToZero();
		}
	}

	return result;
}