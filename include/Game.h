#pragma once

#include "Engine.h"
#include "Cat.h"
#include "GameBackground.h"
#include "Asteroid.h"

class Game {
public:
	Game();
	~Game();

	void init();
	void update();
	void draw();
	void exit();

	GameBackground m_bg;
	Cat m_cat;
	int distance;

	Asteroid m_asteroid[5];
	const int ASTEROID_DESPAWN = -1000;
};