#pragma once
#include "gameObject.h";

#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <string>

struct SDL_Color;

class Case : GameObject
{
private:

	std::map<int, SDL_Texture*> m_mTextures;

public:

	int m_iValue;

	Case(std::map<int, SDL_Texture*> mTextures, int iX, int iY, int iWitdh, int iLength, SDL_Texture* sdlTexture, Window* oWindow);

	void display(int iMax);
	void setTexture();

};
