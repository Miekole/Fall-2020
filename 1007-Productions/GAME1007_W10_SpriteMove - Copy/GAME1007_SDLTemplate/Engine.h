#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#define FPS 60
#define WIDTH 1024
#define HEIGHT 640
using namespace std;

class Sprite
{
public:
	SDL_Rect m_src; // Source rectangle.
	SDL_Rect m_dst; // Destination rectangle.
};

class Enemy : public Sprite
{
private:
	int m_frame = 0,		// Frame Counter
		m_frameMax = 10;		// NUmber of frames to spawn

public:
	Enemy(SDL_Point spawnLoc = { 512, 384 })
	{
		cout << "constructing Enemy at " << &(*this) << endl;
		//	dest rect
		m_dst.x = spawnLoc.x;
		m_dst.y = spawnLoc.y;
		m_dst.h = 35;
		m_dst.w = 35;

		// source rect
		m_src.x = 0;
		m_src.y = 0;
		m_src.h = 35;
		m_src.w = 35;
	}
	~Enemy()
	{
		cout << "De-allocating Enemy at " << &(*this) << endl;
	}
	int SetRects(SDL_Rect s, SDL_Rect d)
	{
		m_src = s;
		m_dst = d;
	}
	void Render(SDL_Renderer* rend)
	{
		SDL_SetRenderDrawColor(rend, 0, 0, 200, 255);
		SDL_RenderFillRect(rend, &m_dst);
	}
	void Update()
	{
		m_dst.x -= 3;	// number is translation.
	}

};

class Engine
{
private: // private properties.
	bool m_running = false;
	Uint32 m_start, m_end, m_delta, m_fps;
	const Uint8* m_keystates;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_frameCtr = 0;

	SDL_Texture* m_pTexture, * m_pBGtexture, * m_pEtexture;
	Sprite m_player, m_bg1, m_bg2;

	vector<Enemy*> m_enemy;

	int m_speed = 5; // In-class initialization. Not normal.

private: // private method prototypes.
	int Init(const char* title, int xPos, int yPos, int width, int height, int flags);
	void Clean();
	void Wake();
	void HandleEvents();
	bool KeyDown(SDL_Scancode c);
	void Update();
	void Render();
	void Sleep();

public: // public method prototypes.
	int Run();
};

#endif

// Reminder: you can ONLY have declarations in headers, not logical code
