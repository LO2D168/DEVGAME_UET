#ifndef _SpaceShipType1__H
#define _SpaceShipType1__H

#include "SpaceShip.h"

class shipType1: public SpaceShip
{
protected:
    const int speedType1 = 30;
public:
    shipType1(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj) {
        speed = speedType1;
        pointerToImg = listImgSpaceShip[0];
    }
};
#endif // _SpaceShipType1__H