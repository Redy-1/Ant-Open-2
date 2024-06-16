#pragma once

#include "SDL.h"

class World {
public:
	World();
	~World();

	bool m_run;

	


	SDL_Window* m_mainWindow;
	SDL_Renderer* m_mainRenderer;

	SDL_Texture* m_backgroundTexture;
	SDL_Texture* m_Test;

	SDL_Rect m_rect;

	void init();
	void update();
	void draw();
	void exit();
	//void mouse_pos();

	void initSDL();
	void improveRenderer();
};
