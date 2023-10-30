#pragma once
struct SDL_Window;
struct SDL_Renderer;

class Window
{
public:
	SDL_Window* m_sdlWindow;
	SDL_Renderer* m_sdlRenderer;

	Window();

	void close();
	void display();

	~Window();
};
