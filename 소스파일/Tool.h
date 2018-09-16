#pragma once

class Tool
{
public:
	SDL_Rect RectMake(int left, int top, int width,  int height);
	void RGBout(SDL_Surface *img);
	bool SDL_PtInRect(SDL_Rect *rc, SDL_Point pt);

	void update(SDL_Event evnt);
	SDL_Point _ptMouse;
	Tool();
	~Tool();
};

