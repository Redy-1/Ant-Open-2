#pragma once
#include "defines.h"
#include <iostream>
#include <vector>
#include "SDL.h"
using namespace std;

class Card {
public:
	Card();
	~Card();

	vector <pair<int, int>> m_offset;
	int pos;//0-l_u, 1-l_d, 2-to_go_left, 3-r_u, 4-r_d, 5-to_go_right
	string m_name;

	SDL_Rect m_rect;
	SDL_Texture* m_texture;
	SDL_Texture* m_r_texture;
};
