#ifndef _SpaceShip__H
#define _SpaceShip__H

#include "C:\DevGame\GameSetup\GameBoard.h"
#include "C:\DevGame\Objects\Bullet\Bullet.h"

class SpaceShip : public Obj
{
protected:
    double vx = 0.0f, vy = 0.0f;
    double angleObj = 0;
    int typeShip = 0;
    int idShip = 0;
    int targetX = 0, targetY = 0;
public:
    SpaceShip(const char* c, const int Speed, const int wobj, const int hobj) : Obj(c, Speed, wobj, hobj) {}

    void trackingMainObj(int x, int y)
    {
        vx = x - posX;
        vy = y - posY;

        targetX = x;
        targetY = y;

        double length = sqrt(vx*vx + vy*vy);
        vx /= length;
        vy /= length;

        angleObj = atan2(vy, vx) * (360.0 / M_PI);
    }

    int getType() {return typeShip;}
    int backId() {return idShip;}
    double getAngle() { return angleObj; }

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

    int dist(int x, int y, int u, int v) {
        return (u - x) * (u - x) + (v - y) * (v - y);
    }

    void move()
    {
        posX += speed * vx;
        posY += speed * vy;
    }

    void render()
    {
        double angle = atan2(vy, vx) * (180.0 / M_PI);
        angle += 90;
        SDL_FRect rectObj = {posX, posY, widthObj, heightObj};
        SDL_RenderCopyExF(renderer, pointerToImg, NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
    }

    virtual ~SpaceShip() = default;
};

inline vector<SpaceShip*> listShip;

#include "SpaceShipType1.h"
#include "SpaceShipType2.h"
#include "SpaceShipType3.h"
#include "SpaceShipType4.h"
#include "SpaceShipType5.h"
#include "SpaceShipType6.h"
#include "SpaceShipType7.h"
#endif // _SpaceShip__H
