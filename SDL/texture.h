#pragma once
#include "window.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <string>
#include <map>

class Textures
{
private:
	Window* m_oWindow;
	std::map<std::string, SDL_Texture*> m_msdlTextures;

public:

	Textures(Window* oWindow);
	SDL_Texture* text(const char* cPath, const char* cMessage, SDL_Color sdlColor);
	SDL_Texture* image(const char* cPath);
	~Textures();
	
	
};