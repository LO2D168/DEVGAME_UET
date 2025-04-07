#ifndef _Bullet__H
#define _Bullet__H

#include ".\GameSetup\GameBoard.h"

class Bullet
{
protected:
    double vx = 0, vy = 0;
    float posX = 0, posY = 0;
    int speed = 0;
    float angle = 0.0f;
    float widthObj = 0, heightObj = 0;
    int type = 0;
    int state = 0;
    int number = 0;
    int damage = 0;
public:
    Bullet(const int Speed, float tx, float ty, int width, int height, int Type)
    {
        type = Type;
        posX = tx;
        posY = ty;
        widthObj = width;
        heightObj = height;
        speed = Speed;
        damage = 1000;

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
    float getPosX() {return posX;}
    float getPosY() {return posY;}
    float getWidthObj() {return widthObj;}
    float getHeightObj() {return heightObj;}
    float getAngle() {return angle;}
    void resetDamage() {damage = 0;}

    void move() {

        posX += speed * vx;
        posY += speed * vy;

        state++;
        state %= number * 16;
        damage -= 10;
        damage = max(damage, 0);
    }

    void changeDirection(int tx, int ty) {
        vx = tx - posX;
        vy = ty - posY;

        double srt = sqrt(vx * vx + vy * vy);
        angle = atan2f(vy, vx) * (180.0f / M_PI);
        angle += 90;

        vx /= srt;
        vy /= srt;
    }

    bool check() {
        return (posX <= SCREEN_WIDTH && posY <= SCREEN_HEIGHT && posX >= 0 && posY >= 0);
    }

    int getDamage() {return damage;}

    void render()
    {
        SDL_FRect rectObj = {posX, posY, widthObj, heightObj};
        switch (type) {
            case 1:
                SDL_RenderCopyExF(renderer, listPointerBulletType1[getState()], NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
                break;
            case 2:
                SDL_RenderCopyExF(renderer, listPointerBulletType2[getState()], NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
                break;
            case 3:
                SDL_RenderCopyExF(renderer, listPointerBulletType3[getState()], NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
                break;
            case 4:
                SDL_RenderCopyExF(renderer, listPointerBulletForMainObj[getState()], NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
                break;
        }

    }
};

#endif // _Bullet__H