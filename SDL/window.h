#pragma once

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


	Window();

	void display();
	void close();

	~Window();
};
