#include "tile.h"


void Tile::init(int i,int j) {

	m_rect.x = ((SCREEN_W - 5 * TILE_S) / 2) + j * TILE_S;
	m_rect.y = ((SCREEN_H - 5 * TILE_S) / 2) + i * TILE_S;
	m_rect.w = TILE_S;
	m_rect.h = TILE_S;
	t_r = i;
	t_c = j;
}

Tile::Tile() {

}
Tile::~Tile() {
}