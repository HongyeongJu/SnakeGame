#pragma once

#ifndef Sound_h
#define Sound_h

#include <string>
#include <Windows.h>
#include <mmsystem.h>		// 음악 라이브러리
#include <Digitalv.h>		// 음악 라이브러리
#pragma comment(lib, "winmm.lib")	// 음악 라이브러리

class Sound {
private:
	std::string soundName;

	MCI_OPEN_PARMS openBgm;
	MCI_PLAY_PARMS playBgm;
	int dwID;
public:

	Sound();
	// 생성자
	Sound(std::string soundName);

	// 음악을 플레이
	void play(bool isLoop);

	// 음악을 중지
	void stop();

	//소멸자
	~Sound();
};


#endif