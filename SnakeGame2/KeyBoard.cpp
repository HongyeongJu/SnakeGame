#include "KeyBoard.h"

int KeyBoard::input1 = 0;
int KeyBoard::input2 = 0;

void KeyBoard::InsertKeyboard() {
	while (true) {
		input1 = _getch();

		if (input1 == 224) {
			input2 = _getch();
			switch (input2) {
			case 72: std::cout << "����"; break;
			case 80: std::cout << "�Ʒ���"; break;
			case 75: std::cout << "����"; break;
			case 77: std::cout << "������"; break;
			}
		}
	}

}