#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#define FPS 60
#define WIDTH 1024
#define HEIGHT 640
using namespace std;

class Sprite
{
protected:
	SDL_Rect m_src; // Source rectangle.
	SDL_Rect m_dst; // Destination rectangle.
public:
	void SetRekts(const SDL_Rect s, const SDL_Rect d)
	{
		m_src = s;
		m_dst = d;
	}
	SDL_Rect* GetSrc() {return &m_src;}
	SDL_Rect* GetDst() { return &m_dst; }
};

class EnemyBullet : public Sprite
{
private:
	int m_frame = 0,		// Frame Counter
		m_frameMax = 180;	// NUmber of frames to display
	SDL_Rect m_enemyBullet;
public:
	EnemyBullet(SDL_Point spawnLoc = { 1512, 384 })
	{
		cout << "constructing Enemy Bullet at " << &(*this) << endl;
		m_src = { 0,0,240,190 };
		m_dst = { spawnLoc.x, spawnLoc.y, 75, 50 };
	}

	~EnemyBullet()
	{
		cout << "De-allocating Enemy Bullet at " << &(*this) << endl;
	}

	void SetLoc(SDL_Point loc)
	{
		m_dst.x = loc.x;
		m_dst.y = loc.y;
	}

	void Update()
	{
		m_dst.x -= 14;	// number is translation.
	}

	void Render(SDL_Renderer* rend)
	{
		SDL_SetRenderDrawColor(rend, 0, 200, 0, 255);
		SDL_RenderFillRect(rend, &m_enemyBullet);
	}

	SDL_Rect* GetEnemy() { return &m_enemyBullet; }
};

class Enemy : public Sprite
{
private:
	int m_frame = 0,		// Frame Counter
		m_frameMax = 180;	// NUmber of frames to display
	int speed = 1;
	SDL_Rect m_enemy;		// single rect for enemy
public:
	Enemy(SDL_Point spawnLoc = { 1250, 384, })
	{
			cout << "constructing Enemy at " << &(*this) << endl;
			m_src = { 0,0,256,256 };
			m_dst = { spawnLoc.x, spawnLoc.y,100,100 };
	}

	~Enemy()
	{
		cout << "De-allocating Enemy at " << &(*this) << endl;
	}

	void SetLoc(SDL_Point newloc)
	{
		m_dst.x = newloc.x;
		m_dst.y = newloc.y;
	}

	void Update()
	{
		m_dst.x -= 3;	// number is translation.
	}

	void Render(SDL_Renderer* rend)
	{
		SDL_SetRenderDrawColor(rend, 0, 200, 0, 255);
		SDL_RenderFillRect(rend, &m_enemy);
	}

	void Shoot()
	{
	}
	SDL_Rect* GetEnemy() { return &m_dst; }
};

class Bullet : public Sprite
{
private:
	SDL_Rect m_rect; //	single rectangle for destination
public:
	Bullet(SDL_Point spawnLoc = {512, 384}) // non-default constructor
	{
		cout << "constructing bullet at " << &(*this) << endl;
		//this->m_rect.x = spawnLoc.x;	//this-> is optional
		//this->m_rect.y = spawnLoc.y;	//this-> is optional
		//this->m_rect.w = 8;
		//this->m_rect.h = 8;
		m_src = { 0,0,212,78 };
		m_dst = { spawnLoc.x, spawnLoc.y, 23, 10 };
	}
	~Bullet()
	{
		cout << "De-allocating Bullet at " << &(*this) << endl;
	}
	void SetLoc(SDL_Point loc)
	{
		m_dst.x = loc.x;
		m_dst.y = loc.y;
	}
	void Update()
	{
		this->m_dst.x += 20;	// number is translation.
	}
	void Render(SDL_Renderer* rend)
	{
		SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
	}
	SDL_Rect* GetRekt() { return &m_rect; }
};

class AnimatedSprite : public Sprite
{
private:
	int m_frame = 0,		// Frame Counter
		m_frameMax = 3,		// NUmber of frames to display
		m_sprite = 0,		// which sprite of the animation to display
		m_spriteMax = 10;	// Number of sprites in the animation
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
				//m_sprite = 0;
			}
			m_src.x = m_src.w * m_sprite;
		}
		m_frame++;

		// Short Way:
		/*if (m_frame++ % m_frameMax == 0)
		{
			m_src.x = m_src.w * (m_sprite++ % (m_spriteMax));
		}*/
	}
	void ResetSprite()
	{
		m_spriteMax = 0;
	}
};

class Obstacle : public Sprite
{
private:
	int speed = 1;
public:
	double angle = 0.0;
	Obstacle(SDL_Point spawnLoc = { 1250, 384, })
	{
		cout << "constructing Bottle Cap at " << &(*this) << endl;
		m_src = { 0,0,437,437 };
		m_dst = { spawnLoc.x, spawnLoc.y,100,100 };
	}
	~Obstacle()
	{
		cout << "De-allocating Bottle Cap at " << &(*this) << endl;
	}
	void SetLoc(SDL_Point newloc)
	{
		m_dst.x = newloc.x;
		m_dst.y = newloc.y;
	}
	void Update()
	{
		m_dst.x -= 5;
		angle += speed;
	}
	void jump()
	{
		speed = (1 + rand() % 20);
		SetLoc({ 1250, rand() % 500 + 100 });
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
	bool alive = 1;

	// sound effect obj
	Mix_Chunk* m_shoot;
	Mix_Chunk* m_death;
	Mix_Chunk* m_eShoot;
	Mix_Chunk* m_eDeath;
	// Music Track obj
	Mix_Music* m_music;

	SDL_Texture *m_pTexture,
				*m_pBGtexture,
				*m_pEtexture,
				*m_pBtexture,
				*m_pEBtexture,
				*m_pOtexture,
				*m_pEXtexture;

	Sprite m_player, m_bg1, m_bg2;
	AnimatedSprite m_explode;
	int m_speed = 5; // In-class initialization. Not normal.

	// Bullet vector;
	vector<Bullet*> m_bullets;
	 
	// Enemy vectors
	vector<Enemy*> m_enemy;

	// Enemy bullets vector
	vector<EnemyBullet*> m_enemyBullets;

	// Obsticle
	vector<Obstacle*> m_obsticle;

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
