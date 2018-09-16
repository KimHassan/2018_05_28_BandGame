#pragma once

enum Song
{
	NONE,
	ROMANCE,
	WITHYOU,
	TALES,
	DUGGY1,
	DUGGY2

};
class InGame : public Tool
{
private:
	SDL_Rect home_rc;
	SDL_Rect mouse;
	

	image *pause_button;
	SDL_Rect pause_rect;
	int count;
	int frame;
	int frame2;
	bool pause_button_up;
	bool isPaused;
	image *song;
	image *home;
	Song list;


	SDL_Rect Romance_rc;
	SDL_Rect With_you_rc;
	SDL_Rect tales_rc;
	SDL_Rect duggy1_rc;
	SDL_Rect duggy2_rc;

	image* Romance_img;
	image* With_you_img;
	image* tales_img;
	image* duggy1_img;
	image* duggy2_img;

	image* guitar;
	image* hamonica;
	image* spin;
	image* jump;
	image* queen;

	DWORD oldT;
	DWORD currentT;
	

	int guitar_frame;
	int hamonica_frame;
	int spin_frame;
	int jump_frame;
	int queen_frame;


public:
	InGame();
	~InGame();
	bool init();
	void update(SDL_Event evnt, PHASE *phase);
	void render(SDL_Surface *pScreenSurface);
	void start();
	void updateRomance();
	void updateWithYou();
	void updateTales();
	void updateDuggy1();
	void updateDuggy2();
	void release();
	void phaseChange();
	void animation(bool queen, bool spin, bool jump, bool guitar, bool hamo,int f);
};

