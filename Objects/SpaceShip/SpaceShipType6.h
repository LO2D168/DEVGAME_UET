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
        setUpHealth(1500);
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
        Mix_PlayChannel(-1, shipShoot, 0);
        Bullet* newBullet = new Bullet(speedBulletMid, posX +  widthObj/2, posY + heightObj/2, widthBullet, heightBullet,2);
        return newBullet;
    }
};

inline void fixedUpdateType6(deque<shipType6*> &listShipType6, deque<Bullet*> &listBulletFromMainShip) {
    int siz = listShipType6.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType6.front();
        listShipType6.pop_front();

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

        if (check) listShipType6.push_back(ship);
        else {
            delete ship;
            ship = nullptr;
        }
    }
}

inline void moveType6(deque<shipType6*> &listShipType6, deque<Bullet*> &listBulletFromOtherShip, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType6) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();
        if (ship->check()) {
            ship->getPenalty();
            Bullet* bullet = ship->getBullet();
            bullet->changeDirection(mainObjCharc->getPosX(), mainObjCharc->getPosY());
            listBulletFromOtherShip.push_back(bullet);
        }

        if (ship->checkPenalty()) {
            Bullet* bullet = ship->getBullet();
            bullet->changeDirection(mainObjCharc->getPosX(), mainObjCharc->getPosY());
            listBulletFromOtherShip.push_back(bullet);
        }
    }
}

inline void renderType6(deque<shipType6*> &listShipType6, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType6) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
        ship->renderHealth(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), 3);
    }
}

inline tuple<float, float, float> findNearestType6(tuple<float, float, float> res, deque<shipType6*> &listShipType6, MainCharacter* mainObjCharc) {
    for (auto ship: listShipType6) {
        if (dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY()) < get<0>(res)) {
            get<0>(res) = dist(mainObjCharc->getPosX(), mainObjCharc->getPosY(), ship->getPosX(), ship->getPosY());
            get<1>(res) = ship->getPosX();
            get<2>(res) = ship->getPosY();
        }
    }

    return res;
}
#endif // _SpaceShipType6__H