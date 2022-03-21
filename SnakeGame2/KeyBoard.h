#pragma once

#ifndef KeyBoard_h
#define KeyBoard_h
#include <conio.h>
#include <iostream>

class KeyBoard {
	// KeyBoard가 작동되는지 확인하는 변수
	static bool isWorking;
public :
	// static 변수로 된 입력 값
	static int input1;
	static int input2;

	// 키보드 값을 입력하는 함수
	static void InsertKeyboard();
	// 입력을 멈추는 함수
	static void inputsToZero();
	// 입력값을 0으로 초기화 하는 함수
	static void stopInput();
};

#endif