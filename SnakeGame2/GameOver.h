#pragma once

#ifndef GameOver_h
#define GameOver_h

#include <string>
#include "KeyBoard.h"
#include <vector>
#include "TextColor.h"

class GameOver {
private :
	// 유저명
	std::vector<char> name;
	// 점수
	int score;
	
	// 이름
	char* Cname;

	// DB 객체
	// DBObject;

	bool isPointer = false;
public :

	// 생성자
	GameOver();

	// 소멸자
	~GameOver();

	// 점수 설정
	void setScore(int score);

	// 화면 출력 함수
	void print();
	
	// 이름 입력 출력값 : 엔터 입력되었다면..
	int inputKeyBoard();

	// 이름 반영 함수
	void doingName();

};

#endif