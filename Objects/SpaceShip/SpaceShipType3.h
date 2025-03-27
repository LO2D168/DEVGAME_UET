#ifndef _SpaceShipType3__H
#define _SpaceShipType3__H

#include "SpaceShip.h"

class shipType3: public SpaceShip
{
protected:
    const int speedType3 = 3;
public:
    shipType3(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj)
    {
        speed = speedType3;
        pointerToImg = listImgSpaceShip[4];
        typeShip = 3;
    }

    void tracking(int x, int y)
    {
        vx = x - posX;
        vy = y - posY;

        double length = sqrt(vx*vx + vy*vy);
        vx /= length;
        vy /= length;

        angleObj = atan2(vy, vx) * (360.0 / M_PI);
    }
};
#endif // _SpaceShipType3__H