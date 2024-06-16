#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	srand(time(NULL));
	m_bg.init();
	m_cat.init();
	for (int i = 0; i < 4; i++) {
		m_asteroid[i].init(rand() % 3, 3000 + 750 * i, rand() % 2000 - 500, rand() % 360);
	}
	distance = 0;
}

void Game::update()
{
	distance+=m_cat.vel.x;
	m_bg.update();
	m_cat.update();
	for (int i = 0; i < 4; i++) {
		if (m_asteroid[i].pos.x <= ASTEROID_DESPAWN) {
			m_asteroid[i].exit();
			m_asteroid[i].init(rand()%3, 3000, rand()%2000-500, rand()%360);	
		}
		m_asteroid[i].update();
	}
	
}

void Game::draw()
{
	m_bg.draw();
	m_cat.draw();
	for (int i = 0; i < 4; i++) {
		m_asteroid[i].draw();
	}
	
}

void Game::exit()
{
	m_bg.exit();
	m_cat.exit();
	for (int i = 0; i < 4; i++) {
		m_asteroid[i].exit();
	}
}
