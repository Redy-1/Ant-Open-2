#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	m_bg.init();
	m_cat.init();
	for (int i = 0; i < 10; i++) {
		m_asteroid[i].init(0,0,0);
	}
	distance = 0;
}

void Game::update()
{
	distance+=m_cat.vel.x;
	cout << distance << endl;
	m_bg.update();
	m_cat.update();
	for (int i = 0; i < 10; i++) {
		if (m_asteroid[i].pos.x <= ASTEROID_DESPAWN) {
			m_asteroid[i].exit();
			m_asteroid[i].init(0,0,0);
			m_asteroid[i].update();
		}
	}
	
}

void Game::draw()
{
	m_bg.draw();
	m_cat.draw();
	for (int i = 0; i < 10; i++) {
		m_asteroid[i].draw();
	}
	
}

void Game::exit()
{
	m_bg.exit();
	m_cat.exit();
	for (int i = 0; i < 10; i++) {
		m_asteroid[i].exit();
	}
}
