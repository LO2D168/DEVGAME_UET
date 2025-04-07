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
        setUpHealth(2000);
    }

    void getFram(int val) {
        framIn = val;
    }

    bool check() {
        return ((timeFrame - framIn) % speedDropShip == 0);
    }
};

inline void fixedUpdateType5(deque<shipType5*> &listShipType5, deque<Bullet*> &listBulletFromMainShip) {
    int siz = listShipType5.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType5.front();
        listShipType5.pop_front();

        bool check = true;

        int siz2 = listBulletFromMainShip.size();
        while (siz2) {
            auto bullet =  listBulletFromMainShip.front();
            listBulletFromMainShip.pop_front();
            siz2--;
            bool check2 = true;

            if (ship->checkCollision(bullet->getPosX(), bullet->getPosY(), widthBullet, heightBullet, bullet->getAngle())) {
                if (ship->decHealth(bullet->getDamage())) {
                    score++;
                    check = false;
                }
                delete bullet;
                bullet = nullptr;
                break;
            }

            listBulletFromMainShip.push_back(bullet);
        }

        if (check) listShipType5.push_back(ship);
        else {
            delete ship;
            ship = nullptr;
        }
    }
}

inline void moveType5(deque<shipType5*> &listShipType5, deque<shipType1*> &listShipType1,MainCharacter* mainObjCharc) {
    for (auto ship: listShipType5) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();

        for (int i = 1; i <= 5; i++) {
            if (ship->check()) {
                shipType1* newship = new shipType1("a", 30, widthShipType1, heightShipType1);
                newship->appear();
                newship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
                listShipType1.push_back(newship);
            }
        }
    }
}

inline void renderType5(deque<shipType5*> &listShipType5, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType5) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
        ship->renderHealth(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), 3);
    }
}

inline tuple<float, float, float> findNearestType5(tuple<float, float, float> res, deque<shipType5*> &listShipType5, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType5) {
        if (dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY()) < get<0>(res)) {
            get<0>(res) = dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY());
            get<1>(res) = ship->getPosX();
            get<2>(res) = ship->getPosY();
        }
    }

    return res;
}
#endif // _SpaceShipType5__H