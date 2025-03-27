#ifndef _SpaceShipType4__H
#define _SpaceShipType4__H

#include "SpaceShip.h"

class shipType4: public SpaceShip
{
protected:
    const int speedType4 = 1;
    const int speedShoot = 200;
    int framIn = 0;
public:
    shipType4(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj)
    {
        speed = speedType4;
        pointerToImg = listImgSpaceShip[6];
        typeShip = 4;
    }

    void getframIn(int val) {
        framIn = val;
    }

    bool check() {
        return ((timeFrame - framIn) % speedShoot == 0);
    }
    Bullet* getBullet() {
        Bullet* newBullet = new Bullet(speedBulletHigh, posX + widthObj/2, posY + heightObj/2, widthBullet, heightBullet, 1);
        return newBullet;
    }
};
#endif // _SpaceShipType4__H