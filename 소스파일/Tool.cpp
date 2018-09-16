#include "stdafx.h"



Tool::Tool()
{
}


Tool::~Tool()
{
}

SDL_Rect Tool::RectMake(int left, int top, int width, int height)
{
	SDL_Rect rc = { left,top,width,height };
	return rc;
}

void Tool::RGBout(SDL_Surface *img)
{
	Uint32 colorkey = SDL_MapRGB(img->format, 255, 0, 255); //»ö±ò Å° °ª 
	SDL_SetColorKey(img, SDL_TRUE, colorkey); //»ö±ò Å° °ª ¼³Á¤
}

bool Tool::SDL_PtInRect(SDL_Rect *rc, SDL_Point pt)
{
	if (rc->x < pt.x && rc->x + rc->w > pt.x && rc->y < pt.y && rc->y + rc->h > pt.y)
	{
		return true;
	}
	else
		return false;
}


void Tool::update(SDL_Event evnt)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	_ptMouse.x = x;
	_ptMouse.y = y;
}