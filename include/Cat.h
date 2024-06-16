#pragma once

#include "Engine.h"

class Cat {
public:
	Cat();
	~Cat();

	void init();
	void update();
	void draw();
	void exit();

	static const int CAT_WIDTH = 138;
	static const int CAT_HEIGHT = 63;
	static const int CAT_HITBOX_WIDTH = 138;
	static const int CAT_HITBOX_HEIGHT = 63;

	SDL_Rect pos;
	SDL_Rect hitbox;
	int angle;

	SDL_Texture* txt;
	int sprite;
	int timer;

	float2 vel;
	bool boosting;

	void getFuel();
	SDL_Rect calc_hitbox();

	const int BOOST_VEL = 10;
	const int D_ANGLE = 1;
	void boost();
	void turn(bool);

private:
	int fuel;
	const int maxFuel = 100;
};