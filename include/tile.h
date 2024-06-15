#pragma once
#include "defines.h"
#include "SDL.h"
#include <iostream>

class Tile {
public:
	Tile();
	~Tile();

	void init(int i, int j);

	bool m_selected = true;
	bool available = false;

	SDL_Rect m_rect;
	SDL_Texture* m_texture;
	SDL_Texture* m_texture_available;


	//cout << m_rect.x << "  " << m_rect.y << endl;
	int t_r;
	int t_c;

	//r_pos = (InputManager::m_mouseCoor.y - ((SCREEN_H - 5 * TILE_S) / 2)) / TILE_S;
	//c_pos = (InputManager::m_mouseCoor.x - ((SCREEN_W - 5 * TILE_S) / 2)) / TILE_S;

	

};