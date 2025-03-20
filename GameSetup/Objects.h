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
    int widthImg, heightImg;
    int speed;

    const char* linkImg;
    SDL_Texture* pointerToImg = NULL;

public:

    Obj(const char* c, const int Speed, const int wobj, const int hobj)
    {
        this->widthObj = wobj;
        this->heightObj = hobj;
        this->initObj = true;
        this->speed = Speed;
        this->linkImg = c;
        //this->pointerToImg = loadTexture(c, renderer);

        SDL_QueryTexture(this->pointerToImg, NULL, NULL, &this->widthImg, &this->heightImg);
    }

    virtual void moveToX(int incr)
    {
        this->posX += (this->speed * incr);
    }

    virtual void moveToY(int incr)
    {
        this->posY += (this->speed * incr);
    }

    virtual int getPosX() {return posX;}
    virtual int getPosY() {return posY;}
    virtual int getWidthObj() {return widthObj;}
    virtual int getHeightObj() {return heightObj;}
    virtual int getWidthImg() {return widthImg;}
    virtual int getHeightImg() {return heightImg;}
    virtual const char* getLinkImg() {return linkImg;}
    virtual SDL_Texture* getPointerObj() {return pointerToImg;}

    virtual void changePosX(int val) {posX = val;}
    virtual void changePosY(int val) {posY = val;}
    virtual void changeWidthObj(int val) {widthObj = val;}
    virtual void changeHeightObj(int val) {heightObj = val;}
    virtual void changeWidthImg(int val) {widthImg = val;}
    virtual void changeHeightImg(int val) {heightImg = val;}
    virtual void changeLinkImg(const char* val) {linkImg = val;}
    virtual void changePointerObj(SDL_Texture* val) {pointerToImg = val;}

    virtual bool checkCollisionObject(const Obj &that)
    {
        SDL_Rect rectA = {this->posX, this->posY, this->widthObj, this->heightObj};
        SDL_Rect rectB = {that.posX, that.posY, that.widthObj, that.heightObj};

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

    virtual ~Obj()
    {
        quitProgram(this->pointerToImg);
    }

    virtual bool checkOutArea()
    {
        return (posX < 0 || posY < 0 || posX > SCREEN_WIDTH || posY > SCREEN_HEIGHT);
    }
};
#endif // _Objects__H



