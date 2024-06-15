#pragma once
#include "defines.h"
#include "SDL.h"
#include "pawn.h"
#include "tile.h"
#include "cards.h"

class Grid {
public: 
	Grid();
	~Grid();

	void update();

	static int c_pos;
	static int r_pos;

	Card card[9];
	int ra_card[5];

	bool pawn_is_selected = false;
	Pawn* last_selected;
	bool turn=true;

	Card* last_selected_card;
	bool card_is_selected = false;

	Pawn m_team1_pawns[5];
	Pawn m_team2_pawns[5];

	SDL_Texture* m_p1_texture;
	SDL_Texture* m_p2_texture;


	Tile arr_tiles[5][5];

	void createGrid();



};


