#include "imageManager.h"
#include "image.h"


imageManager::imageManager()
{
}


imageManager::~imageManager()
{

}

bool imageManager::init()
{

	return true;
}
void imageManager::release()
{
	deleteAll();
}

image *imageManager::addImage(string strKey, char * fileName, int x, int y, int width, int height)
{
	image *img = findImage(strKey);

	if (img) return img;

	img = new image;
	img->init(fileName, x, y, width, height);

	_imageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addFrameImage(string strKey,  char* fileName, float x, float y, int width, int height, int frameX, int frameY)
{
	//해당 키값의 이미지를 찾아서 대입
	image* img = findImage(strKey);

	//만약에 이미지가 있다면, 그냥 그 이미지를 사용
	if (img) return img;

	//이미지를 동적할당
	img = new image;
	img->init(fileName, x, y, width, height, frameX, frameY);

	_imageList.insert(make_pair(strKey, img));

	return img;
}


image* imageManager::findImage(string strKey)
{

	
	_imageListIter= _imageList.find(strKey);

	if (_imageListIter != _imageList.end())
	{
		return _imageListIter->second;
	}

	return NULL;
}

bool imageManager::deleteImage(string strKey)
{

	_imageListIter = _imageList.find(strKey);

	if (_imageListIter != _imageList.end())
	{
		_imageListIter->second->release();
		delete _imageListIter->second;
		_imageList.erase(_imageListIter);
		return true;
	}
	return false;
}

void imageManager::render(string strKey, SDL_Surface *pScreenSurface)
{
	image *img = findImage(strKey);
	if(img) img->render(pScreenSurface);
}

bool imageManager::deleteAll()
{
	_imageListIter = _imageList.begin();

	for (; _imageListIter != _imageList.end();)
	{
		if (_imageListIter->second != NULL)
		{
			delete _imageListIter->second;
			_imageListIter = _imageList.erase(_imageListIter);
		}
		else ++_imageListIter;
	}
	_imageList.clear();

	return true;
}