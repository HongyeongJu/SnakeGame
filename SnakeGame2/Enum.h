#pragma once

#ifndef Enum_h
#define Enum_h

// ���� ������ ����
enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

// �� Ÿ�� ����
// BLANK�� ��ĭ, BLOCK�� ��� �׸�, SNAKE�� ��ĭ ���׶��, HEAD�� ä�����ִ� ���׶��, APPLE�� ��
enum Object {
	BLANK = 0,
	BLOCK = 1,
	SNAKE = 2,
	HEAD = 3,
	APPLE = 4
};

// ���α׷��� �� �޴����, ���Ӹ��, ��ŷ��� 3������ �̷������.
enum MODE {
	MENU,
	GAME,
	RANKING,
	GAMEOVER
};

#endif