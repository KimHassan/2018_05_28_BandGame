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

	void addSound(string keyName, string soundName, bool bgm, bool loop); //bgm����, �������� ��������

	void play(string keyName, float volume = 1.0f);// �ҷ��� �Ƹ� 0-1����
	void stop(string keyName); // ������ ���߰� ���۽� �����
	void pause(string keyName); // �Ͻ�����
	void resume(string keyName); // �ٽý���
	void Allstop();
	bool isPlaySound(string keyName);
	bool isPausedSound(string keyName);
};

