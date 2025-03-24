#ifndef _Bullet__H
#define _Bullet__H

#include "C:\DevGame\GameSetup\GameBoard.h"
#include "C:\DevGame\Objects\SetObj.h"


class Bullet
{
protected:
    int state = 0;
    int vx = 0, vy = 0;
    int posX = 0, posY = 0;
    int speed = 0;
    double angle = 0.0f;
    int widthObj = 0, heightObj = 0;
public:
    Bullet(const int speed, int tx, int ty, int width, int height)
    {
        posX = tx;
        posY = ty;
        vx = mainObjCharc->getPosX() -  tx;
        vy = mainObjCharc->getPosY() -  ty;

        double srt = sqrt(vx * vx + vy * vy);
        vx /= srt;
        vy /= srt;

        angle = atan2(vy, vx) * (180.0 / M_PI);
    }
};
#endif // _Bullet__H