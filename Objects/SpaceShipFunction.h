#ifndef _SpaceShipFunction__H
#define _SpaceShipFunction__H

#include "SetObj.h"
#include "../GameSetup/GameBoard.h"

int timeForNewEventSpaceShip = 120 - levelGame;

inline void spaceShipFixedUpdate() {
    int siz = 0;

    siz = listShipType1.size();
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

    siz = listShipType2.size();
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

    siz = listShipType3.size();
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
                delete bullet;
                check = false;
                break;
            }

            listBulletFromMainShip.push_back(bullet);
        }

        if (check) listShipType3.push_back(ship);
    }

    siz = listShipType4.size();
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
                delete bullet;
                check = false;
                break;
            }

            listBulletFromMainShip.push_back(bullet);
        }

        if (check) listShipType4.push_back(ship);
    }

    siz = listShipType5.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType5.front();
        listShipType5.pop_front();

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

        if (check) listShipType5.push_back(ship);
    }

    siz = listShipType6.size();
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
                delete bullet;
                check = false;
                break;
            }

            listBulletFromMainShip.push_back(bullet);
        }

        if (check) listShipType6.push_back(ship);
    }

    siz = listShipType7.size();
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
                delete bullet;
                check = false;
                break;
            }

            listBulletFromMainShip.push_back(bullet);
        }

        if (check) listShipType7.push_back(ship);
    }
}

inline void spaceShipElapsedUpdate() {

    if(timeFrame == timeForNewEventSpaceShip)
    {
        timeForNewEventSpaceShip += rand() % speedSpaecshipEvent + speedSpaecshipEvent;

        int num = randW();
        switch (num) {
            case 1: {
                int sl = rand() % 4 + 1;
                for (int i = 0; i < sl; i++) {
                    shipType1* ship = new shipType1("a", 5, widthShipType1, heightShipType1);
                    ship->appear();
                    ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
                    listShipType1.push_back(ship);
                }
            }
                break;
            case 2: {
                {
                    int sl = rand() % 3 + 1;
                    for (int i = 0; i < sl; i++) {
                        shipType2* ship = new shipType2("a", 30, widthShipType2, heightShipType2);
                        ship->appear();
                        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
                        listShipType2.push_back(ship);
                    }
                }
            }
                break;
            case 3: {
                int sl = rand() % 2 + 1;
                for (int i = 0; i < sl; i++) {
                    shipType3* ship = new shipType3("a", 30, widthShipType3, heightShipType3);
                    ship->appear();
                    ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
                    listShipType3.push_back(ship);
                }
            }
                break;
            case 4:{
                int sl = rand() % 3 + 1;
                for (int i = 0; i < sl; i++) {
                    shipType4* ship = new shipType4("a", 30, widthShipType4, heightShipType4);
                    ship->getframIn(timeFrame);
                    ship->appear();
                    ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
                    listShipType4.push_back(ship);
                }
            }
                break;
            case 5:
            {
                int sl = 1;
                for (int i = 0; i < sl; i++) {
                    shipType5* ship = new shipType5("a", 30, widthShipType5, heightShipType5);
                    ship->appear();
                    ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
                    listShipType5.push_back(ship);
                }
            }
                break;
            case 6:
            {
                int sl = rand() % 2 + 1;
                for (int i = 0; i < sl; i++) {
                    shipType6* ship = new shipType6("a", 30, widthShipType6, heightShipType6);

                    ship->getframIn(timeFrame);
                    ship->appear();
                    ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
                    listShipType6.push_back(ship);
                }
            }
                break;
            case 7: {
                {
                    int sl = rand() % 2 + 1;
                    for (int i = 0; i < sl; i++) {
                        shipType7* ship = new shipType7("a", 30, widthShipType7, heightShipType7);
                        ship->getframIn(timeFrame);
                        ship->appear();
                        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
                        listShipType7.push_back(ship);
                    }
                }
            }
                break;
        };
    }

    for (auto ship: listShipType2) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();
    }

    for (auto ship: listShipType3) {
        ship->move();
    }

    for (auto ship: listShipType4) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();
        if (ship->check()) {
            Bullet* bullet = ship->getBullet();
            bullet->changeDirection(mainObjCharc->getPosX(), mainObjCharc->getPosY());
            listBulletFromOtherShip.push_back(bullet);
        }
    }

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

            bullet = ship->getBullet();
            bullet->changeDirection(mainObjCharc->getPosX(), mainObjCharc->getPosY() - 100);
            listBulletFromOtherShip.push_back(bullet);

            bullet = ship->getBullet();
            bullet->changeDirection(mainObjCharc->getPosX() - 100, mainObjCharc->getPosY());
            listBulletFromOtherShip.push_back(bullet);
        }
    }

    for (auto ship: listShipType1) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->move();
    }

}

inline void spaceShipRender() {
    for (auto ship: listShipType1) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
    }
    for (auto ship: listShipType2) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
    }
    for (auto ship: listShipType3) {
        ship->tracking(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
    }
    for (auto ship: listShipType4) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
    }
    for (auto ship: listShipType5) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
    }
    for (auto ship: listShipType6) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
    }
    for (auto ship: listShipType7) {
        ship->trackingMainObj(mainObjCharc->getPosX(), mainObjCharc->getPosY());
        ship->render();
    }
}

#endif // _SpaceShipFunction__H
