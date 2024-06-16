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
	SDL_Rect star_pos;

	SDL_Texture* planet_txt;
	int curr_planet;
	const int PLANET_SCREEN_DIST = 3000;
	SDL_Rect planet_txt_pos[6] = {
		{59,202,100,100},
		{196,202,100,100},
		{333,202,100,100},
		{59,352,100,100},
		{296,352,100,100},
		{333,352,100,100},
	};
	int planet_appear[6] = { -100, 30000, 100000, 400000, 800000, 1500000 };
	int planet_dist[6] = { 10000, 20000, 50000, 100000, 300000, 600000 };

};