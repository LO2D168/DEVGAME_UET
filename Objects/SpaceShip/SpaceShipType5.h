#ifndef _SpaceShipType5__H
#define _SpaceShipType5__H

#include "SpaceShip.h"

class shipType5: public SpaceShip
{
protected:
    const int speedType5 = 1;
    const int speedDropShip = 1000;
    int framIn = 0;
public:
    shipType5(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj) {
        speed = speedType5;
        pointerToImg = listImgSpaceShip[5];
        typeShip = 5;
    }

    void getFram(int val) {
        framIn = val;
    }

    bool check() {
        return ((timeFrame - framIn) % speedDropShip == 0);
    }
};
#endif // _SpaceShipType5__H