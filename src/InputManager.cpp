#include "InputManager.h"

mouseCoor InputManager::m_mouseCoor = mouseCoor();
bool InputManager::m_mouseIsPressed = false;

#include <iostream>
using namespace std;

void InputManager::mouse_pos() {
	m_mouseIsPressed = false;
	SDL_Event m_event;
	while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&(m_mouseCoor.x), & (m_mouseCoor.y));

			m_mouseCoor.x *= mouseMultiplyX;
			m_mouseCoor.y *= mouseMultiplyY;

			break;
		case SDL_MOUSEBUTTONDOWN:
			if (m_event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseIsPressed = true;
			}
			break;
		}
	}
}

