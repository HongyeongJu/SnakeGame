#pragma once

#ifndef Sound_h
#define Sound_h

#include <string>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class Sound {
private:
	std::string soundName;

public:

	Sound();
	// 생성자
	Sound(std::string soundName);

	// 음악을 플레이
	void play(bool isLoop);

	// 음악을 중지
	void stop();
};


#endif