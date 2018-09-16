#include "stdafx.h"
#include "BaseWindow.h"

CBaseWindow::CBaseWindow(void) : m_bIsGameRun(SDL_TRUE)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMAGEMANAGER->init();
	SOUNDMANAGER->init();
	IMAGEMANAGER->addImage("Ÿ��Ʋ", "img/main_empty.bmp", 0, 0, WINSIZEX, WINSIZEY);
	
	IMAGEMANAGER->addImage("�ΰ���", "img/ingame.bmp", 0, 0, WINSIZEX, WINSIZEY);
	
	IMAGEMANAGER->addImage("ũ����", "img/credit.bmp", 0, 0, WINSIZEX, WINSIZEY);

	IMAGEMANAGER->addImage("�Ͽ���", "img/how_to.bmp", 0, 0, WINSIZEX, WINSIZEY);

	IMAGEMANAGER->addImage("ũ������ư", "img/button_credit.bmp", 0, 0, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("ũ������ư2", "img/button_credit_up.bmp", 0, 0, WINSIZEX, WINSIZEY);
	//IMAGEMANAGER->addImage("ũ������ư", "img/button_credit.bmp", 0, 0, 298, 157);
	//108,514
	IMAGEMANAGER->addImage("�������ư", "img/button_exit.bmp", 0, 0, 131, 87);
	IMAGEMANAGER->addImage("�������ư2", "img/button_exit_up.bmp", 0, 0, 260, 126);
	//853,435
	IMAGEMANAGER->addImage("Ȩ��ư", "img/button_home.bmp", 0, 0, 298, 157);
	IMAGEMANAGER->addImage("Ȩ��ư2", "img/home_up.bmp", 0, 0, 136, 95);


	IMAGEMANAGER->addImage("�Ͽ�����ư", "img/button_how_ to.bmp", 0, 0, 260, 126);
	IMAGEMANAGER->addImage("�Ͽ�����ư2", "img/button_how_to_up.bmp", 0, 0, 260, 126);
	//893,434
	IMAGEMANAGER->addImage("�÷��̹�ư", "img/button_play.bmp", 0, 0, 260, 126);
	IMAGEMANAGER->addImage("�÷��̹�ư2", "img/button_play_up.bmp", 0, 0, 260, 126);
	//864,340
	IMAGEMANAGER->addFrameImage("�Ͻ�������ư", "img/button_pause.bmp", 0, 0, 699, 74,3,1);

	//376,529
	IMAGEMANAGER->addFrameImage("��Ÿ", "img/camel.bmp", 0, 0, 300, 267, 4, 3);
	IMAGEMANAGER->addFrameImage("ŷ������", "img/ŷ������.bmp", 0, 0, 2728, 502, 11, 2);
	//IMAGEMANAGER->addImage("��Ÿ", "img/camel.bmp", 200, 500, 300, 267);
	IMAGEMANAGER->addImage("Ŀ��", "img/cursor.bmp", 0, 0, 50, 28);

	IMAGEMANAGER->addImage("��", "img/song.bmp", 0, 0, 330, 720);
	IMAGEMANAGER->addFrameImage("�θǽ�", "img/romance.bmp", 0, 0, 990, 95,3,1);
	IMAGEMANAGER->addFrameImage("����", "img/mangak.bmp", 0, 0, 990, 90, 3, 1);
	IMAGEMANAGER->addFrameImage("����", "img/withyou.bmp", 0, 0, 990, 99, 3, 1);
	IMAGEMANAGER->addFrameImage("�ϴÿ���½�", "img/tales.bmp", 0, 0, 990, 94, 3, 1);
	IMAGEMANAGER->addFrameImage("���ý�Ÿ", "img/shootingstar.bmp", 0, 0, 990, 90, 3, 1);

	IMAGEMANAGER->addFrameImage("��Ÿ", "img/guitar.bmp", 0, 0, 512 * 5, 512, 5, 1);
	IMAGEMANAGER->addFrameImage("�߷�", "img/jump.bmp", 0, 0, 2560, 512, 5, 1);
	IMAGEMANAGER->addFrameImage("���ɹ߷�", "img/spin.bmp", 0, 0, 2560, 512, 5, 1);
	IMAGEMANAGER->addFrameImage("��", "img/queen.bmp", 0, 0, 2560, 424, 5, 1);
	IMAGEMANAGER->addFrameImage("�Ǹ�", "img/hamonica.bmp", 0, 0, 1150, 512, 5, 1);



	SOUNDMANAGER->addSound("�θǽ�", "sound/Romance.mp3", true, true);
	SOUNDMANAGER->addSound("���ý�Ÿ", "sound/ShootingStar.mp3", true, true);
	SOUNDMANAGER->addSound("����", "sound/With you.mp3", true, true);
	SOUNDMANAGER->addSound("����", "sound/����.mp3", true, true);
	SOUNDMANAGER->addSound("�ϴÿ���½�", "sound/�ϴÿ���½�.mp3", true, true);

}

CBaseWindow::~CBaseWindow(void)
{
	SDL_Quit();
}

bool CBaseWindow::Initialize()
{
	//m_pWnd = SDL_CreateWindow("SDL_GameBase", 100, 100, WINSIZEX, WINSIZEY, 0);
	m_pWnd = SDL_CreateWindow("SDL_GameBase", 0, 0, WINSIZEX, WINSIZEY, SDL_WINDOW_FULLSCREEN);
	//m_pRender = SDL_CreateRenderer(m_pWnd, -1, 0);
	pScreenSurface = SDL_GetWindowSurface(m_pWnd);
	//ShowCursor(false);
	return true;
}

void CBaseWindow::Terminate()
{
	//SDL_DestroyRenderer(m_pRender);
	SDL_DestroyWindow(m_pWnd);
	SDL_FreeSurface(pScreenSurface);
}