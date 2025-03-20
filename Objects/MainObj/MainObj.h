#ifndef _MainObj__H
#define _MainObj__H

#include "C:/DevGame/GameSetup/GameBoard.h"


class MainCharacter : public Obj
{
protected:
    int helth = 5;

public:

    MainCharacter(const char* c, const int speed, const int wobj, const int hobj) : Obj(c, speed, wobj, hobj)
    {
        posX = SCREEN_WIDTH / 2;
        posY = int(SCREEN_HEIGHT * 0.9);
    }

    void getDirection()
    {
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if(currentKeyStates[SDL_SCANCODE_UP]) moveToX(0), moveToY(-1);
        if(currentKeyStates[SDL_SCANCODE_DOWN]) moveToX(0), moveToY(1);
        if(currentKeyStates[SDL_SCANCODE_LEFT]) moveToX(-1), moveToY(0);
        if(currentKeyStates[SDL_SCANCODE_RIGHT]) moveToX(1), moveToY(0);

        posX = max(posX, 0); posX = min(posX, SCREEN_WIDTH - widthObj);
        posY = max(posY, 0); posY = min(posY, SCREEN_HEIGHT - heightObj);
    }
};

MainCharacter mainObjCharc(MainCharacterIMG, mainSpeed, mainWidthObj, mainHeightObj);

void MainRender()
{
    mainObjCharc.changePointerObj(loadTexture(MainCharacterIMG, renderer));
    SDL_Rect RectObj = {mainObjCharc.getPosX(), mainObjCharc.getPosY(), mainObjCharc.getWidthObj(), mainObjCharc.getHeightObj()};
    SDL_RenderCopy(renderer, mainObjCharc.getPointerObj(), NULL, &RectObj);
}

void MainFixedUpdate()
{
    mainObjCharc.getDirection();
}

void MainElapsedUpdate()
{

}

#endif // _MainObj__H
