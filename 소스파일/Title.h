#pragma once

class Title : public Tool
{
private:
	SDL_Surface* cursor;
	image* play_button;
	image* credit_button;
	image* home_button;
	image* exit_button;
	image* how_to_button;
	image* play_button2;
	image* credit_button2;
	image* exit_button2;
	image* how_to_button2;
	SDL_Rect play_rc;
	SDL_Rect credit_rc;
	SDL_Rect home_rc;
	SDL_Rect exit_rc;
	SDL_Rect how_to_rc;

	bool play_up;
	bool credit_up;
	bool how_to_up;
	bool exit_up;

	bool credit_scene;
	bool how_to_scene;



	bool click;
public:
	bool init();
	void update(SDL_Event evnt, PHASE *phase);
	void render(SDL_Surface *pScreenSurface);
	void release();
	Title();
	~Title();
};

