#pragma once

#ifndef Snake_h
#define Snake_h
#include <deque>
#include "Enum.h"

class Snake {
private :
	// 맵 
	int** map;
	// 맵 사이즈
	int mapsize;
	// x, y좌표
	int x;
	int y;

	// 현재 뱀이 향하는 방향
	int direction;

	// 뱀 길이 사이즈
	int tailSize = 0;
public:
	// 꼬리의 좌표들
	std::deque<std::pair<int, int>> tails;

	// 생성자 
	Snake(int** map, int mapsize);
	// 이동 함수
	void move();
	// 꼬리 짜르기 함수
	void cutTail();
	// 뱀 좌표 설정 함수
	void setPosition(int x, int y);
	// 뱀의 방향 설정 함수
	void setDirection(int direction);
	
	// 꼬리 증가 함수
	void improveTail();

	// x 겟터
	int getX();
	// y 겟터
	int getY();
};

#endif