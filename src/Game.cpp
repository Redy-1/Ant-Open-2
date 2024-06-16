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
	m_asteroid.init(0);
	distance = 1000000;
}

void Game::update()
{
	distance+=m_cat.vel.x;
	m_bg.update();
	m_cat.update();
	m_asteroid.update();
}

void Game::draw()
{
	m_bg.draw();
	m_cat.draw();
	m_asteroid.draw();
}

void Game::exit()
{
	m_bg.exit();
	m_cat.exit();
	m_asteroid.exit();
}
