#pragma once
#include "SingletonBase.h"
#include "stdafx.h"
#include <map>
#include <string>

class image;

class imageManager :
	public singletonBase<imageManager>
{
private:
	map<string, image*> _imageList;
	map<string, image*>::iterator _imageListIter;

public:
	bool init();
	void release();

	image *addImage(string strKey, char * fileName,int x, int y,int width, int height);
	image* addFrameImage(string strKey, char* fileName, float x, float y, int width, int height, int frameX, int frameY);
	image* findImage(string strKey);

	bool deleteImage(string strKey);

	void render(string strKey, SDL_Surface *pScreenSurface);

	bool deleteAll();
	imageManager();
	~imageManager();
};

