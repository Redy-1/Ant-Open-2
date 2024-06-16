#include "Asteroid.h"
#include "Presenter.h"
#include "World.h"

extern World world;

Asteroid::Asteroid()
{
}

Asteroid::~Asteroid()
{
}

void Asteroid::init(int size,int pos_y,int ang)
{
	switch (size) {
	case 0: 
		txt = loadTexture("asteroid1.bmp");
		pos = { 3000,pos_y,430,347 };
		mass = 20;
		hitbox = { 0,0,420,337 };
		break;
	case 1:
		txt = loadTexture("asteroid2.bmp");
		pos = { 3000,pos_y,313,280 };
		mass = 15;
		hitbox = { 0,0,300,260 };
		break;
	case 2:
		txt = loadTexture("asteroid3.bmp");
		pos = { 3000,pos_y,225,225 };
		mass = 10;
		hitbox = { 0,0,215,215 };
		break;
	}
	angle = 0;
	hitbox = calc_hitbox();
}

void Asteroid::update()
{
	int2 vel = world.m_game.m_cat.vel;
	pos.x -= vel.x;
	pos.y -= vel.y;
	hitbox = calc_hitbox();
}

void Asteroid::draw()
{
	Drawable tmp;
	tmp.texture = txt;
	tmp.drect = pos;
	tmp.angle = angle;
	drawObject(tmp);
	if (DEBUG) {
		SDL_SetRenderDrawColor(Presenter::m_main_renderer, 255, 0, 0, 1);
		SDL_RenderDrawRect(Presenter::m_main_renderer, &hitbox);
	}
}

void Asteroid::exit()
{
	SDL_DestroyTexture(txt);
}

SDL_Rect Asteroid::calc_hitbox() {
	SDL_Rect tmp = pos;
	tmp.x += (pos.w - hitbox.w) / 2;
	tmp.y += (pos.h - hitbox.h) / 2;
	tmp.w = hitbox.w;
	tmp.h = hitbox.h;
	return tmp;
}
