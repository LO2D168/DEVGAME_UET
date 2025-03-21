#ifndef _GameBoard__H
#define _GameBoard__H

#include "GameSettings.h"
#include "FuncSettings.h"
#include "Objects.h"

void loadImg()
{
    for(int i = 0; i < numMeteoImg; i++)
    {
        SDL_Texture* pointerObj = loadTexture(meteoArray[i], renderer);
        listPointerMeteo.push_back(pointerObj);
    }

    pointerToHeartImg = loadTexture(linkToHeartImg, renderer);
}
#endif // _GameBoard__H