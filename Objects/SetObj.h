#ifndef _SetObj__H
#define _SetObj__H

#include "../Objects/MainObj/MainObj.h"
#include "../Objects/Meteorite/Meteorite.h"
#include "../Objects/SpaceShip/SpaceShip.h"
#include "../Objects/Bullet/Bullet.h"

inline deque<shipType1*> listShipType1;
inline deque<shipType2*> listShipType2;
inline deque<shipType3*> listShipType3;
inline deque<shipType4*> listShipType4;
inline deque<shipType5*> listShipType5;
inline deque<shipType6*> listShipType6;
inline deque<shipType7*> listShipType7;

inline deque<Bullet*> listBulletFromOtherShip;
inline deque<Bullet*> listBulletFromMainShip;
inline MainCharacter* mainObjCharc = NULL;
inline deque<Meteo*> listMeteoEvent;

#endif //  _SetObj__H