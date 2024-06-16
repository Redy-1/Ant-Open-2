#include "World.h"

World::World()
{
	m_isRunning = true;
}

World::~World()
{
}

void World::init()
{
	m_presenter.init();
	// menu.init_all();

	game_state = 0;
}

void World::run()
{
	m_inputManager.handleInput();
	m_presenter.draw();
}

// call destroy for all classes to prevent memory leak
void World::destroy()
{
	SDL_DestroyRenderer(m_presenter.m_main_renderer);

	SDL_DestroyWindow(m_presenter.m_main_window);
}

bool World::isRunning()
{
	return m_isRunning;
}

void World::quit()
{
	m_isRunning = false;
	destroy();
}
