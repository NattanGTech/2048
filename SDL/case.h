#pragma once
#include "gameObject.h";

#include <string>


class Case : GameObject
{
public:

	int m_iValue;

	Case(int iX, int iY, int iWitdh, int iLength, SDL_Color sdlColor, Window* oWindow);

	void display(int iMax);

};
