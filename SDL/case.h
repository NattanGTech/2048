#pragma once
#include "gameObject.h";

#include <SDL.h>
#include <map>
#include <string>

struct SDL_Color;

class Case : GameObject
{
private:

	std::map<int, SDL_Color> m_mColors;

public:

	int m_iValue;

	Case(std::map<int,SDL_Color> mColors, int iX, int iY, int iWitdh, int iLength, SDL_Color sdlColor, Window* oWindow);

	void display(int iMax);
	void setColor();

};
