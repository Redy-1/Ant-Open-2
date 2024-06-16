#include "FuelBar.h"
#include "World.h"

extern World world;

FuelBar::FuelBar()
{
}

FuelBar::~FuelBar()
{
}

void FuelBar::init()
{
	pos = { 30,800,130,270 };
	frame_txt = loadTexture("fuelbar.bmp");
}

void FuelBar::update()
{
	
}

void FuelBar::draw()
{
	int height = (float)world.m_game.m_cat.fuel / world.m_game.m_cat.maxFuel * 270;
	SDL_Rect pos2 = pos;
	pos2.h = height;
	pos2.y += (270 - height);
	SDL_RenderFillRect(Presenter::m_main_renderer, &pos2);

	Drawable tmp;
	tmp.texture = frame_txt;
	tmp.drect = pos;
	drawObject(tmp);
}

void FuelBar::exit()
{
	SDL_DestroyTexture(frame_txt);
}
