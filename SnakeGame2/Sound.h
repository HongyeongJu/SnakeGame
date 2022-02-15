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
	// ������
	Sound(std::string soundName);

	// ������ �÷���
	void play(bool isLoop);

	// ������ ����
	void stop();
};


#endif