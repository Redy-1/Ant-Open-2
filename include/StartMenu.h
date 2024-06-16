#pragma once
#include "Engine.h"

class Menu {
public:
	SDL_Rect m_background_rect;
	SDL_Texture* m_background_texture;

	SDL_Rect m_title_rect;
	SDL_Texture* m_title_texture;

	SDL_Rect m_quit_rect;
	SDL_Texture* m_quit_texture;

	SDL_Rect m_play_rect;
	SDL_Texture* m_play_texture;

	void init_play();
	void init_quit();
	void init_title();
	void init_background();

	void init_all();

	void draw_quit();
	void draw_play();
	void draw_title();
	void draw_background();

	void draw_all();
};