#include "Engine.h"
#include "ctime"

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
					m_pTexture = IMG_LoadTexture(m_pRenderer, "img/sprite.png");
					m_pBGtexture = IMG_LoadTexture(m_pRenderer, "img/background.png");
					m_pEtexture = IMG_LoadTexture(m_pRenderer, "img/ghost.png");
					m_pBtexture = IMG_LoadTexture(m_pRenderer, "img/bullet.png");
					m_pEBtexture = IMG_LoadTexture(m_pRenderer, "img/FireBall.png");
					m_pOtexture = IMG_LoadTexture(m_pRenderer, "img/bottleCap.png");
					m_pEXtexture = IMG_LoadTexture(m_pRenderer, "img/explosion.png");
				}
				else return false; // Image init failed.
				if (Mix_Init(MIX_INIT_MP3) != 0)
				{
					// Configure Mixer
					Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 2048);
					Mix_AllocateChannels(16);

					// Load Sound
					m_shoot = Mix_LoadWAV("aud/shoot1.wav");
					m_death = Mix_LoadWAV("aud/die1.wav");
					m_eShoot = Mix_LoadWAV("aud/shoot2.wav");
					m_eDeath = Mix_LoadWAV("aud/enemyDie2.wav");
					m_music = Mix_LoadMUS("aud/FightTheme.mp3");
				}
				else return false; // Mixer init failed.
			}
			else return false; // Renderer creation failed.
		}
		else return false; // Window creation failed.
	}
	else return false; // initalization failed.
	m_fps = (Uint32)round(1.0 / (double)FPS * 1000); // Converts FPS into milliseconds, e.g. 16.67
	m_keystates = SDL_GetKeyboardState(nullptr);
	m_player.SetRekts( {0,0,126,72}, {50,350,126,72} ); // First {} is src rectangle, and second {} destination rect
	m_bg1.SetRekts( {0,0,1920,640}, {0,0,1920,640} );
	m_bg2.SetRekts( {0,0,1920,640}, {1920,0,1920,640} );
	cout << "Initialization successful!" << endl;
	Mix_PlayMusic(m_music, -1); // 0, 1-n or -1 for infinate loopping.
	Mix_VolumeMusic(50);	// 0-128.
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
		case SDL_KEYUP:
			if (event.key.keysym.sym == ' ' && alive == true)
			{
				// spawns bullet
				m_bullets.push_back(new Bullet({ m_player.GetDst()->x + 90, m_player.GetDst()->y + 33 }));
				m_bullets.shrink_to_fit();
				Mix_PlayChannel(-1, m_shoot, 0); // -1 channel is the first avalible
				cout << "New bullet vector capacity: " << m_bullets.capacity() << endl;
			}
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
		m_bg1.SetRekts({ 0,0,1920,640 }, { 0,0,1920,640 });
		m_bg2.SetRekts({ 0,0,1920,640 }, { 1920,0,1920,640 });
	}
	
	//	Parse player movement
	if (KeyDown(SDL_SCANCODE_W) && m_player.GetDst()->y > 0)
		m_player.GetDst()->y -= m_speed;
	else if (KeyDown(SDL_SCANCODE_S) && m_player.GetDst()->y < HEIGHT - m_player.GetDst()->h)
		m_player.GetDst()->y += m_speed;
	if (KeyDown(SDL_SCANCODE_A) && m_player.GetDst()->x > 0)
		m_player.GetDst()->x -= m_speed / 1.5;
	else if (KeyDown(SDL_SCANCODE_D) && m_player.GetDst()->x < WIDTH - m_player.GetDst()->w)
		m_player.GetDst()->x += m_speed / 1.5;

	// enemy spawn
	if (m_frameCtr == 150 || m_frameCtr == 300)
	{
		m_enemy.push_back(new Enemy({1100, rand() % 540 + 100 }));
		m_enemy.shrink_to_fit();
		cout << "New enemy vector capacity: " << m_enemy.capacity() << endl;
	}

	// Obstacle spawn
	if (m_frameCtr == 300)
	{
		if ((rand() % 3 + 1) == 1)
		{
			m_frameCtr = 0;
			m_obsticle.push_back(new Obstacle({ 1100, rand() % 540 + 100 }));
			m_obsticle.shrink_to_fit();
			cout << "New obstacle vector capacity: " << m_obsticle.capacity() << endl;
			m_obsticle.push_back(new Obstacle({ 1100, rand() % 540 + 100 }));
			m_obsticle.shrink_to_fit();
			cout << "New obstacle vector capacity: " << m_obsticle.capacity() << endl;
		}
		else if ((rand() % 3 + 1) == 2)
		{
			m_frameCtr = 0;
			m_obsticle.push_back(new Obstacle({ 1100, rand() % 540 + 100 }));
			m_obsticle.shrink_to_fit();
			cout << "New obstacle vector capacity: " << m_obsticle.capacity() << endl;
			m_obsticle.push_back(new Obstacle({ 1100, rand() % 540 + 100 }));
			m_obsticle.shrink_to_fit();
			cout << "New obstacle vector capacity: " << m_obsticle.capacity() << endl;
			m_obsticle.push_back(new Obstacle({ 1100, rand() % 540 + 100 }));
			m_obsticle.shrink_to_fit();
			cout << "New obstacle vector capacity: " << m_obsticle.capacity() << endl;
			
			
		}
		else if ((rand() % 3 + 1) == 3)
		{
			m_frameCtr = 0;
			m_obsticle.push_back(new Obstacle({ 1100, rand() % 540 + 100 }));
			m_obsticle.shrink_to_fit();
			cout << "New obstacle vector capacity: " << m_obsticle.capacity() << endl;
			m_obsticle.push_back(new Obstacle({ 1100, rand() % 540 + 100 }));
			m_obsticle.shrink_to_fit();
			cout << "New obstacle vector capacity: " << m_obsticle.capacity() << endl;
			m_obsticle.push_back(new Obstacle({ 1100, rand() % 540 + 100 }));
			m_obsticle.shrink_to_fit();
			cout << "New obstacle vector capacity: " << m_obsticle.capacity() << endl;
			m_obsticle.push_back(new Obstacle({ 1100, rand() % 540 + 100 }));
			m_obsticle.shrink_to_fit();
			cout << "New obstacle vector capacity: " << m_obsticle.capacity() << endl;
		}
	}
	else
	{
		m_frameCtr++;
	}

	// enemy shooting
	for (int x = 0; x < m_enemy.size(); x++) {
		if (m_frameCtr % 75 == 0) {
			m_enemyBullets.push_back(new EnemyBullet({ m_enemy[x]->GetDst()->x , m_enemy[x]->GetDst()->y }));
			m_enemyBullets.shrink_to_fit();
			cout << "New enemy bullet vector capacity: " << m_enemyBullets.capacity() << endl;
			if (alive == true) {
				Mix_PlayChannel(-1, m_eShoot, 0);
			}
		}
	}


	// bullet update
	for (int i = 0 ; i< m_bullets.size(); i++){
		m_bullets[i]->Update();
	}

	// enemy update
	for (int x = 0; x < m_enemy.size(); x++){
		m_enemy[x]->Update();
	}

	// enemy bullet update
	for (int b = 0; b < m_enemyBullets.size(); b++) {
		m_enemyBullets[b]->Update();
	}

	// obstacle update
	for (int i = 0; i < m_obsticle.size(); i++) {
		m_obsticle[i]->Update();
	}

	// explosion update
	if (alive == false) {
		m_explode.Animate();
	}

	//oblstical hit enemy
	for (int i = 0; i < m_obsticle.size(); i++)
	{
		if (SDL_HasIntersection(m_obsticle[i]->GetDst(), m_player.GetDst()))
		{
			SDL_DestroyTexture(m_pTexture);
			if (alive == true) {
				cout << endl;
				cout << "----====||||	Crash! Died to Bottle Cap.	||||====----\n";
				cout << endl;
				m_explode.ResetSprite();
				m_explode.SetRects({ 0,0,128,128 }, { m_player.GetDst()->x - 50,m_player.GetDst()->y - 75, 200,200 });
				Mix_PlayChannel(-1, m_death, 0);
				alive = false;
			}
		}
	}

	// bullet hit enemy
	for (int x = 0; x < m_enemy.size(); x++){
		for (int i = 0; i < m_bullets.size(); i++){
			if (SDL_HasIntersection(m_bullets[i]->GetDst(), m_enemy[x]->GetDst())){
				//delete enemy
				delete m_enemy[x];	// flag for reallocation
				m_enemy[x] = nullptr;	//	wrangle your dangle
				m_enemy.erase(m_enemy.begin() + x);
				m_enemy.shrink_to_fit();	//	reduces capacity to size
				//delete bullet
				delete m_bullets[i];
				m_bullets[i] = nullptr;
				m_bullets.erase(m_bullets.begin() + i);
				m_bullets.shrink_to_fit();
				cout << "----====||||	hit!	||||====----\n";
				Mix_PlayChannel(-1, m_eDeath, 0);
				break;
			}
		}
	}

	// enemy hit player
	for (int x = 0; x < m_enemy.size(); x++) {
		if (SDL_HasIntersection(m_enemy[x]->GetDst(), m_player.GetDst())){
			SDL_DestroyTexture(m_pTexture);
			if (alive == true) {
				cout << endl;
				cout << "----====||||	Crash! Died to Ghost.	||||====----\n";
				cout << endl;
				m_explode.ResetSprite();
				m_explode.SetRects({ 0,0,128,128 }, { m_player.GetDst()->x - 50,m_player.GetDst()->y - 75, 200,200 });
				Mix_PlayChannel(-1, m_death, 0);
				alive = false;
			}
		}
	}

	// enemy bullet hit player
	for (int i = 0; i < m_enemyBullets.size(); i++) {
		if (SDL_HasIntersection(m_player.GetDst(), m_enemyBullets[i]->GetDst())) {
			SDL_DestroyTexture(m_pTexture);
			if (alive == true) {
				cout << endl;
				cout << "----====||||	Destroyed! Died to fire ball.	||||====----\n";
				cout << endl;
				m_explode.ResetSprite();
				m_explode.SetRects({ 0,0,128,128 }, { m_player.GetDst()->x - 50,m_player.GetDst()->y - 75, 200,200 });
				Mix_PlayChannel(-1, m_death, 0);
				alive = false;
			}
		}
	}

	// check for death
	if (alive == false)
	{
			Mix_PauseMusic();
	}

	// check for bullets going off screen
	for (unsigned i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i]->GetDst()->x >= 1024)
		{
			delete m_bullets[i];	// flag for reallocation
			m_bullets[i] = nullptr;	//	wrangle your dangle
			m_bullets.erase(m_bullets.begin() + i);
			m_bullets.shrink_to_fit();	//	reduces capacity to size
			break;
		}
	}

	// check for enemy going off screen
	for (unsigned x = 0; x < m_enemy.size(); x++)
	{
		if (m_enemy[x]->GetDst()->x < -100)
		{
			delete m_enemy[x];	// flag for reallocation
			m_enemy[x] = nullptr;	//	wrangle your dangle
			m_enemy.erase(m_enemy.begin() + x);
			m_enemy.shrink_to_fit();	//	reduces capacity to size
			break;
		}
	}

	// check for enemy bullets going off screen
	for (unsigned i = 0; i < m_enemyBullets.size(); i++)
	{
		if (m_enemyBullets[i]->GetDst()->x <= -100)
		{
			delete m_enemyBullets[i];
			m_enemyBullets[i] = nullptr;
			m_enemyBullets.erase(m_enemyBullets.begin() + i);
			m_enemyBullets.shrink_to_fit();
			break;
		}
	}

	//check for enemies going off screen
	for (unsigned i = 0; i < m_obsticle.size(); i++)
	{
		if (m_obsticle[i]->GetDst()->x <= -100)
		{
			delete m_obsticle[i];
			m_obsticle[i] = nullptr;
			m_obsticle.erase(m_obsticle.begin() + i);
			m_obsticle.shrink_to_fit();
			break;
		}
	}
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 128, 255, 255);
	SDL_RenderClear(m_pRenderer);
	// Any drawing here...

	SDL_RenderCopy(m_pRenderer, m_pBGtexture, m_bg1.GetSrc(), m_bg1.GetDst());
	SDL_RenderCopy(m_pRenderer, m_pBGtexture, m_bg2.GetSrc(), m_bg2.GetDst());

	// render enemy
	for (int x = 0; x < m_enemy.size(); x++)
	{
		SDL_RenderCopyEx(m_pRenderer, m_pEtexture, m_enemy[x]->GetSrc(), m_enemy[x]->GetDst(), 0, 0 ,SDL_FLIP_NONE);
	}

	// rsnder enemy bullet
	for (int i = 0; i < m_enemyBullets.size(); i++) {
		SDL_RenderCopyEx(m_pRenderer, m_pEBtexture, m_enemyBullets[i]->GetSrc(), m_enemyBullets[i]->GetDst(), 0, 0, SDL_FLIP_NONE);
	}

	// render bullet
	for (int i = 0; i < m_bullets.size(); i++) {
		SDL_RenderCopyEx(m_pRenderer, m_pBtexture, m_bullets[i]->GetSrc(), m_bullets[i]->GetDst(), 0, 0, SDL_FLIP_HORIZONTAL);
	}

	// render obstacle
	for (int i = 0; i < m_obsticle.size(); i++) {
		SDL_RenderCopyEx(m_pRenderer, m_pOtexture, m_obsticle[i]->GetSrc(), m_obsticle[i]->GetDst(), m_obsticle[i]->angle, 0, SDL_FLIP_NONE);
	}

	if (alive == false)
	{
		SDL_RenderCopy(m_pRenderer, m_pEXtexture, m_explode.GetSrc(), m_explode.GetDst());
	}

	// rander player
	SDL_RenderCopyEx(m_pRenderer, m_pTexture, m_player.GetSrc(), m_player.GetDst(), 0, NULL, SDL_FLIP_NONE);
	//SDL_RenderCopyEx(m_pRenderer, m_pTexture, m_player.GetSrc(), m_player.GetDst(), 90.0, NULL, SDL_FLIP_NONE);

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
	// de allocate bullets
	cout << "Cleaning engine..." << endl;
	for (unsigned i = 0; i < m_bullets.size(); i++)
	{
		delete m_bullets[i];	// flag for reallocation
		m_bullets[i] = nullptr;	//	wrangle your dangle
	}
	m_bullets.clear();	//	wipe all elements
	m_bullets.shrink_to_fit();	//	reduces capacity to size

	// de allocate enemy bullets
	for (unsigned i = 0; i < m_enemyBullets.size(); i++)
	{
		delete m_enemyBullets[i];
		m_enemyBullets[i] = nullptr;	
	}
	m_enemyBullets.clear();
	m_enemyBullets.shrink_to_fit();

	// de allocate enemy
	for (unsigned x = 0; x < m_enemy.size(); x++)
	{
		delete m_enemy[x];
		m_enemy[x] = nullptr;	
	}
	m_enemy.clear();
	m_enemy.shrink_to_fit();

	// de allocate obsticles
	for (unsigned o = 0; o < m_enemy.size(); o++)
	{
		delete m_obsticle[o];
		m_obsticle[o] = nullptr;
	}
	m_obsticle.clear();
	m_obsticle.shrink_to_fit();

	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyTexture(m_pTexture);	// player
	SDL_DestroyTexture(m_pBGtexture);	// background
	SDL_DestroyTexture(m_pEtexture);	// enemy texture
	SDL_DestroyTexture(m_pEBtexture); // fireball
	SDL_DestroyTexture(m_pBtexture);	// bullets
	SDL_DestroyTexture(m_pOtexture);	// Obsticles
	IMG_Quit();
	SDL_Quit();
}


