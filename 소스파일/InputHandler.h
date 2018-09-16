#pragma once

enum MOUSEBUTTON // 마우스 상태
{
	LEFT,
	RIGHT,
	MIDDLE,
};
typedef struct MOUSESTATE // 마우스
{
	int x;
	int y;
	BYTE btn[4]; // 버튼이 눌러지는 상황
}MOUSESTATE;

class IInputHandler
{
public:
	IInputHandler()
	{
	}

	virtual ~IInputHandler()
	{
	}

public:
	virtual void KeyboardHandler(void) = 0;
	virtual void MouseHandler(MOUSESTATE mouseState) = 0;
};


