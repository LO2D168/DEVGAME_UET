#ifndef _MainObj__H
#define _MainObj__H


#include "heart.h"
#include "C:\DevGame\GameSetup\Objects.h"


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
    virtual ~MainCharacter() = default;
};
#endif // _MainObj__H