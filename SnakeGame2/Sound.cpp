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
	// 문자열 변환 string -> LPWSTR 형으로
	wchar_t wtext[20];
	mbstowcs(wtext, soundName.c_str(), soundName.length());
	wtext[soundName.length()] = '\0';
	LPWSTR soundName_sw = wtext;

	openBgm.lpstrElementName = soundName_sw;	// 이름 입력
	openBgm.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	dwID = openBgm.wDeviceID;

	// 이 음악은 loop를 필요로 한다면..
	if (isLoop) {
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		//PlaySound(soundName_sw, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else {
		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openBgm);
		Sleep(2000);
		mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
		//PlaySound(soundName_sw, NULL, SND_FILENAME | SND_NOSTOP | SND_ASYNC);
	}
}

void Sound::stop()
{
	PlaySound(NULL, 0, 0);
}

Sound::~Sound() {
}