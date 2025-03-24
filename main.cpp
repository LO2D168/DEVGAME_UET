#include "GameSetup\GameBoard.h"
#include "GameScene\Scence.h"
#include "Objects\SetObj.h"
#include "Data\DataGame.h"
#include "Data\DataVocal.h"
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
        loadData();
        prepareData();
        setupScroll();
        score = 0;

        while(mainObjCharc->getHealth())
        {
            timeFrame++;
            if ( (SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT)) break;

            ElapsedUpdate();
            FixedUpdate();
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
    spaceShipUpdate();
    meteoFixedUpdate();
    bulletFixedUpdate();
    MainFixedUpdate();
}

void ElapsedUpdate()
{
    spaceShipElapsedUpdate();
    bulletElapsedUpdate();
    meteoElapsedUpdate();
    MainElapsedUpdate();
}

void Render()
{
    scroll();
    MainRender();
    meteoRender();
    spaceShipRender();
    bulletRender();
    SDL_RenderPresent(renderer);
}