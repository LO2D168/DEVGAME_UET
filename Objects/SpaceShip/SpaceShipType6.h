#ifndef _SpaceShipType6__H
#define _SpaceShipType6__H

#include "SpaceShip.h"

class shipType6: public SpaceShip
{
protected:
    const int speedType6 = 1;
    const int speedShoot = 200;
    const int delayShoot = 40;
    int penaltyShoot = 0;
    int framIn = 0;
public:
    shipType6(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj) {
        speed = speedType6;
        typeShip = 6;
        pointerToImg = listImgSpaceShip[2];
    }

    void getframIn(int val) {
        framIn = val;
    }

    void getPenalty() {penaltyShoot = 120;}

    bool check() {
        if (penaltyShoot) penaltyShoot--;
        return ((timeFrame - framIn) % speedShoot == 0);
    }

    bool checkPenalty() {
        return (penaltyShoot && (penaltyShoot % delayShoot == 0));
    }


    Bullet* getBullet() {
        Bullet* newBullet = new Bullet(speedBulletMid, posX +  widthObj/2, posY + heightObj/2, widthBullet, heightBullet,2);
        return newBullet;
    }
};
#endif // _SpaceShipType6__H