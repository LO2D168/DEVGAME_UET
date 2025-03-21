#ifndef _Objects__H
#define _Objects__H

#include "GameBoard.h"

class Obj
{
private:
    bool initObj;
protected:
    int posX, posY;
    int widthObj, heightObj;
    int speed;

    const char* linkImg = NULL;
    SDL_Texture* pointerToImg = NULL;
public:

    SDL_Rect RectObj;

    Obj(const char* c, const int Speed, const int wobj, const int hobj)
    {
        widthObj = wobj;
        heightObj = hobj;
        initObj = true;
        speed = Speed;
        linkImg = c;

        //SDL_QueryTexture(pointerToImg, NULL, NULL, &widthImg, &heightImg);
    }

    virtual void moveToX(int incr)
    {
        posX += (speed * incr);
    }

    virtual void moveToY(int incr)
    {
        posY += (speed * incr);
    }

    int getPosX() {return posX;}
    int getPosY() {return posY;}
    int getWidthObj() {return widthObj;}
    int getHeightObj() {return heightObj;}
    bool getInitObj() {return initObj;}
    const char* getLinkImg() {return linkImg;}
    SDL_Texture* getPointerObj() {return pointerToImg;}

    void changePosX(int val) {posX = val;}
    void changePosY(int val) {posY = val;}
    void changeWidthObj(int val) {widthObj = val;}
    void changeHeightObj(int val) {heightObj = val;}
    void changInitObj(bool val) {initObj = val;}
    void changePointerObj(SDL_Texture* val) {pointerToImg = val;}

    virtual bool checkCollisionObject(const Obj* that)
    {
        SDL_Rect rectA = {posX, posY, widthObj, heightObj};
        SDL_Rect rectB = {that->posX, that->posY, that->widthObj, that->heightObj};

        // AABB algorithm
        if (rectA.x + rectA.w > rectB.x &&
            rectA.x < rectB.x + rectB.w &&
            rectA.y + rectA.h > rectB.y &&
            rectA.y < rectB.y + rectB.h)
        {
            return true;
        }
        return false;
    }

    virtual bool checkOutArea()
    {
        return (posX < 0 || posY < 0 || posX > SCREEN_WIDTH || posY > SCREEN_HEIGHT);
    }
    
    void render(SDL_Texture* pointerImg)
    {
        SDL_Rect RectObj = {posX, posY, widthObj, heightObj};
        SDL_RenderCopy(renderer, pointerImg, NULL, &RectObj);
    }
};
#endif // _Objects__H



