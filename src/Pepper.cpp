#include "Pepper.h"
#include "World.h"

extern World world;

Pepper::Pepper()
{
}

Pepper::~Pepper()
{
}

void Pepper::init(int pos_x, int pos_y)
{
	pos = { 0,0,500,500 };
	pos.x = pos_x;
	pos.y = pos_y;
	hitbox = { 0,0,500,500 };
	hitbox = calc_hitbox();
	txt = loadTexture("pepper.bmp");
}

void Pepper::update()
{
	int2 vel = world.m_game.m_cat.vel;
	pos.x -= vel.x;
	pos.y -= vel.y;
	hitbox = calc_hitbox();

	if (collRectRect(hitbox, world.m_game.m_cat.hitbox)) world.m_game.m_cat.getFuel();
}

void Pepper::draw()
{
	Drawable tmp;
	tmp.texture = txt;
	tmp.drect = pos;
	tmp.srect = { 0,0,500,500 };
	drawObject(tmp);
	if (DEBUG) {
		SDL_SetRenderDrawColor(Presenter::m_main_renderer, 255, 0, 0, 1);
		SDL_RenderDrawRect(Presenter::m_main_renderer, &hitbox);
	}
}

void Pepper::exit()
{
}

SDL_Rect Pepper::calc_hitbox()
{
	SDL_Rect tmp = pos;
	tmp.x += (pos.w - hitbox.w) / 2;
	tmp.y += (pos.h - hitbox.h) / 2;
	tmp.w = hitbox.w;
	tmp.h = hitbox.h;
	return tmp;
}
