#pragma once

#ifndef Sound_h
#define Sound_h

#include <string>
#include <Windows.h>
#include <mmsystem.h>		// ���� ���̺귯��
#include <Digitalv.h>		// ���� ���̺귯��
#pragma comment(lib, "winmm.lib")	// ���� ���̺귯��

class Sound {
private:
	std::string soundName;

	MCI_OPEN_PARMS openBgm;
	MCI_PLAY_PARMS playBgm;
	int dwID;
public:

	Sound();
	// ������
	Sound(std::string soundName);

	// ������ �÷���
	void play(bool isLoop);

	// ������ ����
	void stop();

	//�Ҹ���
	~Sound();
};


#endif