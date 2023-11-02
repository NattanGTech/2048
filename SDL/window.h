#pragma once

#include <SDL.h>

#include <vector>

struct SDL_Window;
struct SDL_Renderer;

class GameObject;

class Window
{
public:
	SDL_Window* m_sdlWindow;
	SDL_Renderer* m_sdlRenderer;
	std::vector<GameObject*> m_voGameObjects;


	Window(const char* cTitle, int iWidth, int iHeight);

	void display();
	void close();

	~Window();
};