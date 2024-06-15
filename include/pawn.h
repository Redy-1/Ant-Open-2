#pragma once

#include "SDL.h"
#include "tile.h"

class Pawn {
public:
	Pawn();
	~Pawn();

	void p_init();
	void update();

	//bool m_team = 0;//0 - team1, 1 -team2
	bool m_alive = 1;

	Tile* m_tile;

};