#include "grid.h"
#include "World.h"
#include "InputManager.h"

extern World world;

#include <iostream>
using namespace std;


int Grid::c_pos = 0;
int Grid::r_pos = 0;




Grid::Grid() {

}
Grid::~Grid() {

}

void Grid::createGrid() {


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr_tiles[i][j].init(i,j);
		}
	}
}



void Grid::update() {
	///cout << r_pos << "  " << c_pos << endl;
	r_pos = (InputManager::m_mouseCoor.y - ((SCREEN_H - 5 * TILE_S) / 2)) / TILE_S;
	c_pos = (InputManager::m_mouseCoor.x - ((SCREEN_W - 5 * TILE_S) / 2)) / TILE_S;
	if (InputManager::m_mouseIsPressed) {
		//cout << "AAAAA" << endl;
		card_is_selected = false;
		for (int i = 0; i < 5; i++) {
			r_pos = (InputManager::m_mouseCoor.y - ((SCREEN_H - 5 * TILE_S) / 2)) / TILE_S;
			c_pos = (InputManager::m_mouseCoor.x - ((SCREEN_W - 5 * TILE_S) / 2)) / TILE_S;


			/*
			cout <<"row: " << m_team1_pawns[i].m_tile->t_r << "   " << r_pos << endl;
			cout <<"col: " << m_team1_pawns[i].m_tile->t_c << "   " << c_pos << endl;
			*/

			if (InputManager::m_mouseCoor.y > card[ra_card[i]].m_rect.y && InputManager::m_mouseCoor.y < card[ra_card[i]].m_rect.y + m_CARD_HEIGHT &&
				InputManager::m_mouseCoor.x>card[ra_card[i]].m_rect.x && InputManager::m_mouseCoor.x < card[ra_card[i]].m_rect.x + m_CARD_WIDTH) {
				//card_is_selected
				cout << "You are on " << card[ra_card[i]].pos << endl;
				if (pawn_is_selected) {
					for (int k = 0; k < 5; k++) {
						for (int j = 0; j < 5; j++) {
							arr_tiles[k][j].available = false;
						}
					}
					card_is_selected = true;
					int r = last_selected->m_tile->t_r;
					int c = last_selected->m_tile->t_c;
					//cout << r << " " << c << endl;
					for (int j = 0; j < card[ra_card[i]].m_offset.size(); j++) {
						int temp_r;
						int temp_c;
						if (card[ra_card[i]].pos < 3) {
							temp_r = r + card[ra_card[i]].m_offset[j].first;
							temp_c = c + card[ra_card[i]].m_offset[j].second;
						}
						else {
							temp_r = r - card[ra_card[i]].m_offset[j].first;
							temp_c = c - card[ra_card[i]].m_offset[j].second;
						}
						
						//cout << temp_r << " " << temp_c << endl;
						arr_tiles[temp_r][temp_c].available = true;
					}
				}
			}
			if (InputManager::m_mouseCoor.y > (SCREEN_H-5*TILE_S)/2 && InputManager::m_mouseCoor.y < (SCREEN_H - 5 * TILE_S) / 2 + 5*TILE_S &&
				InputManager::m_mouseCoor.x >(SCREEN_W - 5 * TILE_S) / 2 && InputManager::m_mouseCoor.x < (SCREEN_W - 5 * TILE_S) / 2 + 5 * TILE_S) {
				//cout << "You are in pole" << endl;
				if (m_team1_pawns[i].m_tile->t_r == r_pos && m_team1_pawns[i].m_tile->t_c == c_pos && !pawn_is_selected) {
					//cout << "here" << endl;
					//cout << m_team1_pawns[i].m_tile->t_r << " " << m_team1_pawns[i].m_tile->t_c << " i: " << i << endl;

					pawn_is_selected = true;
					last_selected = &m_team1_pawns[i];
					m_team1_pawns[i].m_tile->m_selected = true;

					break;
				}
				if (m_team2_pawns[i].m_tile->t_r == r_pos && m_team2_pawns[i].m_tile->t_c == c_pos && !pawn_is_selected) {
					//cout << "here" << endl;
					pawn_is_selected = true;
					m_team2_pawns[i].m_tile->m_selected = true;
					last_selected = &m_team2_pawns[i];
					break;
				}
				
				if (pawn_is_selected) {
					//cout << "LastSelecte1: " << last_selected << " LastSelected2 " << last_selected << endl;
					int r = last_selected->m_tile->t_r;
					int c = last_selected->m_tile->t_c;
					if (arr_tiles[r][c].available) {
						cout << "MOVED" << endl;
						turn = !turn;
						last_selected->m_tile = &arr_tiles[r_pos][c_pos];

						last_selected->m_tile->m_selected = false;
						pawn_is_selected = false;
						break;
						
					}
					else{
						pawn_is_selected = false;
					}
					for (int k = 0; k < 5; k++) {
						for (int j = 0; j < 5; j++) {
							arr_tiles[k][j].available = false;
						}
					}
				}
			}				
		}
	}
}