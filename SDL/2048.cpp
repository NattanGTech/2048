#include "case.h"
#include "grid.h"
#include "test.h"

#include <SDL.h>
#include <stdlib.h> 
//#include <SDL_image.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#include <iostream>
#include <string>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


void close(SDL_Window* sdlWindow, SDL_Renderer* sdlRenderer);

#undef main
int main()
{
    srand(time(NULL));
    SDL_Window* sdlWindow = NULL;
    SDL_Renderer* sdlRenderer = NULL;
	SDL_Event sdlEvent;
    SDL_bool sdlQuit = SDL_FALSE;
    SDL_Color sdlBackground = { 187,173,160,255 };
    SDL_Color sdlEmptyCase = { 205,193,180,255 };
    SDL_Color sdlCaseNum2 = { 238,228,218,255 };
	SDL_Color sdlCaseNum4 = { 237,224,200,255 };
    SDL_Color sdlCaseNum8 = { 242,177,121,255 };
	SDL_Color sdlCaseNum16 = { 245,149,99,255 };
	SDL_Color sdlCaseNum32 = { 246,124,95,255 };
	SDL_Color sdlCaseNum64 = { 246,94,59,255 };
	SDL_Color sdlCaseNum128 = { 237,207,114,255 };
	SDL_Color sdlCaseNum256 = { 237,204,97,255 };
	SDL_Color sdlCaseNum512 = { 237,200,80,255 };
	SDL_Color sdlCaseNum1024 = { 237,197,63,255 };
	SDL_Color sdlCaseNum2048 = { 237,194,46,255 };
	SDL_Color sdlCaseNum4096 = { 119,161,54,255 };
	SDL_Color sdlCaseNum8192 = { 45,179,136,255 };
    int iStatut = EXIT_FAILURE;

    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        close(sdlWindow, sdlRenderer);
    }
    
    sdlWindow = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480, SDL_WINDOW_SHOWN);

    if (NULL == sdlWindow)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        close(sdlWindow, sdlRenderer);
    }

    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);

    if (NULL == sdlRenderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        close(sdlWindow, sdlRenderer);
	}

    SDL_RaiseWindow(sdlWindow);

    SDL_SetRenderDrawColor(sdlRenderer, sdlBackground.r, sdlBackground.g, sdlBackground.b, sdlBackground.a);
    SDL_Rect screen = { 0,0,640,480 };
    SDL_RenderFillRect(sdlRenderer, &screen);
   
    SDL_RenderPresent(sdlRenderer);

    Grid* oGrid = new Grid();
    oGrid->display();
    test::move();
    test::win();
    test::lose();

    /*while(!quit){
		while (SDL_PollEvent(&event) && !quit){
            std::cout << "a";
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
                close(window, renderer);
            }
        }*/
	while (!oGrid->lose())
	{
		int c = 0;
		switch ((c = _getch()))
		{
		case KEY_UP:
			oGrid->moveAndGenerateNewtiles(&Grid::moveUp);
			break;
		case KEY_DOWN:
			oGrid->moveAndGenerateNewtiles(&Grid::moveDown);
			break;
		case KEY_RIGHT:
			oGrid->moveAndGenerateNewtiles(&Grid::moveRight);
			break;
		case KEY_LEFT:
			oGrid->moveAndGenerateNewtiles(&Grid::moveLeft);
			break;
		default:
			break;
		}
		oGrid->display();
	}
    /*}*/
   
    std::cout << "perdu";

    delete oGrid;
    return 0;

}
void close(SDL_Window* window, SDL_Renderer* renderer){
    if (NULL != window)
        SDL_DestroyWindow(window);
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
