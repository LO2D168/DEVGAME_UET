#include "GameSetup\GameBoard.h"
#include "GameScene\Scence.h"
#include "Objects\SetObj.h"
using namespace std;

void FixedUpdate();
void ElapsedUpdate();
void Render();

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
        loadImg();
        setupScroll();
        while(mainObjCharc->getHealth())
        {
            timeFrame++;
            if ( (SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT)) break;

            FixedUpdate();
            ElapsedUpdate();
            Render();

            SDL_Delay(16);
        }
        closeWindows();
        close();
        delete mainObjCharc;
    }

    return 0;
}

void FixedUpdate()
{
    meteoFixedUpdate();
    MainFixedUpdate();
}

void ElapsedUpdate()
{
    meteoElapsedUpdate();
    MainElapsedUpdate();
}

void Render()
{
    scroll();
    MainRender();
    meteoRender();
    SDL_RenderPresent(renderer);
}