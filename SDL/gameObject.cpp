#include "gameObject.h"
#include "window.h"

#include <iostream>

GameObject::GameObject(int iX, int iY, int iWitdh, int iLength, SDL_Color sdlColor, Window* oWindow)
{
	m_iX = iX;
	m_iY = iY;
	m_iWidth = iWitdh;
	m_iLength = iLength;
	m_sdlColor = sdlColor;
	(*oWindow).m_voGameObjects.push_back(this);
}

void GameObject::drawRect(SDL_Renderer* sdlRenderer)
{
	SDL_SetRenderDrawColor(sdlRenderer, m_sdlColor.r, m_sdlColor.g, m_sdlColor.b, m_sdlColor.a);
	SDL_Rect sdlRect = { m_iX,m_iY,m_iWidth,m_iLength };
	SDL_RenderFillRect(sdlRenderer, &sdlRect);
}

GameObject::~GameObject()
{
}
