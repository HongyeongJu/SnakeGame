#include "Sound.h"

Sound::Sound()
{
}

Sound::Sound(std::string soundName)
{
	this->soundName = soundName;
}

void Sound::play(bool isLoop)
{
	// ���ڿ� ��ȯ string -> LPWSTR ������
	wchar_t wtext[20];
	mbstowcs(wtext, soundName.c_str(), soundName.length());
	wtext[soundName.length()] = '\0';
	LPWSTR soundName_sw = wtext;

	// �� ������ loop�� �ʿ�� �Ѵٸ�..
	if (isLoop) {
		PlaySound(soundName_sw, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else {
		PlaySound(soundName_sw, NULL, SND_FILENAME);
	}
}

void Sound::stop()
{
	PlaySound(NULL, 0, 0);
}
