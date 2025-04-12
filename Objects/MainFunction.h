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

void checkShip(auto &listShip) {
    int siz = listShip.size();
    for (int i = 0; i < siz; i++) {
        auto ship = listShip.front();
        listShip.pop_front();
        if (mainObjCharc->checkCollision(ship->getPosX(), ship->getPosY(), ship->getWidthObj(), ship->getHeightObj(), ship->getAngle())) {
            Mix_PlayChannel(-1, mainExplore, 0);
            delete ship;
            ship = NULL;
            var();
            return;
        }
        listShip.push_back(ship);
    }
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
            Mix_PlayChannel(-1, mainExplore, 0);
            var();
            return;
        }
    }

    checkShip(listShipType1);
    checkShip(listShipType2);
    checkShip(listShipType3);
    checkShip(listShipType4);
    checkShip(listShipType5);
    checkShip(listShipType6);
    checkShip(listShipType7);

    int siz = listBulletFromOtherShip.size();
    for (int i = 0; i < siz; i++) {
        auto bullet = listBulletFromOtherShip.front();
        listBulletFromOtherShip.pop_front();
        if (mainObjCharc->checkCollision(bullet->getPosX(), bullet->getPosY(), bullet->getWidthObj(), bullet->getHeightObj(), bullet->getAngle())) {
            Mix_PlayChannel(-1, mainExplore, 0);
            var(); delete bullet;
            bullet = NULL;
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
        Mix_PlayChannel(-1, mainShoot, 0);
        listBulletFromMainShip.push_back(bullet);
        mainObjCharc->getDirectionToTarget(targetX, targetY);
    }
}

#endif// _MainFunction__H
