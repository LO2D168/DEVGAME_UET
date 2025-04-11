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
        setUpHealth(1000);
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

        if (check) listShipType2.push_back(ship);
        else {
            delete ship;
            ship = nullptr;
        }
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
        ship->renderHealth(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), 3);
    }
}

inline tuple<float, float, float> findNearestType2(tuple<float, float, float> res, deque<shipType2*> &listShipType2, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType2) {
        if (dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY()) < get<0>(res)) {
            get<0>(res) = dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY());
            get<1>(res) = ship->getPosX();
            get<2>(res) = ship->getPosY();
        }
    }

    return res;
}

#endif // _SpaceShipType2__H