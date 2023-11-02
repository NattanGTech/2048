#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Window;

class GameObject
{
public:
	int m_iX;
	int m_iY;
	int m_iWidth;
	int m_iLength;
	SDL_Texture* m_sdlTexture;

	GameObject(int iX, int iY, int iWitdh, int iLength, SDL_Texture* sdlTexture, Window* oWindow);

	//void drawRect(SDL_Renderer* sdlRenderer);
	void draw(SDL_Renderer* sdlRenderer);

	~GameObject();
};