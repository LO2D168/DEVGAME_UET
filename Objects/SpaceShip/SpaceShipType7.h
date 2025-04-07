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
        setUpHealth(1500);
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

inline void fixedUpdateType7(deque<shipType7*> &listShipType7, deque<Bullet*> &listBulletFromMainShip) {
    int siz = listShipType7.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType7.front();
        listShipType7.pop_front();

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

        if (check) listShipType7.push_back(ship);
        else {
            delete ship;
            ship = nullptr;
        }
    }
}

inline void moveType7(deque<shipType7*> &listShipType7, deque<Bullet*> &listBulletFromOtherShip, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType7) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();

        if (ship->check()) {
            Bullet* bullet = ship->getBullet();
            bullet->changeDirection(mainObjCharc->getPosX(), mainObjCharc->getPosY());
            listBulletFromOtherShip.push_back(bullet);

            bullet = ship->getBullet();
            bullet->changeDirection(mainObjCharc->getPosX(), mainObjCharc->getPosY() - 200);
            listBulletFromOtherShip.push_back(bullet);

            bullet = ship->getBullet();
            bullet->changeDirection(mainObjCharc->getPosX() - 200, mainObjCharc->getPosY());
            listBulletFromOtherShip.push_back(bullet);
        }
    }
}

inline void renderType7(deque<shipType7*> &listShipType7, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType7) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
        ship->renderHealth(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), 3);
    }
}

inline tuple<float, float, float> findNearestType7(tuple<float, float, float> res, deque<shipType7*> &listShipType7, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType7) {
        if (dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY()) < get<0>(res)) {
            get<0>(res) = dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY());
            get<1>(res) = ship->getPosX();
            get<2>(res) = ship->getPosY();
        }
    }

    return res;
}
#endif // _SpaceShipType7__H