#pragma once

#include "SDL.h"
#include "defines.h"

class Cat {
public:
	Cat();
	~Cat();

	

	SDL_Rect m_pos;
	double m_angle;
	
	int2 m_vel;

	void init();
	void update();
	void draw();
	void exit();

	void getFuel();

private:
	int fuel;
	const int maxFuel = 100;
};