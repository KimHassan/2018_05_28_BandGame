#include "stdafx.h"


Title::Title()
{
}


Title::~Title()
{

}

bool Title::init()
{
	cursor = SDL_LoadBMP("img/cursor.bmp");
	RGBout(cursor);
		
	click = false;


	//play_button   = new image; 
	//credit_button = new image;
	//home_button	 = new image;
	//exit_button	 = new image;
	//how_to_button = new image;
	//play_button2 = new image;
	//credit_button2 = new image;
	//exit_button2 = new image;
	//how_to_button2 = new image;

	play_button = IMAGEMANAGER->findImage("플레이버튼");
	credit_button = IMAGEMANAGER->findImage("크레딧버튼");
	home_button = IMAGEMANAGER->findImage("홈버튼");
	exit_button = IMAGEMANAGER->findImage("나가기버튼");
	how_to_button = IMAGEMANAGER->findImage("하우투버튼");
	play_button2 = IMAGEMANAGER->findImage("플레이버튼2");
	credit_button2 = IMAGEMANAGER->findImage("크레딧버튼2");
	exit_button2 = IMAGEMANAGER->findImage("나가기버튼2");
	how_to_button2 = IMAGEMANAGER->findImage("하우투버튼2");

	play_button->setXY(395, 549);
	credit_button->setXY(80, 533);
	home_button->setXY(20, 20);
	exit_button->setXY(913, 543);
	how_to_button->setXY(669, 539);

	//play_button2->setXY(395 + 19, 549 - 14);
	//credit_button2->setXY(80 - 19, 533- 45);
	//exit_button2->setXY(913 + 19, 543 - 14);
	//how_to_button2->setXY(669 + 19, 539 - 14);
	play_button2->setXY(385, 553);
	credit_button2->setXY(99, 557);
	exit_button2->setXY(902, 550);
	how_to_button2->setXY(661, 553);

	play_rc = { 449,583,160,61 };
	credit_rc = {136,582,210,55};
	home_rc = {39,33,115,110};
	exit_rc = {982,588,132,52};
	how_to_rc = { 695,583,224,53 };

	credit_scene = false;
	how_to_scene = false;


	play_up	  = false;
	credit_up = false;
	how_to_up = false;
	exit_up	  = false;



	return true;
}
void Title::update(SDL_Event evnt,PHASE *phase)
{
	Tool::update(evnt);

	play_up = false;
	credit_up = false;
	how_to_up = false;
	exit_up = false;

	if (credit_scene == false &&
		how_to_scene == false)
	{
		if (SDL_PtInRect(&play_rc, _ptMouse))
		{
			play_up = true;
		}
		else if (SDL_PtInRect(&credit_rc, _ptMouse))
		{
			credit_up = true;
		}
		else if (SDL_PtInRect(&exit_rc, _ptMouse))
		{
			exit_up = true;
		}
		else if (SDL_PtInRect(&how_to_rc, _ptMouse))
		{
			how_to_up = true;
		}
	}
	switch (evnt.type)
	{
	case SDL_MOUSEBUTTONDOWN:
	{
		printf("x:%d    y:%d\n", _ptMouse.x, _ptMouse.y);
		SDL_Rect rc;

		if (SDL_PtInRect(&play_rc, _ptMouse))
		{
			play_up = true;
			*phase = INGAME;
			

		}
		else if (SDL_PtInRect(&credit_rc, _ptMouse))
		{
			credit_up = true;
			credit_scene = true;
	
		}
		else if (SDL_PtInRect(&home_rc, _ptMouse) && (credit_scene || how_to_scene))
		{
			credit_scene = false;
			how_to_scene = false;
		}
		else if (SDL_PtInRect(&exit_rc, _ptMouse))
		{
			exit_up = true;
			*phase = EXIT;
		}
		else if (SDL_PtInRect(&how_to_rc, _ptMouse))
		{
			how_to_up = true;
			how_to_scene = true;
	
		}
		break;
	}
	case SDL_MOUSEBUTTONUP:
	{
		break;
	}

	}

}
void Title::render(SDL_Surface *pScreenSurface)
{
	IMAGEMANAGER->findImage("타이틀")->render(pScreenSurface);

	play_button->render(pScreenSurface);
	credit_button->render(pScreenSurface);
	
	exit_button->render(pScreenSurface);
	how_to_button->render(pScreenSurface);

	
	if (credit_scene)
	{
		IMAGEMANAGER->findImage("크레딧")->render(pScreenSurface);
	}
	if (how_to_scene)
	{
		IMAGEMANAGER->findImage("하우투")->render(pScreenSurface);
	}
	if (credit_scene || how_to_scene)
	{
		home_button->render(pScreenSurface);
	}
	if (play_up)
	{
		play_button2->render(pScreenSurface);
	}
	if (how_to_up)
	{
		how_to_button2->render(pScreenSurface);
	}
	if (credit_up)
	{
		credit_button2->render(pScreenSurface);
	}
	if (exit_up)
	{
		exit_button2->render(pScreenSurface);
	}


}
void Title::release()
{
	
}