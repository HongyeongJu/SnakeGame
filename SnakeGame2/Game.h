#pragma once

#ifndef Game_h
#define Game_h
#include "TextColor.h"
#include "Enum.h"
#include "KeyBoard.h"
#include "Snake.h"
#include "Sound.h"
#include <cstdlib>
#include <thread>
#include <ctime>

class Game {
private :
	// �� ����
	int** map;
	// �� ��ü
	Snake* snake;
	// �� ������
	const int MAPSIZE = 10;
	// ����
	int score = 0;

	// ���� ��� �Լ�
	void improveScore();

	// Ű���� �Է�ó�� �Լ�
	void inputKeyBoard();

	// �Ҹ� ���
	Sound* appleSound;

	// ��� �Ҹ� ��� ������
	std::thread *appleSoundThread;
public:

	// ������
	Game();
	// �ʱ� ���� �Լ� (���⼭ �� ��ü�� �����ϰ� ���� ������ �Ѵ�.)
	void init();
	// update �Լ�
	void update();
	// �Ҹ���
	~Game();
	// ���� �ʱ�ȭ�ϴ� �Լ�
	void mapInit();

	// ���� ���� �Լ�
	void setScore(int score);

	// ���� ���� �Լ�
	int getScore();

	// ȭ�� ���
	void print();

	// ����� ��ü �� ����
	void beforePrint();
	
	// �浹ó�� �Լ�
	int collision();


	// ��� ���� �����Լ�
	void makeApple();
};

#endif