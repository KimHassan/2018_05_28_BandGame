#pragma once
#include "SingletonBase.h"
#include <map>

#include "inc/fmod.hpp"
#pragma comment(lib,"lib/fmodex_vc.lib")

using namespace FMOD;

#define SOUNDBUFFER 1000
#define EXTRACHANNELBUFFER 5

#define TOTALSOUNDBUFFER SOUNDBUFFER+EXTRACHANNELBUFFER
class soundManager :
	public singletonBase<soundManager>
{
private:
	map<string, Sound**> _mTotalSounds;
	typedef map<string, Sound**>::iterator arrSoundsIter;
	map<string, Channel**> arrChannels;
	typedef map<string, Channel**>::iterator arrChannelsIter;

	System * _system;
	Sound** _sound;
	Channel** _channel;


	
public:
	soundManager();
	~soundManager();

	bool init();
	void release();
	void update();

	void addSound(string keyName, string soundName, bool bgm, bool loop); //bgm인지, 무한으로 들을건지

	void play(string keyName, float volume = 1.0f);// 불룸은 아마 0-1까지
	void stop(string keyName); // 완전히 멈추고 시작시 재시작
	void pause(string keyName); // 일시정지
	void resume(string keyName); // 다시시작
	void Allstop();
	bool isPlaySound(string keyName);
	bool isPausedSound(string keyName);
};

