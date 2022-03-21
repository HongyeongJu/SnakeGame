#include "KeyBoard.h"

int KeyBoard::input1 = 0;
int KeyBoard::input2 = 0;
bool KeyBoard::isWorking = true;

// Ű���� ���� �Է��ϴ� �Լ�
void KeyBoard::InsertKeyboard() {
	while (isWorking) {
		input1 = _getch();

		// ����Ű�� �Է��ϸ� input1�� 224 
		if (input1 == 224) {
			input2 = _getch();
			/*switch (input2) {
			case 72: std::cout << "����"; break;
			case 80: std::cout << "�Ʒ���"; break;
			case 75: std::cout << "����"; break;
			case 77: std::cout << "������"; break;
			}*/
		}
		else {
			input2 = 0;
		}

		//std::cout << input1 << "  " << input2 << "  " << std::endl;
	}

}

// �Է��� ���ߴ� �Լ�
void KeyBoard::stopInput() {
	isWorking = false;
}

// �Է°��� 0���� �ʱ�ȭ �ϴ� �Լ�
void KeyBoard::inputsToZero()
{
	input1 = 0;
	input2 = 0;
}
