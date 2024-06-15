#pragma once
#include "defines.h"
#include "SDL.h"

struct mouseCoor {
	int x;
	int y;
};

static class InputManager {
public:
	InputManager();
	~InputManager();

	static mouseCoor m_mouseCoor;

	static bool m_mouseIsPressed;

	
	static void mouse_pos();


};

