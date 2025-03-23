#ifndef _SpaceShipType3__H
#define _SpaceShipType3__H

#include "SpaceShip.h"

class shipType3: public SpaceShip
{
protected:
    const int speedType3 = 120;
public:
    shipType3(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj)
    {
        speed = speedType3;
        pointerToImg = listImgSpaceShip[4];
    }
};
#endif // _SpaceShipType3__H