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
	dwNextTick = 0; //���� �� ���� ��ȸ�� ���� �Ǿ�� �ϴ� �ð� 
	
	dwElapsedTicks = 0;
	dwCurrentTicks = 0;
	return true;
}

void CSystem::Pulse()
{


	dwStartTick = GetTickCount();

	dwDelay = dwInterval - (GetTickCount() - dwStartTick);//�̹� �������� ��� �ؾ� �� �ð� = ������ FPS ������ ���� ���� 1��ȸ�� ���� �Ǿ�� �ϴ� �ð� - �߰��� � ������ ���� �Ǿ��� ��� �� ������ �ð�

	if (dwDelay > 0)//�� ���ǹ��� ������ �ð��� FPS ������ ���� ���� 1��ȸ�� ���� �ð� ���� Ŭ ��� dwDelay ���� ������ �Ǿ� Sleep()�Լ� ȣ��� ���� ���ŷ ���¿� ������ ���¸� ���� �ϱ� ���� �뵵�� ���δ�. 
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