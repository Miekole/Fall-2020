#include "Engine.h"

int Engine::Init(const char* title, int xPos, int yPos, int width, int height, int flags)
{
	cout << "Initializing engine..." << endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // If initialization is okay...
	{
		// Create the SDL window...
		m_pWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (m_pWindow != nullptr)
		{
			// Create the SDL renderer...(back buffer)
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, NULL);
			if (m_pRenderer != nullptr)
			{
				// Initialize subsystems...
				if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0)
				{
					m_pTexture = IMG_LoadTexture(m_pRenderer, "sprite.png");
					m_pBGtexture = IMG_LoadTexture(m_pRenderer, "skyline.png");
					m_pEtexture = IMG_LoadTexture(m_pRenderer, "ghost.png");
				}
				else return false; // Image init failed.
			}
			else return false; // Renderer creation failed.
		}
		else return false; // Window creation failed.
	}
	else return false; // initalization failed.
	m_fps = (Uint32)round(1.0 / (double)FPS * 1000); // Converts FPS into milliseconds, e.g. 16.67
	m_keystates = SDL_GetKeyboardState(nullptr);
	m_player = { {0,0,121,227}, {100,250,80,150} }; // First {} is src rectangle, and second {} destination rect
	//m_enemy.push_back( new Enemy->SetRects({ 0,0,35,35 }, {300,300,35,35}));
	m_bg1 = { {0,0,1920,640}, {0,0,1920,640} };
	m_bg2 = { {0,0,1920,640}, {1920,0,1920,640} };
	cout << "Initialization successful!" << endl;
	m_running = true;
	return true;
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

bool Engine::KeyDown(SDL_Scancode c)
{
	if (m_keystates != nullptr)
	{
		if (m_keystates[c] == 1)
			return true;
	}
	return false;
}

void Engine::Update()
{
	//	Scroll the BG
	m_bg1.GetDst()->x -= m_speed;
	m_bg2.GetDst()->x -= m_speed;
	// Wrap the BG.
	if (m_bg1.GetDst()->x <= -1920)	// If BG 1 goes off screen
	{	// Bounce back to original positions
		m_bg1.GetDst()->x = 0;
		m_bg2.GetDst()->x = 1920;
	}

	if (m_frameCtr == 150)
	{
		m_frameCtr = 0;
		m_enemy.push_back(new Enemy({ 1240, rand() % 550 + 100 }));
		m_enemy.shrink_to_fit();
		cout << "New enemy vector capacity: " << m_enemy.capacity() << endl;
	}
	else
	{
		m_frameCtr++;
	}

	if (KeyDown(SDL_SCANCODE_W) && m_player.GetDst()->y > 0)
		m_player.GetDst()->y -= m_speed;
	else if (KeyDown(SDL_SCANCODE_S) && m_player.GetDst()->y < HEIGHT - m_player.GetDst()->h)
		m_player.GetDst()->y += m_speed;
	if (KeyDown(SDL_SCANCODE_A) && m_player.GetDst()->x > 0)
		m_player.GetDst()->x -= m_speed;
	else if (KeyDown(SDL_SCANCODE_D) && m_player.GetDst()->x < WIDTH - m_player.GetDst()->w)
		m_player.GetDst()->x += m_speed;
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 128, 255, 255);
	SDL_RenderClear(m_pRenderer);
	// Any drawing here...

	//BG render
	SDL_RenderCopy(m_pRenderer, m_pBGtexture, m_bg1.GetSrc(), m_bg1.GetDst());
	SDL_RenderCopy(m_pRenderer, m_pBGtexture, m_bg2.GetSrc(), m_bg2.GetDst());

	//player render
	SDL_RenderCopyEx(m_pRenderer, m_pTexture, m_player.GetSrc(), m_player.GetDst(), 90.0, NULL, SDL_FLIP_NONE);

	SDL_RenderCopy(m_pRenderer, m_pEtexture, m_bg2.GetSrc(), m_bg2.GetDst());

	SDL_RenderPresent(m_pRenderer); // Flip buffers - send data to window.
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
	{
		return 1;
	}
	// Start and run the "engine"
	if (Init("GAME1007 M1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE) == false)
	{
		return 2;
	}
	// We passed our initial checks, start the loop!
	while (m_running == true)
	{
		Wake();
		HandleEvents(); // Input
		Update();       // Processing
		Render();       // Output
		if (m_running == true)
			Sleep();
	}
	Clean();
	return 0;
}


void Engine::Clean()
{
	cout << "Cleaning engine..." << endl;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyTexture(m_pTexture);
	IMG_Quit();
	SDL_Quit();
}


