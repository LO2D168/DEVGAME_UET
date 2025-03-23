#ifndef _SpaceShipType2__H
#define _SpaceShipType2__H

#include "SpaceShip.h"

class shipType2: public SpaceShip
{
protected:
    const int speedType2 = 60;
public:
    shipType2(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj)
    {
        speed = speedType2;
        pointerToImg = listImgSpaceShip[1];
    }
};
#endif // _SpaceShipType2__H