#include "World.h"
#include "InputManager.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;


World::World()
{

}

World::~World()
{

}

void World::draw() {
	SDL_RenderCopy(m_mainRenderer, m_backgroundTexture, NULL, NULL);

	SDL_RenderPresent(m_mainRenderer);
} 

void World::exit() {

}
void World::update() {
	InputManager::mouse_pos();

	//cout << InputManager::m_mouseCoor.x << "   " << InputManager::m_mouseCoor.y << endl;
}
void World::init() {
	initSDL();
	m_run = true;
}
void World::initSDL() {
	m_mainWindow = SDL_CreateWindow("GameName",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, 0);
	
	m_mainRenderer = SDL_CreateRenderer(m_mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	//SDL_SetWindowFullscreen(m_mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

	improveRenderer();
}

void World::improveRenderer()
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);

	auto desktopWidth = DM.w;
	auto desktopHeight = DM.h;

	if (SDL_SetWindowFullscreen(m_mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP) < 0)
	{
		cout << "SDL_IMPROVE_RENDERER FAILED: %s\n" << SDL_GetError() << endl;
	}

	SDL_RenderSetLogicalSize(m_mainRenderer, SCREEN_W, SCREEN_H);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
}