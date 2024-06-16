#include "Cat.h"
#include "Presenter.h"
#include "InputManager.h"

Cat::Cat()
{
}

Cat::~Cat()
{
}

void Cat::init()
{
	pos = { 200,520,CAT_WIDTH,CAT_HEIGHT };
	angle = 0;
	vel = { 0,0 };
	txt = loadTexture("rocket.bmp");
	hitbox = calc_hitbox();
	sprite = 0;
	timer = 0;
}

void Cat::update()
{
	turn(1);
	timer++;
	if (timer >= 6) {
		sprite++;
		timer = 0;
		boost();
	}
	if (sprite == 3)sprite = 0;
	if (angle < 0) angle += 360;
	angle %= 360;
}

void Cat::draw()
{
	Drawable tmp;
	tmp.texture = txt;
	tmp.drect = pos;
	tmp.srect = { sprite * CAT_WIDTH,0,CAT_WIDTH,CAT_HEIGHT };
	tmp.angle = angle;
	drawObject(tmp);
	if (DEBUG) {
		SDL_SetRenderDrawColor(Presenter::m_main_renderer, 255, 0, 0, 1);
		SDL_RenderDrawRect(Presenter::m_main_renderer, &hitbox);
	}
}

void Cat::exit()
{
	SDL_DestroyTexture(txt);
}

void Cat::getFuel()
{
}

SDL_Rect Cat::calc_hitbox()
{
	SDL_Rect tmp = pos;
	tmp.x += (CAT_WIDTH - CAT_HITBOX_WIDTH) / 2;
	tmp.y += (CAT_HEIGHT - CAT_HITBOX_HEIGHT) / 2;
	tmp.w = CAT_HITBOX_WIDTH;
	tmp.h = CAT_HITBOX_HEIGHT;
	return tmp;
}

void Cat::boost()
{
	vel.x += BOOST_VEL * cos(angle * 3.14 / 180);
	vel.y += BOOST_VEL * sin(angle * 3.14 / 180);
}

void Cat::turn(bool dir) {
	if (dir) angle += D_ANGLE;
	else angle -= D_ANGLE;
}