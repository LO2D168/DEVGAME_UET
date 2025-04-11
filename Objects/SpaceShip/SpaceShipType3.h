#ifndef _SpaceShipType3__H
#define _SpaceShipType3__H

#include "SpaceShip.h"

class shipType3: public SpaceShip
{
protected:
    const int speedType3 = 3;
public:
    shipType3(const char* c, const int Speed, const int wobj, const int hobj) : SpaceShip(c, Speed, wobj, hobj)
    {
        speed = speedType3;
        pointerToImg = listImgSpaceShip[4];
        typeShip = 3;
        setUpHealth(500);
    }

    void tracking(int x, int y)
    {
        vx = x - posX;
        vy = y - posY;

        double length = sqrt(vx*vx + vy*vy);
        vx /= length;
        vy /= length;

        angleObj = atan2(vy, vx) * (360.0 / M_PI);
    }
};

inline void fixedUpdateType3(deque<shipType3*> &listShipType3, deque<Bullet*> &listBulletFromMainShip) {
    int siz = listShipType3.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType3.front();
        listShipType3.pop_front();

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

        if (check) listShipType3.push_back(ship);
        else {
            delete ship;
            ship = nullptr;
        }
    }
}

inline void moveType3(deque<shipType3*> &listShipType3) {
    for (auto ship: listShipType3) {
        ship->move();
    }
}

inline void renderType3(deque<shipType3*> &listShipType3, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType3) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
        ship->renderHealth(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), 3);
    }
}

inline tuple<float, float, float> findNearestType3(tuple<float, float, float> res, deque<shipType3*> &listShipType3, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType3) {
        if (dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY()) < get<0>(res)) {
            get<0>(res) = dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY());
            get<1>(res) = ship->getPosX();
            get<2>(res) = ship->getPosY();
        }
    }

    return res;
}
#endif // _SpaceShipType3__H