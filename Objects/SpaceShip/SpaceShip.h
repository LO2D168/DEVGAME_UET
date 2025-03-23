#ifndef _SpaceShip__H
#define _SpaceShip__H

#include "C:\DevGame\GameSetup\GameBoard.h"
#include "C:\DevGame\Objects\SetObj.h"

class SpaceShip : public Obj
{
protected:
    double vx = 0.0f, vy = 0.0f;
public:
    SpaceShip(const char* c, const int Speed, const int wobj, const int hobj) : Obj(c, Speed, wobj, hobj) {}

    void trackingMainObj(MainCharacter* obj)
    {
        vx = obj->getPosX() - posX;
        vy = obj->getPosY() - posY;

        double length = sqrt(vx*vx + vy*vy);
        vx /= length;
        vy /= length;
    }

    virtual void appear()
    {
        int type = rand() % 3;

        switch (type) {
            case 0:
                posX = -widthObj;
                posY = rand() % (SCREEN_HEIGHT / 2) - heightObj;
                break;
            case 1:
                posX = rand() % SCREEN_WIDTH - widthObj;
                posY = -heightObj;
                break;
            case 2:
                posX = SCREEN_WIDTH;
                posY = rand() % (SCREEN_HEIGHT / 2) - heightObj;
                break;
        }
    }

    void move()
    {
        posX += vx*speed;
        posY += vy*speed;
    }

    void render()
    {
        double angle = atan2(vy, vx) * (180.0 / M_PI);
        SDL_Rect rectObj = {posX, posY, widthObj, heightObj};
        SDL_RenderCopyEx(renderer, pointerToImg, NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
    }
};

#endif // _SpaceShip__H

#include "SpaceShipType1.h"
#include "SpaceShipType2.h"
#include "SpaceShipType3.h"
#include "SpaceShipType4.h"
#include "SpaceShipType5.h"
#include "SpaceShipType6.h"
#include "SpaceShipType7.h"
#include "SpaceShipType8.h"
