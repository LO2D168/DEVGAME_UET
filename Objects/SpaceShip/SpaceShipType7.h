#ifndef _SpaceShipType7__H
#define _SpaceShipType7__H

#include "SpaceShip.h"

class shipType7: public SpaceShip
{
protected:
    const int speedType7 = 2;
    const int speedShoot = 250;
    int framIn = 0;
public:
    shipType7(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj) {
        speed = speedType7;
        typeShip = 7;
        pointerToImg = listImgSpaceShip[3];
    }

    void getframIn(int val) {
        framIn = val;
    }

    bool check() {
        return ((timeFrame - framIn) % speedShoot == 0);
    }
    Bullet* getBullet() {
        Bullet* newBullet = new Bullet(speedBulletLow, posX, posY, widthBullet, heightBullet, 3);
        return newBullet;
    }
};
#endif // _SpaceShipType7__H