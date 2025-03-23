#ifndef _SpaceShipType4__H
#define _SpaceShipType4__H

#include "SpaceShip.h"

class shipType4: public SpaceShip
{
protected:
    const int speedType4 = 120;
public:
    shipType4(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj)
    {
        speed = speedType4;
        pointerToImg = listImgSpaceShip[4];
    }
};
#endif // _SpaceShipType4__H