#include "stdafx.h"


InGame::InGame()
{
}


InGame::~InGame()
{

}
bool InGame::init()
{
	home_rc = { 10,13,136,95 };
	home = new image;
	home = IMAGEMANAGER->findImage("홈버튼2");
	home->setXY(10, 13);
	mouse = { 10,10,10,10 };
	pause_rect = { 414,568,256,71 };
	pause_button = new image;
	pause_button = IMAGEMANAGER->findImage("일시정지버튼");
	pause_button->setXY(411, 575);
	song = IMAGEMANAGER->findImage("곡");
	song->setXY(WINSIZEX  - 330, 0);

	Romance_rc = { song->getX() ,127,330,94 };
	With_you_rc = { song->getX() ,260,330,114 };
	tales_rc = { song->getX(), 372,329,112 };
	duggy1_rc = { song->getX() ,483,330,114 };
	duggy2_rc = { song->getX() , 608,330,112 };

	Romance_img		= IMAGEMANAGER->findImage("로맨스");
	With_you_img	 = IMAGEMANAGER->findImage("윗유");
	tales_img	= IMAGEMANAGER->findImage("하늘에닿는시");
	duggy1_img	 = IMAGEMANAGER->findImage("망각");
	duggy2_img	 = IMAGEMANAGER->findImage("슈팅스타");

	Romance_img->setXY(song->getX(), 129);
	With_you_img->setXY(song->getX(), 246);
	tales_img->setXY(song->getX(), 372);
	duggy1_img->setXY(song->getX(), 501); 
	duggy2_img->setXY(song->getX(), 620);

	guitar   = IMAGEMANAGER->findImage("기타");
	hamonica = IMAGEMANAGER->findImage("피리"); 
	spin	 = IMAGEMANAGER->findImage("스핀발레");
	jump	 = IMAGEMANAGER->findImage("발레");
	queen	 = IMAGEMANAGER->findImage("퀸");

	guitar->setXY(510, 33);
	hamonica->setXY(-25, 172);
	spin->setXY(380, 45);
	jump->setXY(0, 0);
	queen->setXY(185, 0);

	guitar_frame = 0;
	hamonica_frame = 0;
	spin_frame = 0;
	jump_frame = 0;

	queen_frame = 0;

	count = 0;
	frame = 0;

	return true;
}
void InGame::update(SDL_Event evnt, PHASE *phase)
{

	Tool::update(evnt);



	//노래 재생과 애니메이션 프레임 변경
	if (!isPaused)
	{
		count++;
		switch (list)
		{
		case NONE:
		{
			break;
		}
		case ROMANCE:
		{
			updateRomance();
			break;
		}
		case WITHYOU:
		{
			updateWithYou();
			break;
		}
		case TALES:
		{
			updateTales();
			break;
		}
		case DUGGY1:
		{
			updateDuggy1();
			break;
		}
		case DUGGY2:
		{
			updateDuggy2();
			break;
		}
		}
	}
	//노래 재생과 프레임 돌리기 끝

	//puase버튼
	if (isPaused)
	{
		pause_button->setFrameX(1);
	}
	else
	{

		if (SDL_PtInRect(&pause_rect, _ptMouse))
		{
			pause_button->setFrameX(2);
			pause_button_up = true;
		}
		else
		{
			pause_button->setFrameX(0);
			pause_button_up = false;
		}
	}
	//pause버튼 끝

	//노래 마우스 충돌시 아웃레이
	if (SDL_PtInRect(&Romance_rc, _ptMouse))
	{
		Romance_img->setFrameX(1);
	}

	else
	{
		Romance_img->setFrameX(0);
	}
	if (SDL_PtInRect(&With_you_rc, _ptMouse))
	{
		With_you_img->setFrameX(1);
	}
	else
	{
		With_you_img->setFrameX(0);
	}
	if (SDL_PtInRect(&tales_rc, _ptMouse))
	{
		tales_img->setFrameX(1);
	}
	else
	{
		tales_img->setFrameX(0);
	}
	if (SDL_PtInRect(&duggy1_rc, _ptMouse))
	{
		duggy1_img->setFrameX(1);
	}
	else
	{
		duggy1_img->setFrameX(0);
	}
	if (SDL_PtInRect(&duggy2_rc, _ptMouse))
	{
		duggy2_img->setFrameX(1);
	}
	else
	{
		duggy2_img->setFrameX(0);
	}
	if (SOUNDMANAGER->isPlaySound("로맨스"))
	{
		Romance_img->setFrameX(2);
		list = ROMANCE;
	}
	if (SOUNDMANAGER->isPlaySound("윗유"))
	{
		With_you_img->setFrameX(2);
		list = WITHYOU;
	}
	if (SOUNDMANAGER->isPlaySound("하늘에닿는시"))
	{
		tales_img->setFrameX(2);
		list = TALES;
	}
	if (SOUNDMANAGER->isPlaySound("망각"))
	{
		duggy1_img->setFrameX(2);
		list = DUGGY1;
	}
	if (SOUNDMANAGER->isPlaySound("슈팅스타"))
	{
		duggy2_img->setFrameX(2);
		list = DUGGY2;
	}
	//노래 아웃레이 끝

	//노래 실행
	switch (evnt.type)
	{

		case SDL_MOUSEBUTTONDOWN:
		{
			printf("%d\n", count);

			if (SDL_PtInRect(&home_rc, _ptMouse))
			{
				isPaused = false;
				SOUNDMANAGER->Allstop();
				start();
				
				*phase = TITLE;
			}
			if (SDL_PtInRect(&Romance_rc, _ptMouse))
			{

				Romance_img->setFrameX(2);
				
				isPaused = false;
					start();
					SOUNDMANAGER->Allstop();
					SOUNDMANAGER->play("로맨스");
				
				
			}
			if (SDL_PtInRect(&With_you_rc, _ptMouse))
			{
				isPaused = false;
				
				With_you_img->setFrameX(2);
				start();
				SOUNDMANAGER->Allstop();
				SOUNDMANAGER->play("윗유");
			}
			if (SDL_PtInRect(&tales_rc, _ptMouse))
			{
				isPaused = false;
				
				tales_img->setFrameX(2);
				start();
				SOUNDMANAGER->Allstop();
				SOUNDMANAGER->play("하늘에닿는시");
			}
			if (SDL_PtInRect(&duggy1_rc, _ptMouse))
			{
				isPaused = false;
				
				duggy1_img->setFrameX(2);
				start();
				SOUNDMANAGER->Allstop();
				SOUNDMANAGER->play("망각");
			}
			if (SDL_PtInRect(&duggy2_rc, _ptMouse))
			{
				isPaused = false;
				
				duggy2_img->setFrameX(2);
				start();
				SOUNDMANAGER->Allstop();
				SOUNDMANAGER->play("슈팅스타");
			}
			if (SDL_PtInRect(&pause_rect, _ptMouse))
			{
				if (isPaused == false)
				{
					isPaused = true;
					switch (list)
					{
					case ROMANCE:
					{
						SOUNDMANAGER->pause("로맨스");
						break;
					}
					case WITHYOU:
					{
						SOUNDMANAGER->pause("윗유");
						break;
					}
					case TALES:
					{
						SOUNDMANAGER->pause("하늘에닿는시");
						break;
					}
					case DUGGY1:
					{
						SOUNDMANAGER->pause("망각");
						break;
					}
					case DUGGY2:
					{
						SOUNDMANAGER->pause("슈팅스타");
						break;
					}
					}
				}
				else
				{
					isPaused = false;
					switch (list)
					{
					case NONE:
					{
						break;
					}
					case ROMANCE:
					{
						SOUNDMANAGER->resume("로맨스");
						break;
					}
					case WITHYOU:
					{
						SOUNDMANAGER->resume("윗유");
						break;
					}
					case TALES:
					{
						SOUNDMANAGER->resume("하늘에닿는시");
						break;
					}
					case DUGGY1:
					{
						SOUNDMANAGER->resume("망각");
						break;
					}
					case DUGGY2:
					{
						SOUNDMANAGER->resume("슈팅스타");
						break;
					}
					}
				}
			}
		}
	}
	//노래 실행 끝

	//애니메이션 돌리기
	guitar->setFrameX(guitar_frame);
	spin->setFrameX(spin_frame);
	jump->setFrameX(jump_frame);
	queen->setFrameX(queen_frame);
	hamonica->setFrameX(hamonica_frame);
	//애니 실행끝
}
void InGame::render(SDL_Surface *pScreenSurface)
{

	//IMAGEMANAGER->findImage("인게임")->render(pScreenSurface);
	IMAGEMANAGER->findImage("인게임")->render(pScreenSurface);

	song->render(pScreenSurface);
	Romance_img->frameRender(pScreenSurface);
	With_you_img ->frameRender(pScreenSurface);
	tales_img	 ->frameRender(pScreenSurface);
	duggy1_img	 ->frameRender(pScreenSurface);
	duggy2_img	 ->frameRender(pScreenSurface);

	queen	 ->frameRender(pScreenSurface);
	guitar	 ->frameRender(pScreenSurface);
	spin	 ->frameRender(pScreenSurface);
	jump	 ->frameRender(pScreenSurface);
	hamonica->frameRender(pScreenSurface);
	pause_button->frameRender(pScreenSurface);

	if (SDL_PtInRect(&home_rc, _ptMouse))
	{
		home->render(pScreenSurface);
	}
	

}
void InGame::release()
{

}

void InGame::start()
{
	count = 0;
	guitar->setFrameX(0);
	hamonica->setFrameX(0);
	spin->setFrameX(0);
	jump->setFrameX(0);
	queen->setFrameX(0);
	guitar_frame= 0;
	hamonica_frame= 0;
	spin_frame= 0;
	jump_frame= 0;
	queen_frame= 0;

}

void InGame::phaseChange()
{
	start();
	list = NONE;
}
void InGame::updateRomance()
{
	if ((count > 1 && count <28) || (count > 87 && count <= 87 + 27))
	{
		animation(true, false, false, false, false, 2);
	}

	if ((count >= 28 && count <= 48) || (count >= 28 + 87 && count <= 48 + 87))
	{
		animation(true, true, false, false, false, 2);
	}
	
	if ((count > 48 && count <= 69) || (count >= 48 + 87 && count <= 69 + 87))
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count > 69 && count <= 91) || (count > 69 + 87 && count <= 91 + 83))
	{
		animation(1, 1, 1, 1, 1, 2);
	}
	if ((count > 179 && count <= 195) || (count > 199 && count <= 215) || (count > 219 && count <= 235) || (count > 239 && count <= 255) || (count > 259 && count <= 275) || (count > 279 && count <= 295) || (count > 299 && count <= 315) || (count > 319 && count <= 335))
	{
		animation(0, 0, 0, 1, 1, 2);
	}
	if ((count > 350 && count <= 368))
	{
		animation(0, 1, 0, 0, 0, 2);
	}
	if ((count > 368 && count <= 388))
	{
		animation(1, 0, 0, 0, 0, 2);
	}
	if ((count > 388 && count <= 408))
	{
		animation(0, 0, 1, 0, 0, 2);
	}
	if ((count > 416 && count <= 431) || (count > 436 && count <= 453) || (count > 458 && count <= 473) || (count > 478 && count <= 498))
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if (count > 518)
	{
		int num1 = rand() % 2;
		int num2 = rand() % 2;
		int num3 = rand() % 2;
		int num4 = rand() % 2;
		int num5 = rand() % 2;
		animation(num1, num2, num3, num4, num5, 2);
	}

}

void InGame::updateWithYou()
{
	if ((count > 5 && count <53))
	{
		animation(1, 0, 0, 0, 0, 2);
	}
	if ((count > 53 && count <99))
	{
		animation(0, 1, 0, 0, 0, 2);
	}
	if ((count > 99 && count <122))
	{
		animation(0, 0, 1, 0, 0, 2);
	}
	if ((count > 122 && count <143))
	{
		animation(0, 0, 0, 1, 1, 2);
	}
	if ((count > 143 && count <170))
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count > 183 && count <230))
	{
		animation(1, 0, 0, 0, 0, 2);
	}
	if ((count > 230 && count <266))
	{
		animation(1, 0, 1, 0, 0, 2);
	}
	if ((count > 266 && count <308))
	{
		animation(0, 1, 1, 0, 0, 2);
	}
	if ((count > 308 && count <349))
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count > 349 && count <390))
	{
		animation(0, 0, 0, 1, 1, 2);
	}
	if ((count > 390 && count <431))
	{
		animation(1, 1, 1, 1, 1, 2);
	}
	if (count > 431)
	{
		int num1 = rand() % 2;
		int num2 = rand() % 2;
		int num3 = rand() % 2;
		int num4 = rand() % 2;
		int num5 = rand() % 2;
		animation(num1, num2, num3, num4, num5, 2);
	}
}

void InGame::updateTales()
{
	if ((count > 15 && count < 56))
	{
		animation(0, 0, 0, 1, 0, 2);
	}
	if ((count > 56 && count < 97))
	{
		animation(0, 0, 0, 0, 1, 2);
	}
	if ((count > 92 && count < 128))
	{
		animation(1, 0, 0, 0, 0, 2);
	}
	if ((count > 128 && count < 169))
	{
		animation(0, 1, 1, 0, 0, 2);
	}
	if ((count > 169 && count < 208))
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if (count > 208 && count < 247)
	{
		animation(0, 0, 0, 0, 1, 2);
	}
	if (count > 247 && count < 285)
	{
		animation(0, 0, 0, 1, 1, 2);
	}
	if (count > 286 && count < 328)
	{
		animation(1, 1, 1, 1, 1, 2);
	}
	if (count > 330 && count < 368)
	{
		animation(0, 0, 0, 0, 1, 2);
	}
	if (count > 368 && count < 408)
	{
		animation(0, 0, 0, 1, 0, 2);
	}
	if (count > 408 && count < 443)
	{
		animation(0, 1, 1, 0, 0, 2);
	}
	if (count > 443 && count < 485)
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if (count > 485)
	{
		int num1 = rand() % 2;
		int num2 = rand() % 2;
		int num3 = rand() % 2;
		int num4 = rand() % 2;
		int num5 = rand() % 2;
		animation(num1, num2, num3, num4, num5, 2);
	}
}

void InGame::updateDuggy1()
{

	if ((count > 15 && count < 93))
	{
		animation(0, 0, 0, 1, 0, 2);
	}
	if ((count > 93 && count < 132))
	{
		animation(0, 0, 0, 0, 1, 2);
	}
	if ((count > 132 && count < 168))
	{
		animation(0, 0, 0, 1, 0, 2);
	}
	if ((count > 168 && count < 206))
	{
		animation(0, 1, 0, 0, 0, 2);
	}
	if ((count > 206 && count < 243))
	{
		animation(0, 0, 1, 0, 0, 2);
	}
	if ((count > 243 && count < 281))
	{
		animation(1, 0, 0, 0, 0, 2);
	}
	if ((count > 281 && count < 319))
	{
		animation(0, 1, 1, 0, 0, 2);
	}
	if ((count > 319 && count < 357))
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count > 357 && count < 394))
	{
		animation(1, 0, 0, 0, 0, 2);
	}
	if ((count > 396 && count < 434))
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count > 472 && count < 509))
	{
		animation(1, 0, 0, 0, 0, 2);
	}
	if ((count > 511 && count < 549))
	{
		animation(0, 1, 1, 0, 0, 2);
	}
	if ((count == 550) && count < 553)
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count == 628) && count < 635)
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count == 664 && count < 670))
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count >= 811) && count <= 968)
	{
		animation(0, 0, 0, 1, 1, 2);
	}
	if (count > 968)
	{
		int num1 = rand() % 2;
		int num2 = rand() % 2;
		int num3 = rand() % 2;
		int num4 = rand() % 2;
		int num5 = rand() % 2;
		animation(num1, num2, num3, num4, num5, 2);
	}
}

void InGame::updateDuggy2()
{

	if ((count >= 24) && count <=74)
	{
		animation(1, 1, 1, 0, 0, 2);
	}

	if ((count >= 74) && count <= 123)
	{
		animation(0, 0, 0, 1, 0, 2);
	}
	if ((count >= 123) && count <= 172)
	{
		animation(0, 0, 0, 0, 1, 2);
	}
	if ((count >= 172) && count <= 196)
	{
		animation(1, 0, 0, 0, 0, 2);
	}
	if ((count >= 196) && count <= 220)
	{
		animation(0, 1, 1, 0, 0, 2);
	}
	if ((count >= 220) && count <= 270)
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count >= 270) && count <= 318)
	{
		animation(0, 0, 0, 1, 1, 2);
	}
	if ((count >= 318) && count <= 368)
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count >= 368) && count <= 392)
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count >= 416) && count <= 441)
	{
		animation(1, 1, 1, 1, 1, 2);
	}
	if ((count >= 441) && count <= 465)
	{
		animation(1, 0, 0, 0, 0, 2);
	}
	if ((count >= 465) && count <= 497)
	{
		animation(0, 1, 1, 0, 0, 2);
	}
	if ((count >= 497) && count <= 513)
	{
		animation(0, 0, 0, 1, 1, 2);
	}
	if ((count >= 513) && count <= 541)
	{
		animation(1, 1, 1, 0, 0, 2);
	}
	if ((count >= 564) && count <= 614)
	{
		animation(1, 1, 1, 1, 1, 2);
	}
	if (count > 614)
	{
		int num1 = rand() % 2;
		int num2 = rand() % 2;
		int num3 = rand() % 2;
		int num4 = rand() % 2;
		int num5 = rand() % 2;
		animation(num1, num2, num3, num4, num5, 2);
	}
}

void InGame::animation(bool queen,bool spin,bool jump,bool guitar,bool hamo,int f)
{
	if (queen)
	{
		if (count % f == 0)
		{
			queen_frame++;
			if (queen_frame >= 5)
			{
				queen_frame = 0;
			}
			
		}
	}
	if (spin)
	{
		if (count % f == 0)
		{
			spin_frame++;
			if (spin_frame >= 5)
			{
				spin_frame = 0;
			}
		}
	}
	if (jump)
	{
		if (count % f == 0)
		{
			jump_frame++;
			if (jump_frame >= 5)
			{
				jump_frame = 0;
			}
		}
	}
	if (guitar)
	{
		if (count % f == 0)
		{
			guitar_frame++;
			if (guitar_frame >= 5)
			{
				guitar_frame = 0;
			}
		}
	}
	if (hamo)
	{
		if (count % f == 0)
		{
			hamonica_frame++;
			if (hamonica_frame >= 5)
			{
				hamonica_frame = 0;
			}
		}
	}
}