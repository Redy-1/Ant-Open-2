#pragma once

#include "Engine.h"

class GameBackground {
public:
	GameBackground();
	~GameBackground();

	void init();
	void update();
	void draw();
	void exit();

	const float scrollMult = 0.05;

	const int STARS_WIDTH = 540;
	const int STARS_HEIGTH = 360;
	SDL_Texture* stars_txt;
	SDL_Texture* planet_txt;
	SDL_Rect star_pos;


};