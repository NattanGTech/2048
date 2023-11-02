#include "case.h"
#include "grid.h"
#include "test.h"
#include "window.h"
#include "texture.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <time.h>

#include <string>
#include <iostream>


#undef main
int main()
{
	srand(time(NULL));
	TTF_Init();

	SDL_Event sdlEvent;
	SDL_bool sdlQuit = SDL_FALSE;

	Window* oWindow = new Window("2048", 900, 576);
	Textures* oTextures = new Textures(oWindow);

	bool play = true;

	while (play && !sdlQuit) {

		oWindow->m_voGameObjects.clear();

		GameObject* oScreen = new GameObject(0, 0, 900, 576, oTextures->image("image/Fond.bmp"), oWindow);

		sdlQuit = SDL_FALSE;
		Grid* oGrid = new Grid(oWindow, oTextures);
		oGrid->display();
		oWindow->display();

		while (!oGrid->lose() && !sdlQuit)
		{
			if (oGrid->win()) {
				GameObject* oTextWin = new GameObject(500, 300, 350, 100, oTextures->text("font/harry.TTF", "Victoire !!! Continue", { 250, 227, 12 }), oWindow);
			}
			while (SDL_PollEvent(&sdlEvent)) {
				if (sdlEvent.type == SDL_QUIT) {
					sdlQuit = SDL_TRUE;
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

		oWindow->m_voGameObjects.clear();
		GameObject* oLoose = new GameObject(0, 0, 900, 576, oTextures->image("image/defeat.bmp"), oWindow);
		GameObject* oTextDefeat = new GameObject(100, 20, 250, 150, oTextures->text("font/harry.TTF", "Defeat !!!", { 198, 36, 1 }), oWindow);
		GameObject* oTextRestart = new GameObject(400, 450, 400, 100, oTextures->text("font/harry.TTF", "Press space to play again", { 198, 36, 1 }), oWindow);

		delete oGrid;

		play = false;

		while (!play && !sdlQuit)
		{
			while (SDL_PollEvent(&sdlEvent)) {
				if (sdlEvent.type == SDL_QUIT) {
					sdlQuit = SDL_TRUE;
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

	delete oTextures;
	delete oWindow;
	return 0;

}
