#include "stdafx.h"
#include "BaseWindow.h"

CBaseWindow::CBaseWindow(void) : m_bIsGameRun(SDL_TRUE)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMAGEMANAGER->init();
	SOUNDMANAGER->init();
	IMAGEMANAGER->addImage("타이틀", "img/main_empty.bmp", 0, 0, WINSIZEX, WINSIZEY);
	
	IMAGEMANAGER->addImage("인게임", "img/ingame.bmp", 0, 0, WINSIZEX, WINSIZEY);
	
	IMAGEMANAGER->addImage("크레딧", "img/credit.bmp", 0, 0, WINSIZEX, WINSIZEY);

	IMAGEMANAGER->addImage("하우투", "img/how_to.bmp", 0, 0, WINSIZEX, WINSIZEY);

	IMAGEMANAGER->addImage("크레딧버튼", "img/button_credit.bmp", 0, 0, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("크레딧버튼2", "img/button_credit_up.bmp", 0, 0, WINSIZEX, WINSIZEY);
	//IMAGEMANAGER->addImage("크레딧버튼", "img/button_credit.bmp", 0, 0, 298, 157);
	//108,514
	IMAGEMANAGER->addImage("나가기버튼", "img/button_exit.bmp", 0, 0, 131, 87);
	IMAGEMANAGER->addImage("나가기버튼2", "img/button_exit_up.bmp", 0, 0, 260, 126);
	//853,435
	IMAGEMANAGER->addImage("홈버튼", "img/button_home.bmp", 0, 0, 298, 157);
	IMAGEMANAGER->addImage("홈버튼2", "img/home_up.bmp", 0, 0, 136, 95);


	IMAGEMANAGER->addImage("하우투버튼", "img/button_how_ to.bmp", 0, 0, 260, 126);
	IMAGEMANAGER->addImage("하우투버튼2", "img/button_how_to_up.bmp", 0, 0, 260, 126);
	//893,434
	IMAGEMANAGER->addImage("플레이버튼", "img/button_play.bmp", 0, 0, 260, 126);
	IMAGEMANAGER->addImage("플레이버튼2", "img/button_play_up.bmp", 0, 0, 260, 126);
	//864,340
	IMAGEMANAGER->addFrameImage("일시정지버튼", "img/button_pause.bmp", 0, 0, 699, 74,3,1);

	//376,529
	IMAGEMANAGER->addFrameImage("낙타", "img/camel.bmp", 0, 0, 300, 267, 4, 3);
	IMAGEMANAGER->addFrameImage("킹슬라임", "img/킹슬라임.bmp", 0, 0, 2728, 502, 11, 2);
	//IMAGEMANAGER->addImage("낙타", "img/camel.bmp", 200, 500, 300, 267);
	IMAGEMANAGER->addImage("커서", "img/cursor.bmp", 0, 0, 50, 28);

	IMAGEMANAGER->addImage("곡", "img/song.bmp", 0, 0, 330, 720);
	IMAGEMANAGER->addFrameImage("로맨스", "img/romance.bmp", 0, 0, 990, 95,3,1);
	IMAGEMANAGER->addFrameImage("망각", "img/mangak.bmp", 0, 0, 990, 90, 3, 1);
	IMAGEMANAGER->addFrameImage("윗유", "img/withyou.bmp", 0, 0, 990, 99, 3, 1);
	IMAGEMANAGER->addFrameImage("하늘에닿는시", "img/tales.bmp", 0, 0, 990, 94, 3, 1);
	IMAGEMANAGER->addFrameImage("슈팅스타", "img/shootingstar.bmp", 0, 0, 990, 90, 3, 1);

	IMAGEMANAGER->addFrameImage("기타", "img/guitar.bmp", 0, 0, 512 * 5, 512, 5, 1);
	IMAGEMANAGER->addFrameImage("발레", "img/jump.bmp", 0, 0, 2560, 512, 5, 1);
	IMAGEMANAGER->addFrameImage("스핀발레", "img/spin.bmp", 0, 0, 2560, 512, 5, 1);
	IMAGEMANAGER->addFrameImage("퀸", "img/queen.bmp", 0, 0, 2560, 424, 5, 1);
	IMAGEMANAGER->addFrameImage("피리", "img/hamonica.bmp", 0, 0, 1150, 512, 5, 1);



	SOUNDMANAGER->addSound("로맨스", "sound/Romance.mp3", true, true);
	SOUNDMANAGER->addSound("슈팅스타", "sound/ShootingStar.mp3", true, true);
	SOUNDMANAGER->addSound("윗유", "sound/With you.mp3", true, true);
	SOUNDMANAGER->addSound("망각", "sound/망각.mp3", true, true);
	SOUNDMANAGER->addSound("하늘에닿는시", "sound/하늘에닿는시.mp3", true, true);

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