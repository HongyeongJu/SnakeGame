#pragma once

#ifndef KeyBoard_h
#define KeyBoard_h
#include <conio.h>
#include <iostream>

class KeyBoard {
	// KeyBoard�� �۵��Ǵ��� Ȯ���ϴ� ����
	static bool isWorking;
public :
	// static ������ �� �Է� ��
	static int input1;
	static int input2;

	// Ű���� ���� �Է��ϴ� �Լ�
	static void InsertKeyboard();
	// �Է��� ���ߴ� �Լ�
	static void inputsToZero();
	// �Է°��� 0���� �ʱ�ȭ �ϴ� �Լ�
	static void stopInput();
};

#endif