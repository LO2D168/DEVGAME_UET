#ifndef _Bullet__H
#define _Bullet__H

#include "C:\DevGame\GameSetup\GameBoard.h"

class Bullet
{
protected:
    double vx = 0, vy = 0;
    int posX = 0, posY = 0;
    int speed = 0;
    double angle = 0.0f;
    int widthObj = 0, heightObj = 0;
    int type = 0;
    int state = 0;
    int number = 0;
    double disX = 0, disY = 0;
    double _posX = 0, _posY = 0;
public:
    Bullet(const int Speed, int tx, int ty, int width, int height, int Type)
    {
        type = Type;
        _posX = posX = tx;
        _posY = posY = ty;
        widthObj = width;
        heightObj = height;
        speed = Speed;

        switch (type) {
            case 1:
                number = 4;
                break;
            case 2:
                number = 3;
                break;
            case 3:
                number = 2;
                break;
            case 4:
                number = 4;
                break;
        }
    }

    int getState() {return state/16;}
    int getPosX() {return posX;}
    int getPosY() {return posY;}
    int getWidthObj() {return widthObj;}
    int getHeightObj() {return heightObj;}
    double getAngle() {return angle;}

    void move() {
        _posX += disX * speed;
        _posY += disY * speed;

        posX = _posX;
        posY = _posY;

        state++;
        state %= number * 16;
    }

    void changeDirection(int tx, int ty) {
        vx = tx - posX;
        vy = ty - posY;

        double srt = sqrt(vx * vx + vy * vy);
        vx /= srt;
        vy /= srt;

        disX = vx;
        disY = vy;

        angle = atan2(vy, vx) * (360.0 / M_PI);
    }

    bool check() {
        return (posX <= SCREEN_WIDTH && posY <= SCREEN_HEIGHT && posX >= 0 && posY >= 0);
    }

    void render()
    {
        SDL_Rect rectObj = {posX, posY, widthObj, heightObj};
        switch (type) {
            case 1:
                SDL_RenderCopyEx(renderer, listPointerBulletType1[getState()], NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
                break;
            case 2:
                SDL_RenderCopyEx(renderer, listPointerBulletType2[getState()], NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
                break;
            case 3:
                SDL_RenderCopyEx(renderer, listPointerBulletType3[getState()], NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
                break;
            case 4:
                SDL_RenderCopyEx(renderer, listPointerBulletForMainObj[getState()], NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
                break;
        }

    }
};
#endif // _Bullet__H