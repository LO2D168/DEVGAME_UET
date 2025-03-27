#ifndef _BulletFunction__H
#define _BulletFunction__H
#include "SetObj.h"

void bulletRender() {
    for (auto c: listBulletFromOtherShip) {
        c->render();
    }
    for (auto c: listBulletFromMainShip) {
        c->render();
    }
}

void bulletElapsedUpdate() {
    int siz = listBulletFromOtherShip.size();
    for (int i = 0; i < siz; i++) {
        auto bullet = listBulletFromOtherShip.front();
        listBulletFromOtherShip.pop_front();
        if (bullet->check()) {
            bullet->move();
            listBulletFromOtherShip.push_back(bullet);
        }
    }

    siz = listBulletFromMainShip.size();
    for (int i = 0; i < siz; i++) {
        auto bullet = listBulletFromMainShip.front();
        listBulletFromMainShip.pop_front();
        if (bullet->check()) {
            bullet->move();
            listBulletFromMainShip.push_back(bullet);
        }
    }
}
#endif// _BulletFunction__H