#include "case.h"
#include "grid.h"
#include "test.h"
#include "window.h"

#include <SDL.h>
#include <time.h>

#include <iostream>


#undef main
int main()
{
	srand(time(NULL));

	SDL_Event sdlEvent;
	SDL_bool sdlQuit = SDL_FALSE;
	/*int iStatut = EXIT_FAILURE;*/

	Window* oWindow = new Window();
	Grid* oGrid = new Grid(oWindow);
	oGrid->display();
	oWindow->display();
	/*test::move();
	test::win();
	test::lose();*/

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

	delete oGrid;
	delete oWindow;
	return 0;

}
