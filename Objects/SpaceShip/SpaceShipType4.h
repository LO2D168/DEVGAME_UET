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
        setUpHealth(600);
    }

    void getframIn(int val) {
        framIn = val;
    }

    bool check() {
        return ((timeFrame - framIn) % speedShoot == 0);
    }
    Bullet* getBullet() {
        Mix_PlayChannel(-1, shipShoot, 0);
        Bullet* newBullet = new Bullet(speedBulletHigh, posX + widthObj/2, posY + heightObj/2, widthBullet, heightBullet, 1);
        return newBullet;
    }
};

inline void fixedUpdateType4(deque<shipType4*> &listShipType4, deque<Bullet*> &listBulletFromMainShip) {
    int siz = listShipType4.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType4.front();
        listShipType4.pop_front();

        bool check = true;

        int siz2 = listBulletFromMainShip.size();
        while (siz2) {
            auto bullet =  listBulletFromMainShip.front();
            listBulletFromMainShip.pop_front();
            siz2--;

            if (ship->checkCollision(bullet->getPosX(), bullet->getPosY(), widthBullet, heightBullet, bullet->getAngle())) {
                if (ship->decHealth(bullet->getDamage())) {
                    Mix_PlayChannel(-1, shipExplore, 0);
                    score++;
                    check = false;
                }
                delete bullet;
                bullet = nullptr;
                break;
            }
            listBulletFromMainShip.push_back(bullet);
        }

        if (check) listShipType4.push_back(ship);
        else {
            delete ship;
            ship = nullptr;
        }
    }
}

inline void moveType4(deque<shipType4*> &listShipType4, MainCharacter* mainObjCharc, deque<Bullet*> &listBulletFromOtherShip) {
    for (auto ship: listShipType4) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();
        if (ship->check()) {
            Bullet* bullet = ship->getBullet();
            bullet->changeDirection(mainObjCharc->getPosX(), mainObjCharc->getPosY());
            listBulletFromOtherShip.push_back(bullet);
        }
    }
}

inline void renderType4(deque<shipType4*> &listShipType4, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType4) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
        ship->renderHealth(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), 3);
    }
}

inline tuple<float, float, float> findNearestType4(tuple<float, float, float> res, deque<shipType4*> &listShipType4, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType4) {
        if (dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY()) < get<0>(res)) {
            get<0>(res) = dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY());
            get<1>(res) = ship->getPosX();
            get<2>(res) = ship->getPosY();
        }
    }

    return res;
}
#endif // _SpaceShipType4__H