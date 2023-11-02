#pragma once
#include "gameObject.h";
#include "texture.h";

#include <SDL.h>
#include <SDL_image.h>


class Case : GameObject
{
private:

	Textures* m_oTextures;

public:

	int m_iValue;

	Case(Textures* m_oTextures, int iX, int iY, int iWitdh, int iLength, SDL_Texture* sdlTexture, Window* oWindow);

	void display(int iMax);
	void setTexture();

};