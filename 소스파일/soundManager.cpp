#include "soundManager.h"



soundManager::soundManager()
	:_system(NULL), _channel(NULL), _sound(NULL)
{
	
}


soundManager::~soundManager()
{

}

bool soundManager::init()															  
{

	System_Create(&_system);

	_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, NULL);//버퍼 / 이것은 설정할수 있는데 기본으로 함

	_sound = new Sound*[TOTALSOUNDBUFFER]; // 이중포인터이기 때문에 이렇게 썼음
	_channel = new Channel*[TOTALSOUNDBUFFER];


	//ZeroMemory(_sound, sizeof(_sound));
	//ZeroMemory(_channel, sizeof(_channel));
	return true;
}
void soundManager::release()														  
{
	//안에 있는 사운드 제거
	if (_channel != NULL || _sound != NULL) // 채널이나 사운드가 비어있지 않다면
	{
		for (int i = 0; i < TOTALSOUNDBUFFER; i++)
		{
			if (_channel != NULL)
			{
				if (_channel[i]) _channel[i]->stop();
			}
			if (_sound != NULL)
			{
				if (_sound !=NULL) _sound[i]->release();
			}
		}
	}

	//메모리를 지움
	delete _channel;
	delete _sound;

	//시스템 닫어버리기
	if (_system != NULL)
	{
		_system->release();
		_system->close();
	}
}


void soundManager::update()															  
{
	//사운드 시스템 계속적으로 업데이트
	_system->update();
	//불륨 변경 재생이 끝난 사운드 채널에서 뺴내기
}

void soundManager::addSound(string keyName, string soundName, bool bgm, bool loop)
{
	if (loop)
	{
		if (bgm)
		{
			_system->createStream(soundName.c_str(), FMOD_LOOP_NORMAL, NULL,
				&_sound[_mTotalSounds.size()]);
		}
		else
		{
			_system->createSound(soundName.c_str(), FMOD_DEFAULT, NULL, &_sound[_mTotalSounds.size()]);
		}
	}
	_mTotalSounds.insert(make_pair(keyName, &_sound[_mTotalSounds.size()]));

}
void soundManager::play(string keyName, float volume)						  
{
	arrSoundsIter iter = _mTotalSounds.begin(); // 배열 탐색을 위한 이터레이터 생성
	int count = 0; //배열 탐색을 위한 카운트

	for (iter; iter != _mTotalSounds.end(); ++iter, count++) 
	{
		if (keyName == iter->first) // map의 string이 키네임과 같다면
		{
			
			_system->playSound(FMOD_CHANNEL_FREE, *iter->second, false,
				&_channel[count]);

			_channel[count]->setVolume(volume);
			break;
		}
	}
}
void soundManager::stop(string keyName)												  
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, ++count)
	{
		if (keyName == iter->first)
		{
			_channel[count]->stop();
			break;
		}
	}
}

void soundManager::Allstop()
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, ++count)
	{
	
			_channel[count]->stop();

	}
}

void soundManager::pause(string keyName)											  
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(true);
			break;
		}
	}
}
void soundManager::resume(string keyName)											  
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;		//배열 탐색을 위한 카운트

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(false);
			break;
		}
	}
}
bool soundManager::isPlaySound(string keyName)										  
{
	bool isPlay;

	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->isPlaying(&isPlay);
			break;
		}
	}
	return isPlay;
}
bool soundManager::isPausedSound(string keyName)									  
{
	bool isPause;

	//이터레이터에 맵컨테이너 처음을 가르키게 해주고
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;		//배열 탐색을 위한 카운트

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->getPaused(&isPause);
			break;
		}
	}

	return isPause;

}