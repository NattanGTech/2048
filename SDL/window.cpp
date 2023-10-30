#include "window.h";
#include "gameObject.h";

#include <SDL.h>
//#include <SDL_image.h>

#include <iostream>

Window::Window()
{
    
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        close();
    }

    m_sdlWindow = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        480, 480, SDL_WINDOW_SHOWN);

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
    SDL_Color sdlBackground = { 187,173,160,255 };
    GameObject* oScreen = new GameObject(0, 0, 480, 480, sdlBackground);
    oScreen->drawRect(m_sdlRenderer);
    display(); 
}

void Window::display()
{
    SDL_RenderPresent(m_sdlRenderer);
}

void Window::close(){
    if (NULL != m_sdlWindow)
        SDL_DestroyWindow(m_sdlWindow);
    if (NULL != m_sdlRenderer)
        SDL_DestroyRenderer(m_sdlRenderer);
    SDL_Quit();

}

Window::~Window()
{

}
