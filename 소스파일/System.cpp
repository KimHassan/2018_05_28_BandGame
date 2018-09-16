#include "stdafx.h"

static SDL_Point points[] = { 
	{ 50, 150 }, { 150, 100 },
	{ 300, 200 }, { 300, 100 },
	{ 150, 200 }, { 50, 150 },
};
static SDL_Rect rects[] = { 
	{ 50, 150, 10, 10 }, { 150, 100, 10, 10 },
	{ 300, 200, 10, 10 }, { 300, 100, 10, 10 },
	{ 150, 200, 10, 10 }, { 50, 150, 10, 10 },
};

CSystem::CSystem(void)
{

}

CSystem::~CSystem(void)
{

}

bool CSystem::Initialize()
{
	CBaseWindow::Initialize();


	m_pInputManager = new CInputManager;
	m_pInputManager->SetInputHandler(this);
	TitleScene = new Title;
	TitleScene->init();
	InGameScene = new InGame;
	InGameScene->init();
	phase = TITLE;
	FPS = 60;
	dwInterval = 1000 /FPS;
	dwNextTick = 0; //다음 번 루프 순회가 시작 되어야 하는 시간 
	
	dwElapsedTicks = 0;
	dwCurrentTicks = 0;
	return true;
}

void CSystem::Pulse()
{


	dwStartTick = GetTickCount();

	dwDelay = dwInterval - (GetTickCount() - dwStartTick);//이번 루프에서 대기 해야 할 시간 = 지정된 FPS 유지를 위해 루프 1순회당 지연 되어야 하는 시간 - 중간에 어떤 이유로 지연 되었을 경우 그 지연된 시간

	if (dwDelay > 0)//이 조건문은 지연된 시간이 FPS 유지를 위한 루프 1순회당 지연 시간 보다 클 경우 dwDelay 값이 음수가 되어 Sleep()함수 호출시 무한 블록킹 상태에 빠지는 사태를 방지 하기 위한 용도로 쓰인다. 
		Sleep(dwDelay);
	
	m_pInputManager->Pulse();

	SDL_Event evnt;
	SDL_PollEvent(&evnt);
	m_pInputManager->Mouse(evnt);
	
	if (evnt.type == SDL_QUIT)	m_bIsGameRun = SDL_FALSE;

	
		switch(phase)
		{
			case TITLE:
			{
				TitleScene->update(evnt, &phase);
				TitleScene->render(pScreenSurface);
				InGameScene->phaseChange();
			}
				break;
			
			case INGAME:
			{
				InGameScene->update(evnt,&phase);
				InGameScene->render(pScreenSurface);
				break;
			}
			case EXIT:
			{
				m_bIsGameRun = SDL_FALSE;
				break;
			}
		}
		SDL_UpdateWindowSurface(m_pWnd);
}

void CSystem::Terminate()
{
	m_pInputManager->Terminate();

	CBaseWindow::Terminate();
	CTimeManager::Terminate();
}

void CSystem::Run()
{	
	while (m_bIsGameRun)
	{
		Pulse(); //Update()
	}
}

#define g_pKeyCodeScan(vk) (m_pInputManager->GetOldKeyState(vk)&&m_pInputManager->GetCurKeyState(vk))

void CSystem::KeyboardHandler()
{
	if (g_pKeyCodeScan(SDL_SCANCODE_1))
		m_nIsDrawingState = DrawingState::POINTS;
	if (g_pKeyCodeScan(SDL_SCANCODE_2))
		m_nIsDrawingState = DrawingState::LINES;
	if (g_pKeyCodeScan(SDL_SCANCODE_3))
		m_nIsDrawingState = DrawingState::BOXES;
	if (g_pKeyCodeScan(SDL_SCANCODE_4))
		m_nIsDrawingState = DrawingState::END;
}

void CSystem::MouseHandler(MOUSESTATE mouseState)
{
	//if (mouseState.btn[MOUSEBUTTON::LEFT])
	//{
	//	//MouseDown(btnUp, mouseState.x, mouseState.y);
	//}
	if (mouseState.btn[MOUSEBUTTON::RIGHT])
	{

	}
}