#pragma once

#include <SDL.h>

class Window;

//class SDL_Renderer;
//struct SDL_Color;

class GameObject
{
public:
	int m_iX;
	int m_iY;
	int m_iWidth;
	int m_iLength;
	SDL_Color m_sdlColor;

	GameObject(int iX, int iY, int iWitdh, int iLength, SDL_Color sdlColor, Window* oWindow);

	void drawRect(SDL_Renderer* sdlRenderer);

	~GameObject();
};
