#include "KeyBoard.h"

int KeyBoard::input1 = 0;
int KeyBoard::input2 = 0;
bool KeyBoard::isWorking = true;

void KeyBoard::InsertKeyboard() {
	while (isWorking) {
		input1 = _getch();

		// 방향키를 입력하면 input1은 224 
		if (input1 == 224) {
			input2 = _getch();
			/*switch (input2) {
			case 72: std::cout << "위쪽"; break;
			case 80: std::cout << "아래쪽"; break;
			case 75: std::cout << "왼쪽"; break;
			case 77: std::cout << "오른쪽"; break;
			}*/
		}
		else {
			input2 = 0;
		}
	}

}

void KeyBoard::stopInput() {
	isWorking = false;
}

void KeyBoard::inputsToZero()
{
	input1 = 0;
	input2 = 0;
}
