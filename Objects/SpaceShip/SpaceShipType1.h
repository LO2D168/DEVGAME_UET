#ifndef _SpaceShipType1__H
#define _SpaceShipType1__H

#include "SpaceShip.h"
#include "../SetObj.h"


class shipType1: public SpaceShip
{
protected:
    const int speedType1 = 1;
public:
    shipType1(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj) {
        speed = speedType1;
        pointerToImg = listImgSpaceShip[0];
        typeShip = 1;
        setUpHealth(500);
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
                if (ship->decHealth(bullet->getDamage())) {
                    check = false;
                    score++;
                    break;
                }
                delete bullet;
                bullet = nullptr;
            }

            listBulletFromMainShip.push_back(bullet);
        }

        if (check) listShipType1.push_back(ship);
        else {
            delete ship;
            ship = nullptr;
        }
    }
}

inline void moveType1(deque<shipType1*> &listShipType1, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType1) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();
    }
}

inline void renderType1(deque<shipType1*> &listShipType1, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType1) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
        ship->renderHealth(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), 3);
    }
}

inline tuple<float, float, float> findNearestType1(tuple<float, float, float> res, deque<shipType1*> &listShipType1, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType1) {
        if (dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY()) < get<0>(res)) {
            get<0>(res) = dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY());
            get<1>(res) = ship->getPosX();
            get<2>(res) = ship->getPosY();
        }
    }

    return res;
}
#endif // _SpaceShipType1__H