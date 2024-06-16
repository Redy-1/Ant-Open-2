#pragma once

#include "Engine.h"

class Asteroid {
public:
	Asteroid();
	~Asteroid();

	void init(int,int,int);
	void update();
	void draw();
	void exit();

	SDL_Rect pos;
	SDL_Rect hitbox;
	SDL_Texture* txt;

	int mass;
	int angle;

	SDL_Rect calc_hitbox();
};