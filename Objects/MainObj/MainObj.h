#ifndef _MainObj__H
#define _MainObj__H

#include "C:/DevGame/GameSetup/GameBoard.h"
#include "C:/DevGame/Objects/SetObj.h"
#include "../Meteorite/Meteorite.h"
#include "heart.h"



class MainCharacter : public Obj, public heart
{
protected:
    int health = 5;
public:
    int penalty = 0;
    MainCharacter(const char* c, const int speed, const int wobj, const int hobj) : Obj(c, speed, wobj, hobj) {}

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

    void gotAttack() {health--;}
    int getHealth() {return health;}
};

MainCharacter* mainObjCharc = new MainCharacter(MainCharacterIMG, mainSpeed, mainWidthObj, mainHeightObj);

void MainRender()
{
    mainObjCharc->renderHeart(mainObjCharc->getHealth() - 1);
    // animation after collision
    if(mainObjCharc->penalty && (mainObjCharc->penalty % 3 != 0)) {return;}
    //
    mainObjCharc->render(mainObjCharc->getPointerObj());
    mainObjCharc->renderHeart(mainObjCharc->getHealth());
}

void MainFixedUpdate()
{
    mainObjCharc->getDirection();

    if(mainObjCharc->penalty)
    {
        (mainObjCharc->penalty)--;
        return;
    }

    for(auto c: listMeteoEvent)
    {
        if(mainObjCharc->checkCollisionObject(c))
        {
            mainObjCharc->gotAttack();
            mainObjCharc->deleteHeart();
            mainObjCharc->penalty = penaltyValue;
            break;
        }
    }

}

void MainElapsedUpdate()
{
    if(mainObjCharc->getInitObj() == true)
    {
        mainObjCharc->changePosX(SCREEN_WIDTH / 2 - mainWidthObj / 2);
        mainObjCharc->changePosY(SCREEN_HEIGHT - mainHeightObj);

        mainObjCharc->changePointerObj(loadTexture(mainObjCharc->getLinkImg(), renderer));
        mainObjCharc->changInitObj(false);
    }
}

#endif // _MainObj__H
