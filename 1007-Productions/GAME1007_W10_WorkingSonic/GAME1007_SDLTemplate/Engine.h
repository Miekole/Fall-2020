#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#define FPS 60
#define WIDTH 1024
#define HEIGHT 768
using namespace std;

class Sprite
{
public:
	SDL_Rect m_src; // Source rectangle.
	SDL_Rect m_dst; // Destination rectangle.
};

class AnimatedSprite : public Sprite
{
private:
	int m_frame = -1, // Current frame
		m_frameMax = 5, // nuber of framess to display each sprite
		m_sprite = 0, // which sprite to display
		m_spriteMax = 8; // # of sprites in the animation
	bool m_faceLeft = 0; // 1 = left, 0 = right
	
public:
	void SetRects(SDL_Rect s, SDL_Rect d)
	{
		m_src = s;
		m_dst = d;
	}
	void Animate()
	{
		//	Long way:
		if (m_frame == m_frameMax)
		{
			m_frame = 0;
			m_sprite++;
			if (m_sprite == m_spriteMax)
			{
				m_sprite = 0;
			}
			m_src.x = m_src.w * m_sprite;
		}
			m_frame++;
		
		// Short way:
		/*if (m_frame++ % m_frameMax == 0)
		{
			m_src.x = m_src.w * (m_sprite++ % m_spriteMax);
		}*/
	}
	void Idol()
	{
		m_frame = -1;
		if (m_frame == -1)
		{
			m_src.x = 1024;
		}
	}
	void SetFaceLeft(bool left)
	{
		m_faceLeft = left;
	}

	int GetFaceLeft()
	{
		return m_faceLeft;
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
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

	SDL_Texture* m_pTexture;
	AnimatedSprite m_player;
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
