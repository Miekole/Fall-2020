/*******************************************************************************
* File Name   :		GAME1007_M1_FerrazzoMichael
* Description :		SDL stuff :)
* Author      :		Michael Ferrazzo
* Created     :		Tue, Oct 15, 2020
* Modified    :		Sun, Oct 25, 2020
*******************************************************************************/

// SDL includes pasted for convenience. Move/copy to relevant files.
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine game;
	return game.Run();
}