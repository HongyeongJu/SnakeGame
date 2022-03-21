#pragma once

#ifndef Snake_h
#define Snake_h
#include <deque>
#include "Enum.h"

class Snake {
private :
	// �� 
	int** map;
	// �� ������
	int mapsize;
	// x, y��ǥ
	int x;
	int y;

	// ���� ���� ���ϴ� ����
	int direction;

	// �� ���� ������
	int tailSize = 0;
public:
	// ������ ��ǥ��
	std::deque<std::pair<int, int>> tails;

	// ������ 
	Snake(int** map, int mapsize);
	// �̵� �Լ�
	void move();
	// ���� ¥���� �Լ�
	void cutTail();
	// �� ��ǥ ���� �Լ�
	void setPosition(int x, int y);
	// ���� ���� ���� �Լ�
	void setDirection(int direction);
	
	// ���� ���� �Լ�
	void improveTail();

	// x ����
	int getX();
	// y ����
	int getY();
};

#endif