#pragma once

#ifndef GameOver_h
#define GameOver_h

#include <string>
#include "KeyBoard.h"
#include <vector>
#include "TextColor.h"

class GameOver {
private :
	// ������
	std::vector<char> name;
	// ����
	int score;
	
	// �̸�
	char* Cname;

	// DB ��ü
	// DBObject;

	bool isPointer = false;
public :

	// ������
	GameOver();

	// �Ҹ���
	~GameOver();

	// ���� ����
	void setScore(int score);

	// ȭ�� ��� �Լ�
	void print();
	
	// �̸� �Է� ��°� : ���� �ԷµǾ��ٸ�..
	int inputKeyBoard();

	// �̸� �ݿ� �Լ�
	void doingName();

};

#endif