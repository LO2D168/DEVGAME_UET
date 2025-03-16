#ifndef _GameSettings__H
#define _GameSettings__H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

using namespace std;

//---------Info settings----------------------
int SCREEN_WIDTH;
int SCREEN_HEIGHT;

const int mod_vocal = 26000;
const int scroll_speed = 1;
const char* gameTitle = "AstroType";

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* pointerBackground = NULL;

//--------------------------------------------

//----------Link img--------------------------

const char* background = "../image_source/background.png";
const char* MainCharacter = "../image_source/Example_ships/1.png";



//--------------------------------------------



//------- Start SDL and create windows -------
bool checkInit();
//--------------------------------------------
bool checkWindows();

//--------------------------------------------
void close();

void errorWarningAndExit(const char* str, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", str, error);
    close();
}

//-------------------------------------------
bool checkInit()
{
    std::srand(time(0));
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        return false;
    }

    // Get screen size
    SDL_DisplayMode dm;
    if (SDL_GetCurrentDisplayMode(0, &dm) != 0)
    {
        cerr << "Can't get screen size" << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    SCREEN_WIDTH = dm.w;
    SCREEN_HEIGHT = dm.h;

    SCREEN_HEIGHT -= 80;
    SCREEN_WIDTH /= 2.5;

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


    return true;
}

bool checkWindows()
{
    window = SDL_CreateWindow( gameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        errorWarningAndExit("CreateWindow", SDL_GetError());
        return false;
    }

    return true;
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