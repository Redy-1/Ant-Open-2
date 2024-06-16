#pragma once

#include "Engine.h"
#include "Cat.h"

class Game {
public:
	Game();
	~Game();

	void init();
	void update();
	void draw();
	void exit();

	Cat m_cat;
};