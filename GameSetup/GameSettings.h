#ifndef _GameSettings__H
#define _GameSettings__H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

using namespace std;

//---------Info settings----------------------
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 600;
const int mod_vocal = 26000;
const char* gameTitle = "AstroType";

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
//--------------------------------------------

//----------Link img-------------------------

//------------------------------------------



//------- Start SDL and create windows -------
bool checkInit();
//--------------------------------------------
bool checkWindows();

//--------------------------------------------
void close();



//-------------------------------------------
bool checkInit()
{
    std::srand(time(0));
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        return false;
    }
    else return true;
}

bool checkWindows()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    // Initialize SDL_ttf
    if (TTF_Init() != 0) {
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
        return false;
    }
    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled!");
    }

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    window = SDL_CreateWindow( gameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        return false;
    }
}

void close()
{

    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_FreeSurface(screenSurface);
    screenSurface= NULL;

    //Quit SDL subsystems
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}


#endif // _GameSettings__H