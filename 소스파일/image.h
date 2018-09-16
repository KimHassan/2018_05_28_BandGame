#pragma once
#include "stdafx.h"

class image
{
	SDL_Surface* _image;
	char* _fileName;
	int _x, _y;
	int _width, _height;
	int _frameWidth, _frameHeight;
	int _currentFrameX, _currentFrameY;
	int _maxFrameX, _maxFrameY;

public:
	bool init(char* fileName,int x,int y,int width,int height);
	bool init(char* fileName, float x, float y, int width, int height,
		int frameX, int frameY);
	void release();
	void render(SDL_Surface *pScreenSurface);
	void frameRender(SDL_Surface *pScreenSurface);
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void setXY(int x, int y) { _x = x; _y = y; }
	void setFrameX(int x) { _currentFrameX = x; }
	void setFrameY(int y) { _currentFrameY = y; }
	int getX() {return _x; }
	int getY() { return _y; }
	image();
	~image();
};

