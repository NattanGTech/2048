#include "case.h"
#include "grid.h"
#include "test.h"
#include "window.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <time.h>

#include <iostream>


#undef main
int main()
{
	srand(time(NULL));
	TTF_Init();

	SDL_Event sdlEvent;
	SDL_bool sdlQuit = SDL_FALSE;

	Window* oWindow = new Window();

	bool play = true;

	while(play && !sdlQuit){

		oWindow->m_voGameObjects.clear();

		SDL_Surface* sdlSurface = SDL_LoadBMP("image/Fond.bmp");
		if (sdlSurface == NULL)
		{
			std::cout << "Error SDL_LoadBMP :" << SDL_GetError();
			oWindow->close();
		}
		SDL_Texture* sdlTexture = SDL_CreateTextureFromSurface(oWindow->m_sdlRenderer, sdlSurface);
		if (sdlTexture == NULL)
		{
			std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
			oWindow->close();
		}
		SDL_FreeSurface(sdlSurface);

		GameObject* oScreen = new GameObject(0, 0, 900, 576, sdlTexture, oWindow);

		sdlQuit = SDL_FALSE;
		Grid* oGrid = new Grid(oWindow);
		oGrid->display();
		oWindow->display();

		while (!oGrid->lose() && !sdlQuit)
		{
			while (SDL_PollEvent(&sdlEvent)) {
				if (sdlEvent.type == SDL_QUIT) {
					sdlQuit = SDL_TRUE;
					delete oWindow;
				}
				else if (sdlEvent.type == SDL_KEYDOWN)
				{
					if (sdlEvent.key.keysym.sym == SDLK_UP) {
						oGrid->moveAndGenerateNewtiles(&Grid::moveUp);
					}
					else if (sdlEvent.key.keysym.sym == SDLK_DOWN) {
						oGrid->moveAndGenerateNewtiles(&Grid::moveDown);
					}
					else if (sdlEvent.key.keysym.sym == SDLK_RIGHT) {
						oGrid->moveAndGenerateNewtiles(&Grid::moveRight);
					}
					else if (sdlEvent.key.keysym.sym == SDLK_LEFT) {
						oGrid->moveAndGenerateNewtiles(&Grid::moveLeft);
					}
					oGrid->display();
					oWindow->display();
				}
			}
		}


		SDL_Surface* sdlSurfaceLoose = SDL_LoadBMP("image/defeat.bmp");

		if (sdlSurfaceLoose == NULL)
		{
			std::cout << "Error SDL_LoadBMP :" << SDL_GetError();
			oWindow->close();
		}
		SDL_Texture* sdlTextureLoose = SDL_CreateTextureFromSurface(oWindow->m_sdlRenderer, sdlSurfaceLoose);
		if (sdlTextureLoose == NULL)
		{
			std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
			oWindow->close();
		}
		SDL_FreeSurface(sdlSurfaceLoose);

		oWindow->m_voGameObjects.clear();
		GameObject* oLoose = new GameObject(0, 0, 900, 576, sdlTextureLoose, oWindow);

		TTF_Font* font = TTF_OpenFont("font/harry.TTF", 512);
		SDL_Surface* sdlLooseTextSurface = TTF_RenderUTF8_Solid(font, "Défaite !!! Press space to restart", { 255, 0, 0 });
		if (sdlLooseTextSurface == NULL)
		{
		std::cout << "Error TTF_RenderUTF8_Solid :" << SDL_GetError();
		oWindow->close();
		}
		SDL_Texture* sdlTextureLooseText = SDL_CreateTextureFromSurface(oWindow->m_sdlRenderer, sdlLooseTextSurface);
		if (sdlTextureLooseText == NULL)
		{
		std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
		oWindow->close();
		}
		SDL_FreeSurface(sdlLooseTextSurface);
		GameObject* oTextLoose = new GameObject(200, 200, 500, 500, sdlTextureLooseText, oWindow);

		delete oGrid;
		sdlQuit = SDL_FALSE;

		play = false;

		while (!play && !sdlQuit)
		{
			while (SDL_PollEvent(&sdlEvent)) {
				if (sdlEvent.type == SDL_QUIT) {
					sdlQuit = SDL_TRUE;
					delete oWindow;
				}
				else if (sdlEvent.type == SDL_KEYDOWN)
				{
					if (sdlEvent.key.keysym.sym == SDLK_SPACE) {
						play = true;
					}
					oWindow->display();
				}
			}
		}
	}
	
	
	delete oWindow;
	return 0;

}
