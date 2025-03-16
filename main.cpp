#include "GameSetup\GameBoard.h"
#include "GameScene\Scence.h"
#include "Objects\SetObj.h"
using namespace std;

int WinMain(int argc, char* args[])
{
    if(!checkInit()) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        if(!checkWindows())
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }

        SDL_Event e;
        createWindows();
        setupScroll();
        while(true)
        {
            if ( (SDL_PollEvent(&e) != 0) && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT)) break;
            scroll();
            SDL_Delay(16);
        }
        closeWindows();
        close();
    }

    return 0;
}