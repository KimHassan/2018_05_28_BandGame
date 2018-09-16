#include "stdafx.h"



class Title;
class InGame;
enum PHASE
{
	TITLE,
	INGAME,
	EXIT,
};

class CSystem : public CBaseWindow,
			   public CTimeManager,
			   public IInputHandler
{	
private:

	enum DrawingState{ POINTS = 0, LINES, BOXES, END };
	int m_nIsDrawingState = POINTS;

private:

	CInputManager*	m_pInputManager;
	Title* TitleScene;
	InGame* InGameScene;
	 PHASE phase;
	 DWORD dwInterval;
	 DWORD dwNextTick;
	 DWORD dwStartTick;
	 DWORD dwDelay;

	 DWORD dwElapsedTicks;
	 DWORD dwCurrentTicks;
	 DWORD FPS;

public:
	CSystem(void);
	~CSystem(void);

private:
	void Pulse();

	void Update(const SDL_Event & ev);
	void Render();
public:
	bool Initialize();
	void Terminate();
	void Run();

public:
	void KeyboardHandler();
	void MouseHandler(MOUSESTATE mouseState);
};
