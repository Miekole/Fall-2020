#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <iostream>
#define WIDTH 1024
#define HEIGHT 768
#define FPS 60
using namespace std;

bool g_running = false;
Uint32 g_start, g_end, g_delta, g_fps;
const Uint8* g_keystates;

SDL_Window* g_pWindow;
SDL_Renderer* g_pRenderer;
SDL_Point g_mousePos; // Mouse position object.

int Init(const char* title, int xPos, int yPos, int width, int height, int flags)
{
	cout << "Initializing engine..." << endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // If initialization is okay...
	{
		// Create the SDL window...
		g_pWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (g_pWindow != nullptr)
		{
			// Create the SDL renderer...(back buffer)
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, NULL);
			if (g_pRenderer != nullptr)
			{
				// Initialize subsystems...
				if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0)
				{
					// Nothing here needed for this.
				}
				else return false; // Image init failed.
			}
			else return false; // Renderer creation failed.
		}
		else return false; // Window creation failed.
	}
	else return false; // initalization failed.
	g_fps = (Uint32)round(1.0 / (double)FPS * 1000); // Converts FPS into milliseconds, e.g. 16.67
	g_keystates = SDL_GetKeyboardState(nullptr);
	// Just demonstrating an unscoped enum as an array index.
	g_running = true;
	return true;
}

void Wake()
{
	g_start = SDL_GetTicks();
}

void HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_running = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.scancode == SDL_SCANCODE_A) // Scancode. Cannot use 'a'
				cout << "Pressed A..." << endl;
			else if (event.key.keysym.sym == SDLK_b) // Keycode. Can use 'b' but will not work with scancodes.
				cout << "Pressed B..." << endl;
			break;
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&g_mousePos.x, &g_mousePos.y);
			cout << "Mouse: " << g_mousePos.x << ',' << g_mousePos.y << endl;
			break;
		}
	}
}

bool KeyDown(SDL_Scancode c)
{
	if (g_keystates != nullptr)
	{
		if (g_keystates[c] == 1)
			return true;
	}
	return false;
}

void Update()
{
	if (KeyDown(SDL_GetScancodeFromKey(SDLK_1)) == 1) // Making the key parse keyboard dependent.
		cout << "Pressed 1..." << endl;
}

void Render()
{
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);
	// Any drawing here...
	SDL_RenderPresent(g_pRenderer); // Flip buffers - send data to window.
}

void Sleep()
{
	g_end = SDL_GetTicks(); // GetTicks return time in ms since initialization
	g_delta = g_end - g_start; // 1055 - 1050 = 5ms
	if (g_delta < g_fps)
		SDL_Delay(g_fps - g_delta);

}

void Clean()
{
	cout << "Cleaning engine..." << endl;
	SDL_DestroyRenderer(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	IMG_Quit();
	SDL_Quit();
}

int Run()
{
	if (g_running == true)
	{
		return 1;
	}
	// Start and run the "engine"
	if (Init("GAME1007 M1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, NULL) == false)
	{
		return 2;
	}
	// We passed our initial checks, start the loop!
	while (g_running == true)
	{
		Wake();
		HandleEvents(); // Input
		Update();       // Processing
		Render();       // Output
		if (g_running == true)
			Sleep();
	}
	Clean();
	return 0;
}



int main(int argc, char* argv[])
{
	return Run();
}