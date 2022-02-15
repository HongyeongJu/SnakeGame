#pragma once

#ifndef KeyBoard_h
#define KeyBoard_h
#include <conio.h>
#include <iostream>

class KeyBoard {
	static bool isWorking;
public :
	static int input1;
	static int input2;

	static void InsertKeyboard();
	static void inputsToZero();
	static void stopInput();
};

#endif