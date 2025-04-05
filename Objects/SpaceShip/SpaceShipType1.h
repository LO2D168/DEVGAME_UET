#ifndef _SpaceShipType1__H
#define _SpaceShipType1__H

#include "SpaceShip.h"

class shipType1: public SpaceShip
{
protected:
    const int speedType1 = 1;
public:
    shipType1(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj) {
        speed = speedType1;
        pointerToImg = listImgSpaceShip[0];
        typeShip = 1;
    }
};

inline void fixedUpdateType1(deque<shipType1*> &listShipType1, deque<Bullet*> &listBulletFromMainShip) {
    int siz = listShipType1.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType1.front();
        listShipType1.pop_front();

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

        if (check) listShipType1.push_back(ship);
    }
}

inline void moveType1(deque<shipType1*> &listShipType1, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType1) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();
    }
}

inline void renderType1(deque<shipType1*> listShipType1, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType1) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
    }
}
#endif // _SpaceShipType1__H