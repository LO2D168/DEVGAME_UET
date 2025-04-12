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

inline const int mod_vocal = 1056;
inline const int scroll_speed = 1;
inline const char* gameTitle = "TYPING ATTACK";
inline int volObj = 64, volBack = 64, levelGame = 0;
inline const int constVolObj = 128, constVolBack = 128, constLevelGame = 150;
inline SDL_Surface* icon;

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
inline const char* meteoArray[] = {"../image_source/p1.png",
                            "../image_source/p2.png",
                            "../image_source/p3.png",
                            "../image_source/p4.png"};
//-----------------------------

//-----------Heart------------
inline const int heathWidthObj = 40;
inline const int heathHeightObj = 40;
inline const char* linkToHeartImg = "../image_source/heart.png";
inline SDL_Texture* pointerToHeartImg = NULL;
//-----------------------------

//-----------Text-------------------
inline SDL_Texture* alphabetPointerToImg[26];
inline SDL_Texture* digitPointerToImg[10];
inline const char* alphabet[] = {"../image_source/alphabet/A.png",
                                "../image_source/alphabet/B.png",
                                "../image_source/alphabet/C.png",
                                "../image_source/alphabet/D.png",
                                "../image_source/alphabet/E.png",
                                "../image_source/alphabet/F.png",
                                "../image_source/alphabet/G.png",
                                "../image_source/alphabet/H.png",
                                "../image_source/alphabet/I.png",
                                "../image_source/alphabet/J.png",
                                "../image_source/alphabet/K.png",
                                "../image_source/alphabet/L.png",
                                "../image_source/alphabet/M.png",
                                "../image_source/alphabet/N.png",
                                "../image_source/alphabet/O.png",
                                "../image_source/alphabet/P.png",
                                "../image_source/alphabet/Q.png",
                                "../image_source/alphabet/R.png",
                                "../image_source/alphabet/S.png",
                                "../image_source/alphabet/T.png",
                                "../image_source/alphabet/U.png",
                                "../image_source/alphabet/V.png",
                                "../image_source/alphabet/W.png",
                                "../image_source/alphabet/X.png",
                                "../image_source/alphabet/Y.png",
                                "../image_source/alphabet/Z.png",};
inline const char* digit[] = {"../image_source/digit/0.png",
                                "../image_source/digit/1.png",
                                "../image_source/digit/2.png",
                                "../image_source/digit/3.png",
                                "../image_source/digit/4.png",
                                "../image_source/digit/5.png",
                                "../image_source/digit/6.png",
                                "../image_source/digit/7.png",
                                "../image_source/digit/8.png",
                                "../image_source/digit/9.png",};
inline const char* specSynImg = "../image_source/alphabet/specSync.png";
inline SDL_Texture* specSync = NULL;
inline const float widthText = 30;
inline const float heightText = 40;
inline const float startTextX = 30;
inline const float startTextY = 10;
//-----------------------------------
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
    "../image_source/mainBullet1.png",
    "../image_source/mainBullet2.png",
    "../image_source/mainBullet3.png",
    "../image_source/mainBullet4.png",
    "../image_source/bulletType1_1.png",
    "../image_source/bulletType1_2.png",
    "../image_source/bulletType1_3.png",
    "../image_source/bulletType1_4.png",
    "../image_source/bulletType2_1.png",
    "../image_source/bulletType2_2.png",
    "../image_source/bulletType2_3.png",
    "../image_source/bulletType3_1.png",
    "../image_source/bulletType3_2.png",
};
//----------------------------------
//---------SpaceShip-----------
inline const int numTypeSpaceShip = 7;
inline const char* linkToSpaceShip[] ={
        "../image_source/Example_ships/3B.png",
        "../image_source/Example_ships/4.png",
        "../image_source/Example_ships/5B.png",
        "../image_source/Example_ships/6B.png",
        "../image_source/Example_ships/8.png",
        "../image_source/Example_ships/9.png",
        "../image_source/Example_ships/10B.png",
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
inline int idShip = 0;
//-----------------------------

inline SDL_Window* window = NULL;
inline SDL_Surface* screenSurface = NULL;
inline SDL_Renderer* renderer = NULL;
inline SDL_Texture* pointerBackground = NULL;

//----------Link img--------------------------
inline const char* background = "../image_source/background.png";
inline const char* MainCharacterIMG = "../image_source/Example_ships/1.png";
//--------------------------------------------

//------------------Menu----------------------
inline const char* menuImage = "../image_source/Menu/menuImage/backgroundMenu.png";
inline const char* button[] = {"../image_source/Menu/menuImage/play.png",
                        "../image_source/Menu/menuImage/setting.png",
                        "../image_source/Menu/menuImage/tutorial.png",
                        "../image_source/Menu/menuImage/rty.png",};
inline const char* mouse = "../image_source/Menu/mouse.png";
inline const char* pausedImg = "../image_source/Menu/playButton/PauseImg.png";
inline const char* endGameImg = "../image_source/Menu/playButton/EndGameImg.png";
inline const char* turtorial = "../image_source/Menu/Turtorial/turtorial.png";
inline const char* scoreBoard = "../image_source/Menu/Turtorial/scoreBoard.png";
inline const char* backgroundSetting = "../image_source/Menu/settingButton/Background.png";
inline const char* sliderImg = "../image_source/Menu/settingButton/slider.png";
inline const char* sliderButtonImg = "../image_source/Menu/settingButton/sliderButton.png";
inline const char* back2Img = "../image_source/Menu/settingButton/back2.png";
inline SDL_Texture* buttonPointerImg[4];
inline SDL_Texture* menuPointerImg;
inline SDL_Texture* mousePointerImg;
inline SDL_Texture* pausedPointerImg;
inline SDL_Texture* endGamePointerImg;
inline SDL_Texture* turtorialPointerImg;
inline SDL_Texture* scoreBoardPointerImg;
inline SDL_Texture* backgroundSettingPointerImg;
inline SDL_Texture* sliderPointerImg;
inline SDL_Texture* sliderButtonPointerImg;
inline SDL_Texture* back2PointerImg;
//--------------------------------------------

//----------------Music-----------------------
inline Mix_Music* soundBackground;
inline Mix_Music* soundPlay;
inline Mix_Chunk* shipShoot;
inline Mix_Chunk* shipExplore;
inline Mix_Chunk* mainShoot;
inline Mix_Chunk* mainExplore;
inline Mix_Chunk* TransButton;
//--------------------------------------------
//----------------Font------------------------
inline TTF_Font *font = NULL;
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
    
    if (TTF_Init() != 0) {
        cerr << "SDL_ttf initialization failed: " << TTF_GetError() << endl;
        return false;
    }
    
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled!");
    }
    
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }
    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    soundBackground = Mix_LoadMUS("../sound_source/StarWars.mp3");
    if (!soundBackground) {
        std::cerr << "Failed to load music background: " << Mix_GetError() << "\n";
        return false;
    }

    soundPlay = Mix_LoadMUS("../sound_source/March.mp3");
    if (!soundPlay) {
        std::cerr << "Failed to load music play part: " << Mix_GetError() << "\n";
        return false;
    }

    mainShoot = Mix_LoadWAV("../sound_source/MainShoot.wav");
    if (!mainShoot) {
        std::cerr << "Failed to load mainShoot part: " << Mix_GetError() << "\n";
    }

    shipShoot = Mix_LoadWAV("../sound_source/ShipShoot.wav");
    if (!shipShoot) {
        std::cerr << "Failed to load shipShoot part: " << Mix_GetError() << "\n";
    }

    mainExplore = Mix_LoadWAV("../sound_source/MainExplore.wav");
    if (!mainExplore) {
        std::cerr << "Failed to load mainExplore part: " << Mix_GetError() << "\n";
    }

    shipExplore = Mix_LoadWAV("../sound_source/ShipExplore.wav");
    if (!shipExplore) {
        std::cerr << "Failed to load shipExplore part: " << Mix_GetError() << "\n";
    }

    TransButton = Mix_LoadWAV("../sound_source/TransButton.wav");
    if (!TransButton) {
        std::cerr << "Failed to load TransButton part: " << Mix_GetError() << "\n";
    }

    icon = IMG_Load("../image_source/logo.png");
    if (!icon) {
        SDL_Log("Failed to load icon: %s", IMG_GetError());
        return false;
    }
    SDL_SetWindowIcon(window, icon);

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
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);

    //Quit SDL subsystems
    SDL_FreeSurface(icon);
    Mix_FreeMusic(soundBackground);
    Mix_FreeMusic(soundPlay);
    Mix_FreeChunk(mainShoot);
    Mix_FreeChunk(mainExplore);
    Mix_FreeChunk(TransButton);
    Mix_FreeChunk(shipExplore);
    Mix_FreeChunk(shipShoot);
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
}


#endif // _GameSettings__H