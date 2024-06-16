#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	m_cat.init();
}

void Game::update()
{
	m_cat.update();
}

void Game::draw()
{
	m_cat.draw();
}

void Game::exit()
{
	m_cat.exit();
}
