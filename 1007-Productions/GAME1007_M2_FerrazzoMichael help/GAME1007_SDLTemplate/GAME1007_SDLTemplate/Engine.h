#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_
#include <iostream>
#include "SDL.h"
#define FPS 60
#define WIDTH 1024
#define HEIGHT 768
#define SPEED 5
using namespace std;

class Sprite
{
public:
	SDL_Rect m_src; // source rectangle
	SDL_Rect m_dst;	//destination rectangle
};

class Engine
{
private:
	bool m_running = false;
	Uint32 m_start, m_end, m_delta, m_fps;
	const Uint8* m_keystates;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Texture* m_pTexture;
	Sprite m_player;
private:
	int Init(const char* title, int xPos, int yPos, int width, int height, int flags);
	void Clean();
	void Wake();
	void HandleEvents();
	bool KeyDown(SDL_Scancode c);
	void Update();
	void Render();
	void Sleep();
public:	//public method prototypes
	int Run();

};

#endif // !_ENGINE_H_
