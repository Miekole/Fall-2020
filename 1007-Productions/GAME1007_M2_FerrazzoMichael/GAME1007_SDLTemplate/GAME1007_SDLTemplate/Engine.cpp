#include <iostream>
#include "Engine.h"
#include "SDL_image.h"


SDL_Rect m_dest; // Rectangle structur with 4 ints: x, y, w (width), h(hight),
int m_speed = SPEED;

int Engine::Init(const char* title, int xPos, int yPos, int width, int height, int flags) //<--- Perameters
{
	cout << "initializing Engine....." << endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // if innitalizling is ok
	{
		// create SDL window
		m_pWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (m_pWindow != nullptr)
		{
			// create SDL renderer... (back buffer)
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, NULL);
			if (m_pRenderer != nullptr)
			{
				// Initalize subsystems  later...
				if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0)
				{
					m_pTexture = IMG_LoadTexture(m_pRenderer, "ship.png");

				}
				else  return false;
			}
			else return false; // Renderer creation failed.
		}
		else return false; // Window creation failed. 
	}
	else return false;	// Initialization failed
	m_fps = (Uint32)round((1.0 / (double)FPS) * 1000); // converts FPS into milliseconds
	m_keystates = SDL_GetKeyboardState(nullptr);
	m_player = { {0,0,154,70}, {512,384,154,70} }; // First {} is src, second () is dst rect
	cout << "Initialization successfull" << endl;
	m_running = true;
	return true;
}

void Engine::Clean()
{
	cout << "Cleaning engine..." << endl;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

void Engine::Wake()
{
	m_start = SDL_GetTicks();
}

void Engine::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_running = false;
			break;
		}
	}
}

void Engine::Update()
{

}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 128, 255, 255);
	SDL_RenderClear(m_pRenderer);
	// Any drawing here... 
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_player.m_src, &m_player.m_dst);
	SDL_RenderPresent(m_pRenderer); // Flip buffers - send data to windows.
}

void Engine::Sleep()
{
	m_end = SDL_GetTicks();
	m_delta = m_end - m_start; // 1055 - 1050 = 5ms
	if (m_delta < m_fps)
		SDL_Delay(m_fps - m_delta);
}

int Engine::Run()
{
	if (m_running == true)
		return 1;
	// starts and runs the engine
	if (Init("GAME1007 M1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, NULL) == false)
		return 2;
	// we passed our irnitial checks
	while (m_running == true)
	{
		Wake();
		HandleEvents();	 // Input
		Update();		 // processing
		Render();		 // Output
		if (m_running == true)
			Sleep();
	}
	Clean();
	return 0;

}