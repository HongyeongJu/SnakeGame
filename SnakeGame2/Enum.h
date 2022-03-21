#pragma once

#ifndef Enum_h
#define Enum_h

// 뱀의 방향을 정의
enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

// 맵 타일 정의
// BLANK는 빈칸, BLOCK은 흰색 네모, SNAKE는 빈칸 동그라미, HEAD는 채워져있는 동그라미, APPLE은 별
enum Object {
	BLANK = 0,
	BLOCK = 1,
	SNAKE = 2,
	HEAD = 3,
	APPLE = 4
};

// 프로그램은 총 메뉴모드, 게임모드, 랭킹모드 3가지로 이루어진다.
enum MODE {
	MENU,
	GAME,
	RANKING,
	GAMEOVER
};

#endif