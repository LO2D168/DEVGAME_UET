#ifndef _SpaceShip__H
#define _SpaceShip__H

#include ".\GameSetup\GameBoard.h"
#include ".\Objects\Bullet\Bullet.h"
#include "healthBar.h"

inline float dist(float u, float v, float x, float y) {
    return (u - x) * (u - x) + (v - y) * (v - y);
}

class SpaceShip : public Obj, public healthbar
{
protected:
    double vx = 0.0f, vy = 0.0f;
    double angleObj = 0;
    int typeShip = 0;
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

        angleObj = atan2(vy, vx) * (180.0 / M_PI);
        angleObj += 90;
    }

    int getType() {return typeShip;}
    int backId() {return idShip;}
    double getAngle() { return angleObj; }

    virtual void appear()
    {
        int type = rand() % 3;

        switch (type) {
            case 0:
                posX = -widthObj/2;
                posY = rand() % (SCREEN_HEIGHT / 2) - heightObj/2;
                break;
            case 1:
                posX = rand() % SCREEN_WIDTH - widthObj/2;
                posY = -heightObj/2;
                break;
            case 2:
                posX = SCREEN_WIDTH;
                posY = rand() % (SCREEN_HEIGHT / 2) - heightObj/2;
                break;
        }
    }

    float dist(float x, float y, float u, float v) {
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

#include "SpaceShipType1.h"
#include "SpaceShipType2.h"
#include "SpaceShipType3.h"
#include "SpaceShipType4.h"
#include "SpaceShipType5.h"
#include "SpaceShipType6.h"
#include "SpaceShipType7.h"
#endif // _SpaceShip__H
