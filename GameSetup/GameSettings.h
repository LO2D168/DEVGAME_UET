#ifndef _GameSettings__H
#define _GameSettings__H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

using namespace std;

//---------Info settings----------------------
inline int SCREEN_WIDTH;
inline int SCREEN_HEIGHT;
inline int timeFrame = 0;

inline const int mod_vocal = 8;
inline const int scroll_speed = 1;
inline const char* gameTitle = "AstroType";

//--------Main Val-------------
inline const int mainSpeed = 5;
inline const int mainHeightObj = 70;
inline const int mainWidthObj = 50;
inline const int penaltyValue = 50;
//-----------------------------

//----------Meteorite----------
inline const int meteoSpeed = 5 ;
inline const int meteoHeight = 40;
inline const int meteoWidth = 30;
inline const int numMeteoImg = 4;
inline const int meteoEventSpeed = 50;
inline const char* meteoArray[] = {"C:/DevGame/image_source/p1.png",
                            "C:/DevGame/image_source/p2.png",
                            "C:/DevGame/image_source/p3.png",
                            "C:/DevGame/image_source/p4.png"};
//-----------------------------

//-----------Heart------------
inline const int heathWidthObj = 40;
inline const int heathHeightObj = 40;
inline const char* linkToHeartImg = "C:/DevGame/image_source/heart.png";
inline SDL_Texture* pointerToHeartImg = NULL;
//-----------------------------

//------------------Bullet-----------
const int speedBulletLow = 3;
const int speedBulletHigh = 5;
const int speedBulletMid = 4;
const int widthBullet = 20;
const int heightBullet = 40;
const int numBulletMain = 4;
const int numBulletTyp1 = 4;
const int numBulletTyp2 = 3;
const int numBulletTyp3 = 2;

inline const char* bulletArray[] ={
    "C:/DevGame/image_source/mainBullet1.png",
    "C:/DevGame/image_source/mainBullet2.png",
    "C:/DevGame/image_source/mainBullet3.png",
    "C:/DevGame/image_source/mainBullet4.png",
    "C:/DevGame/image_source/bulletType1_1.png",
    "C:/DevGame/image_source/bulletType1_2.png",
    "C:/DevGame/image_source/bulletType1_3.png",
    "C:/DevGame/image_source/bulletType1_4.png",
    "C:/DevGame/image_source/bulletType2_1.png",
    "C:/DevGame/image_source/bulletType2_2.png",
    "C:/DevGame/image_source/bulletType2_3.png",
    "C:/DevGame/image_source/bulletType3_1.png",
    "C:/DevGame/image_source/bulletType3_2.png",
};
//----------------------------------
//---------SpaceShip-----------
inline const int numTypeSpaceShip = 7;
inline const char* linkToSpaceShip[] ={
        "C:/DevGame/image_source/Example_ships/3B.png",
        "C:/DevGame/image_source/Example_ships/4.png",
        "C:/DevGame/image_source/Example_ships/5B.png",
        "C:/DevGame/image_source/Example_ships/6B.png",
        "C:/DevGame/image_source/Example_ships/8.png",
        "C:/DevGame/image_source/Example_ships/9.png",
        "C:/DevGame/image_source/Example_ships/10B.png",
};
inline vector<SDL_Texture*> listImgSpaceShip;
const int widthShipType1 = 40;
const int heightShipType1 = 40;
const int widthShipType2 = 40;
const int heightShipType2 = 50;
const int widthShipType3 = 50;
const int heightShipType3 = 30;
const int widthShipType4 = 50;
const int heightShipType4 = 50;
const int widthShipType5 = 60;
const int heightShipType5 = 70;
const int widthShipType6 = 50;
const int heightShipType6 = 50;
const int widthShipType7 = 40;
const int heightShipType7 = 50;

const int speedSpaecshipEvent = 300;
//-----------------------------

inline SDL_Window* window = NULL;
inline SDL_Surface* screenSurface = NULL;
inline SDL_Renderer* renderer = NULL;
inline SDL_Texture* pointerBackground = NULL;

//----------Link img--------------------------

inline const char* background = "../image_source/background.png";
inline const char* MainCharacterIMG = "C:/DevGame/image_source/Example_ships/1.png";
//--------------------------------------------

//----------------Font------------------------
inline TTF_Font *fontBold = NULL;
inline TTF_Font *fontRegular = NULL;
inline TTF_Font *fontLight = NULL;
inline TTF_Font *fontMedium = NULL;
inline TTF_Font *fontSemiBold = NULL;
inline TTF_Font *fontVariable = NULL;
//--------------------------------------------

//------- Start SDL and create windows -------
inline bool checkInit();
//--------------------------------------------
inline bool checkWindows();

//--------------------------------------------
void close();

inline void errorWarningAndExit(const char* str, const char* error)
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

    fontBold = TTF_OpenFont("../fonts/bold.ttf", 20);
    fontRegular = TTF_OpenFont("../fonts/regular.ttf", 20);
    fontLight = TTF_OpenFont("../fonts/light.ttf", 20);
    fontMedium = TTF_OpenFont("../fonts/medium.ttf", 20);
    fontSemiBold = TTF_OpenFont("../fonts/semibold.ttf", 20);
    // fontVariable = TTF_OpenFont("../fonts/variable.ttf", 20);

    // if (fontSemiBold == NULL || fontMedium == NULL || fontSemiBold == NULL || fontVariable == NULL || fontLight == NULL)
    //     return false;


    return true;
}

inline bool checkWindows()
{
    window = SDL_CreateWindow( gameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        errorWarningAndExit("CreateWindow", SDL_GetError());
        return false;
    }

    return true;
}

inline void close()
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