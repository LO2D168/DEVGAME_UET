#ifndef _SpaceShipFunction__H
#define _SpaceShipFunction__H

#include "SetObj.h"
#include "../GameSetup/GameBoard.h"

inline int timeForNewEventSpaceShip = 60;
inline int speedSpaecshipEvent = 300 - levelGame;

inline void spaceShipFixedUpdate() {

    fixedUpdateType1(listShipType1, listBulletFromMainShip);
    fixedUpdateType2(listShipType2, listBulletFromMainShip);
    fixedUpdateType3(listShipType3, listBulletFromMainShip);
    fixedUpdateType4(listShipType4, listBulletFromMainShip);
    fixedUpdateType5(listShipType5, listBulletFromMainShip);
    fixedUpdateType6(listShipType6, listBulletFromMainShip);
    fixedUpdateType7(listShipType7, listBulletFromMainShip);
}

inline void spaceShipElapsedUpdate() {

    if(timeFrame == timeForNewEventSpaceShip)
    {
        timeForNewEventSpaceShip += rand() % speedSpaecshipEvent + speedSpaecshipEvent;

        int num = randW() % 7 + 1;
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

    moveType2(listShipType2, mainObjCharc);
    moveType3(listShipType3);
    moveType4(listShipType4, mainObjCharc, listBulletFromOtherShip);
    moveType5(listShipType5, listShipType1, mainObjCharc);
    moveType6(listShipType6, listBulletFromOtherShip, mainObjCharc);
    moveType7(listShipType7, listBulletFromOtherShip, mainObjCharc);
    moveType1(listShipType1, mainObjCharc);
}

inline void spaceShipRender() {
    renderType1(listShipType1, mainObjCharc);
    renderType2(listShipType2, mainObjCharc);
    renderType3(listShipType3, mainObjCharc);
    renderType4(listShipType4, mainObjCharc);
    renderType5(listShipType5, mainObjCharc);
    renderType6(listShipType6, mainObjCharc);
    renderType7(listShipType7, mainObjCharc);
}

#endif // _SpaceShipFunction__H
