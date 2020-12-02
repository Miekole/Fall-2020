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
	SDL_Rect m_src;	//	Source rect
	SDL_Rect m_dst;	//	Destination rect
};

class EnemyBullet
{
private:
	SDL_Rect m_enemyBullet;
public:
	EnemyBullet(SDL_Point spawnLoc = { 512, 384 })
	{
		cout << "constructing Enemy Bullet at " << &(*this) << endl;
		m_enemyBullet.x = spawnLoc.x;
		m_enemyBullet.y = spawnLoc.y;
		m_enemyBullet.h = 8;
		m_enemyBullet.w = 8;
	}

	~EnemyBullet()
	{
		cout << "De-allocating Enemy at " << &(*this) << endl;
	}

	void SetLoc(SDL_Point loc)
	{
		m_enemyBullet.x = loc.x;
		m_enemyBullet.y = loc.y;
	}

	void Update()
	{
		m_enemyBullet.x -= 5;	// number is translation.
	}

	void Render(SDL_Renderer* rend)
	{
		SDL_SetRenderDrawColor(rend, 0, 200, 0, 255);
		SDL_RenderFillRect(rend, &m_enemyBullet);
	}

	SDL_Rect* GetEnemy() { return &m_enemyBullet; }
};

class Enemy
{
private:
	int m_frame = 0,		// Frame Counter
		m_frameMax = 180;	// NUmber of frames to display
	SDL_Rect m_enemy;		// single rect for enemy
public:
	Enemy(SDL_Point spawnLoc = { 512, 384 })
	{
			cout << "constructing Enemy at " << &(*this) << endl;
			m_enemy.x = spawnLoc.x;
			m_enemy.y = spawnLoc.y;
			m_enemy.h = 35;
			m_enemy.w = 35;
	}

	~Enemy()
	{
		cout << "De-allocating Enemy at " << &(*this) << endl;
	}


	void Update()
	{
		m_enemy.x -= 3;	// number is translation.
	}

	void Render(SDL_Renderer* rend)
	{
		SDL_SetRenderDrawColor(rend, 0, 0, 200, 255);
		SDL_RenderFillRect(rend, &m_enemy);
	}
	SDL_Rect* GetEnemy() { return &m_enemy; }
};

class Bullet : public Sprite
{
private:
	SDL_Rect m_rect; //	single rectangle for destination
public:
	Bullet(SDL_Point spawnLoc = {512, 384}) // non-default constructor
	{
		cout << "constructing bullet at " << &(*this) << endl;
		this->m_rect.x = spawnLoc.x;	//this-> is optional
		this->m_rect.y = spawnLoc.y;	//this-> is optional
		this->m_rect.w = 8;
		this->m_rect.h = 8;
	}
	~Bullet()
	{
		cout << "De-allocating Bullet at " << &(*this) << endl;
	}
	void SetLoc(SDL_Point loc)
	{
		m_rect.x = loc.x;
		m_rect.y = loc.y;
	}
	void Update()
	{
		this->m_rect.x += 5;	// number is translation.
	}
	void Render(SDL_Renderer* rend)
	{
		SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
		SDL_RenderFillRect(rend, &m_rect);
	}
	SDL_Rect* GetRekt() { return &m_rect; }
};

class AnimatedSprite : public Sprite
{
private:
	int m_frame = 0,		// Frame Counter
		m_frameMax = 10,		// NUmber of frames to display
		m_sprite = 0,		// which sprite of the animation to display
		m_spriteMax = 8;	// Number of sprites in the animation
public:
	void SetRects(SDL_Rect s, SDL_Rect d)
	{
		m_src = s;
		m_dst = d;
	}
	void Animate()
	{
	//	Long way:
	/*	if (m_frame == m_frameMax)
		{
			m_frame = 0;
			m_sprite++;
			if (m_sprite == m_spriteMax)
			{
				m_sprite = 0;
			}
			m_src.x = m_src.w * m_sprite;
		}
		m_frame++;*/

		// Short Way:
		if (m_frame++ % m_frameMax == 0)
		{
			m_src.x = m_src.w * (m_sprite++ % (m_spriteMax));
		}
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

	SDL_Texture *m_pTexture, *m_pBtexture;	// player texture
	SDL_Texture* m_pBGTexture;	// backgroung texture
	Sprite m_bg1, m_bg2;

	AnimatedSprite m_player;
	int m_speed = 5; // In-class initialization. Not normal.

	// Bullet vector;
	vector<Bullet*> m_bullets;

	// enemy vector
	vector<Enemy*> m_enemys;

	//enemy bullets vector
	vector<EnemyBullet*> m_enemyBullets;

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
