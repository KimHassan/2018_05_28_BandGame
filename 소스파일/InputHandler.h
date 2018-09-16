#pragma once

enum MOUSEBUTTON // ���콺 ����
{
	LEFT,
	RIGHT,
	MIDDLE,
};
typedef struct MOUSESTATE // ���콺
{
	int x;
	int y;
	BYTE btn[4]; // ��ư�� �������� ��Ȳ
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


