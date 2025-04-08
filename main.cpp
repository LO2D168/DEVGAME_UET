#include ".\Menu\All.h"
using namespace std;

int WinMain(int argc, char* args[])
{
    if(!checkInit()) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else  if(!checkWindows()) printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    createWindows(); loadImg(); loadData(); loadScoreData();

    SDL_ShowCursor(SDL_DISABLE);
    SDL_Event e;
    while (!((SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT))) {
        int num = renderMenu(e);
        if (num == 4) break;
        switch (num) {
            case 1: playButton(e);
                break;
            case 2: settingButton();
                break;
            case 3: turtorialButton();
                break;
        }
    }
    closeWindows();
    close();

    return 0;
}
