#include ".\Menu\All.h"
using namespace std;


int WinMain(int argc, char* args[])
{
    if(!checkInit()) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else  if(!checkWindows()) printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    //resetT();
    createWindows(); loadImg(); loadData(); loadScoreData();
    SDL_ShowCursor(SDL_DISABLE);
    SDL_Event e;
    Mix_PlayMusic(soundBackground, -1);
    while (!((SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT))) {
        int num = renderMenu(e);
        if (num == 4) break;
        switch (num) {
            case 1:
                Mix_PlayChannel(-1, TransButton, 0);
                Mix_HaltMusic();
                Mix_PlayMusic(soundPlay, -1);
                playButton(e);
                Mix_HaltMusic();
                Mix_PlayMusic(soundBackground, -1);
                break;
            case 2:
                Mix_PlayChannel(-1, TransButton, 0);
                settingButton(e);
                break;
            case 3:
                Mix_PlayChannel(-1, TransButton, 0);
                turtorialButton(e);
                break;
        }
    }
    closeWindows();
    close();

    return 0;
}
