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
	distance = 10000;
}

void Game::update()
{
	distance+=m_cat.vel.x;
	m_bg.update();
	m_cat.update();
}

void Game::draw()
{
	m_bg.draw();
	m_cat.draw();
}

void Game::exit()
{
	m_bg.exit();
	m_cat.exit();
}
