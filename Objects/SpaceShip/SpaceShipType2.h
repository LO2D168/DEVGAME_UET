#ifndef _SpaceShipType2__H
#define _SpaceShipType2__H

#include "SpaceShip.h"

class shipType2: public SpaceShip
{
protected:
    const int speedType2 = 2;
public:
    shipType2(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj)
    {
        speed = speedType2;
        pointerToImg = listImgSpaceShip[1];
        typeShip = 2;
    }
};

inline void fixedUpdateType2(deque<shipType2*> &listShipType2, deque<Bullet*> &listBulletFromMainShip) {
    int siz = listShipType2.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType2.front();
        listShipType2.pop_front();

        bool check = true;

        int siz2 = listBulletFromMainShip.size();
        while (siz2) {
            auto bullet =  listBulletFromMainShip.front();
            listBulletFromMainShip.pop_front();
            siz2--;

            if (ship->checkCollision(bullet->getPosX(), bullet->getPosY(), widthBullet, heightBullet, bullet->getAngle())) {
                delete bullet;
                check = false;
                break;
            }

            listBulletFromMainShip.push_back(bullet);
        }

        if (check) listShipType2.push_back(ship);
    }
}

inline void moveType2(deque<shipType2*> &listShipType2, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType2) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();
    }
}

inline void renderType2(deque<shipType2*> &listShipType2, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType2) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
    }
}

#endif // _SpaceShipType2__H