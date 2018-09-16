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

	_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, NULL);//���� / �̰��� �����Ҽ� �ִµ� �⺻���� ��

	_sound = new Sound*[TOTALSOUNDBUFFER]; // �����������̱� ������ �̷��� ����
	_channel = new Channel*[TOTALSOUNDBUFFER];


	//ZeroMemory(_sound, sizeof(_sound));
	//ZeroMemory(_channel, sizeof(_channel));
	return true;
}
void soundManager::release()														  
{
	//�ȿ� �ִ� ���� ����
	if (_channel != NULL || _sound != NULL) // ä���̳� ���尡 ������� �ʴٸ�
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

	//�޸𸮸� ����
	delete _channel;
	delete _sound;

	//�ý��� �ݾ������
	if (_system != NULL)
	{
		_system->release();
		_system->close();
	}
}


void soundManager::update()															  
{
	//���� �ý��� ��������� ������Ʈ
	_system->update();
	//�ҷ� ���� ����� ���� ���� ä�ο��� ������
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
	arrSoundsIter iter = _mTotalSounds.begin(); // �迭 Ž���� ���� ���ͷ����� ����
	int count = 0; //�迭 Ž���� ���� ī��Ʈ

	for (iter; iter != _mTotalSounds.end(); ++iter, count++) 
	{
		if (keyName == iter->first) // map�� string�� Ű���Ӱ� ���ٸ�
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

	int count = 0;		//�迭 Ž���� ���� ī��Ʈ

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

	//���ͷ����Ϳ� �������̳� ó���� ����Ű�� ���ְ�
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;		//�迭 Ž���� ���� ī��Ʈ

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