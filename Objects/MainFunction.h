#ifndef _MainFunction__H
#define _MainFunction__H
#include "SetObj.h"

inline void var() {
    mainObjCharc->gotAttack();
    mainObjCharc->deleteHeart();
    mainObjCharc->penalty = penaltyValue;
}

inline void MainRender()
{
    mainObjCharc->renderHeart(mainObjCharc->getHealth() - 1);
    mainObjCharc->renderText();
    mainObjCharc->renderScore();
    // animation after collision
    if(mainObjCharc->penalty && (mainObjCharc->penalty % 3 != 0)) {return;}
    //
    mainObjCharc->render(mainObjCharc->getPointerObj());
    mainObjCharc->renderHeart(mainObjCharc->getHealth());
}

inline void MainFixedUpdate()
{
    if(mainObjCharc->penalty)
    {
        (mainObjCharc->penalty)--;
        return;
    }

    for(auto c: listMeteoEvent)
    {
        if(mainObjCharc->checkCollisionObject(c))
        {
            var();
            return;
        }
    }

    int siz = listShipType1.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType1.front();
        listShipType1.pop_front();
        if (mainObjCharc->checkCollision(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), ship->getHeightObj(), ship->getAngle())) {
            delete ship;
            var();
            return;
        }
        listShipType1.push_back(ship);
    }

    siz = listShipType2.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType2.front();
        listShipType2.pop_front();
        if (mainObjCharc->checkCollision(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), ship->getHeightObj(), ship->getAngle())) {
            delete ship;
            var();
            return;
        }
        listShipType2.push_back(ship);
    }

    siz = listShipType3.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType3.front();
        listShipType3.pop_front();
        if (mainObjCharc->checkCollision(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), ship->getHeightObj(), ship->getAngle())) {
            var(); delete ship;
            return;
        }
        listShipType3.push_back(ship);
    }

    siz = listShipType4.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType4.front();
        listShipType4.pop_front();
        if (mainObjCharc->checkCollision(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), ship->getHeightObj(), ship->getAngle())) {
            var(); delete ship;
            return;
        }
        listShipType4.push_back(ship);
    }

    siz = listShipType5.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType5.front();
        listShipType5.pop_front();
        if (mainObjCharc->checkCollision(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), ship->getHeightObj(), ship->getAngle())) {
            var(); delete ship;
            return;
        }
        listShipType5.push_back(ship);
    }

    siz = listShipType6.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType6.front();
        listShipType6.pop_front();
        if (mainObjCharc->checkCollision(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), ship->getHeightObj(), ship->getAngle())) {
            var(); delete ship;
            return;
        }
        listShipType6.push_back(ship);
    }

    siz = listShipType7.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShipType7.front();
        listShipType7.pop_front();
        if (mainObjCharc->checkCollision(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), ship->getHeightObj(), ship->getAngle())) {
            var(); delete ship;
            return;
        }
        listShipType7.push_back(ship);
    }

    siz = listBulletFromOtherShip.size();
    for (int i = 0; i < siz; i++) {
        auto bullet = listBulletFromOtherShip.front();
        listBulletFromOtherShip.pop_front();
        if (mainObjCharc->checkCollision(bullet->getPosX(), bullet->getPosY(), bullet->getWidthObj(), bullet->getHeightObj(), bullet->getAngle())) {
            var(); delete bullet;
            return;
        }
        listBulletFromOtherShip.push_back(bullet);
    }
}

inline void MainElapsedUpdate()
{
    mainObjCharc->getDirection();
    if(mainObjCharc->getInitObj() == true)
    {
        mainObjCharc->changePosX(SCREEN_WIDTH / 2 - mainWidthObj / 2);
        mainObjCharc->changePosY(SCREEN_HEIGHT - mainHeightObj);

        mainObjCharc->changePointerObj(loadTexture(mainObjCharc->getLinkImg(), renderer));
        mainObjCharc->changInitObj(false);
    }


    // const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    // if (currentKeyStates[SDL_SCANCODE_SPACE] && (timeFrame % 5 == 0)) {
    //     tuple<float, float, float> res(1e9, SCREEN_WIDTH/2, 0);
    //
    //     res = findNearestType1(res, listShipType1, mainObjCharc);
    //     res = findNearestType2(res, listShipType2, mainObjCharc);
    //     res = findNearestType3(res, listShipType3, mainObjCharc);
    //     res = findNearestType4(res, listShipType4, mainObjCharc);
    //     res = findNearestType5(res, listShipType5, mainObjCharc);
    //     res = findNearestType6(res, listShipType6, mainObjCharc);
    //     res = findNearestType7(res, listShipType7, mainObjCharc);
    //
    //     float targetX  = get<1>(res);
    //     float targetY  = get<2>(res);
    //
    //     mainObjCharc->getDirectionToTarget(targetX, targetY);
    //     Bullet* bullet = new Bullet(10, mainObjCharc->getPosX() + mainWidthObj/2 - 10, mainObjCharc->getPosY(), widthBullet, heightBullet, 4);
    //     bullet->changeDirection(targetX, targetY);
    //     listBulletFromMainShip.push_back(bullet);
    //     mainObjCharc->getDirectionToTarget(targetX, targetY);
    // }

    mainObjCharc->getWord();
    if (mainObjCharc->getCheckWord() == true &&
        (listShipType1.size() || listShipType2.size() || listShipType3.size() ||
            listShipType4.size() || listShipType5.size() || listShipType6.size() || listShipType7.size())) {
        tuple<float, float, float> res(1e9, SCREEN_WIDTH/2, 0);

        res = findNearestType1(res, listShipType1, mainObjCharc);
        res = findNearestType2(res, listShipType2, mainObjCharc);
        res = findNearestType3(res, listShipType3, mainObjCharc);
        res = findNearestType4(res, listShipType4, mainObjCharc);
        res = findNearestType5(res, listShipType5, mainObjCharc);
        res = findNearestType6(res, listShipType6, mainObjCharc);
        res = findNearestType7(res, listShipType7, mainObjCharc);

        float targetX  = get<1>(res);
        float targetY  = get<2>(res);

        mainObjCharc->getDirectionToTarget(targetX, targetY);
        Bullet* bullet = new Bullet(10, mainObjCharc->getPosX() + mainWidthObj/2 - 10, mainObjCharc->getPosY(), widthBullet, heightBullet, 4);
        bullet->changeDirection(targetX, targetY);
        listBulletFromMainShip.push_back(bullet);
        mainObjCharc->getDirectionToTarget(targetX, targetY);
    }
}

#endif// _MainFunction__H
