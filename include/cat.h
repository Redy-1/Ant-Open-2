#pragma once

#include "Engine.h"

class Cat {
public:
	Cat();
	~Cat();

	static const int CAT_WIDTH = 63;
	static const int CAT_HEIGHT = 138;
	static const int CAT_HITBOX_WIDTH = 63;
	static const int CAT_HITBOX_HEIGHT = 138;

	SDL_Rect pos;
	SDL_Rect hitbox;
	int angle;

	SDL_Texture* txt;
	int sprite;
	int timer;

	float2 vel;

	void init();
	void update();
	void draw();
	void exit();

	void getFuel();
	SDL_Rect calc_hitbox();

private:
	int fuel;
	const int maxFuel = 100;
};