#include "GameSetup\GameBoard.h"
#include "GameScene\Scence.h"
#include "Objects\Obj.h"
#include "Data\DataVocal.h"
#include "Data\DataGame.h"

using namespace std;

int WinMain(int argc, char* args[])
{
    if(!checkInit()) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        if(!checkWindows()) printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Event e;

        createWindows(); loadImg(); loadData(); setupScroll(); score = 0;

        mainObjCharc = new MainCharacter(MainCharacterIMG, mainSpeed, mainWidthObj, mainHeightObj);
        idShip = 0;

        while(mainObjCharc->getHealth())
        {
            timeFrame++;
            if ( (SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT)) break;
            play();

            SDL_Delay(16);
        }
        closeWindows();
        close();
    }
    return 0;
}
