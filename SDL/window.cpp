#include "window.h"
#include "gameObject.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

Window::Window()
{

    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        close();
    }

    m_sdlWindow = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        900, 576, SDL_WINDOW_SHOWN);

    if (NULL == m_sdlWindow)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        close();
    }

    m_sdlRenderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED);

    if (NULL == m_sdlRenderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        close();
    }

    SDL_RaiseWindow(m_sdlWindow);
}

void Window::display()
{
    SDL_RenderClear(m_sdlRenderer);
    for (int i = 0; i < m_voGameObjects.size(); i++) {
        m_voGameObjects[i]->draw(m_sdlRenderer);
    }
    SDL_RenderPresent(m_sdlRenderer);
}


void Window::close() {
    if (NULL != m_sdlWindow)
        SDL_DestroyWindow(m_sdlWindow);
    if (NULL != m_sdlRenderer)
        SDL_DestroyRenderer(m_sdlRenderer);
    SDL_Quit();

}

Window::~Window()
{
    close();
}
