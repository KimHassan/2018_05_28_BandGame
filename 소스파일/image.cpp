#include "image.h"



image::image()
{
}


image::~image()
{

}

bool image::init(char* fileName, int x, int y, int width, int height)	
{
	_image = SDL_LoadBMP(fileName);
	_fileName = fileName;
	_x = x;
	_y = y;
	_height = height;
	_width = width;
	//Uint32 colorkey = SDL_MapRGB(_image->format, 255, 0, 255); //색깔 키 값 
	SDL_SetColorKey(_image, SDL_TRUE, RGB(225,0,225)); //색깔 키 값 설정

	return true;

}

bool image::init(char* fileName, float x, float y, int width, int height,
	int frameX, int frameY)
{
	//이미지 정보가 이미 있다면 해제

	//DC영역을 가져온다

	_image = SDL_LoadBMP(fileName);
	_fileName = fileName;
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_frameWidth = width / frameX;
	_frameHeight = height / frameY;
	_currentFrameX = 0;
	_currentFrameY = 0;
	_maxFrameX = frameX - 1;
	_maxFrameY = frameY - 1;

	SDL_SetColorKey(_image, SDL_TRUE, RGB(225, 0, 225));
	return S_OK;
}


void image::release()														
{
	_fileName = NULL;
	SDL_FreeSurface(_image);
}
void image::render(SDL_Surface *pScreenSurface)								
{
	SDL_Rect rc = { _x,_y,_width,_height };
	SDL_BlitSurface(_image, NULL, pScreenSurface, &rc); //pImageSurface ==> pScreenSurface로 고속복사 , NULL의 의미는 이미지 전체

}

void image::frameRender(SDL_Surface *pScreenSurface)
{
	SDL_Rect rc = { _x,_y,_width,_height };
	SDL_Rect frame_rc = { _currentFrameX * _frameWidth,_currentFrameY * _frameHeight,_frameWidth,_frameHeight };
	SDL_BlitSurface(_image, &frame_rc, pScreenSurface, &rc);
}