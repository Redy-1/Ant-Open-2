#include "GameBackground.h"
#include "Presenter.h"
#include "World.h"

extern World world;

GameBackground::GameBackground()
{
}

GameBackground::~GameBackground()
{
}

void GameBackground::init()
{
	stars_txt = loadTexture("stars.bmp");
	planet_txt = loadTexture("planets.bmp");
}

void GameBackground::update()
{
	star_pos = { int(world.m_game.distance * scrollMult) % STARS_WIDTH,0,STARS_WIDTH,STARS_HEIGTH };
}

void GameBackground::draw()
{
	Drawable tmp;
	tmp.texture = stars_txt;
	tmp.drect = { 0,0,(int)Presenter::m_SCREEN_WIDTH,(int)Presenter::m_SCREEN_HEIGHT };
	tmp.srect = star_pos;
	drawObject(tmp);
}

void GameBackground::exit()
{
	SDL_DestroyTexture(stars_txt);
	SDL_DestroyTexture(planet_txt);
}
