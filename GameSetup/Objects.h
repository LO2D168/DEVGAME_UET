#ifndef _Objects__H
#define _Objects__H

#include "GameSettings.h"

typedef pair<double, double> vec;
#define fi first
#define se second
double angle = 0.0f;
vec rotatePoint(float cx, float cy, float angle, float px, float py)
{
    float s = sin(angle);
    float c = cos(angle);

    px -= cx;
    py -= cy;

    float xnew = px * c - py * s;
    float ynew = px * s + py * c;

    px = xnew + cx;
    py = ynew + cy;
    return {px, py};
}

class Obj
{
private:
    bool initObj;
protected:
    float posX, posY;
    float widthObj, heightObj;
    int speed;

    const char* linkImg = NULL;
    SDL_Texture* pointerToImg = NULL;
    float angleObj = 0.0f;

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

    bool checkCollisionObject(const Obj* that)
    {
        SDL_FRect rectA = {posX, posY, widthObj, heightObj};
        SDL_FRect rectB = {that->posX, that->posY, that->widthObj, that->heightObj};

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


    bool checkOutArea()
    {
        return (posX < 0 || posY < 0 || posX > SCREEN_WIDTH || posY > SCREEN_HEIGHT);
    }
    
    virtual void render(SDL_Texture* pointerImg)
    {
        SDL_FRect RectObj = {posX, posY, widthObj, heightObj};
        SDL_RenderCopyF(renderer, pointerImg, NULL, &RectObj);
    }

    bool checkCollision(const float thatX, const float thatY, const float thatWidth, const float thatHeight, const double thatAngle)
    {
          vec rectA[4] =
          {
             rotatePoint(posX, posY, angle, posX -  widthObj/ 2, posY - heightObj / 2),
             rotatePoint(posX, posY, angle, posX + widthObj / 2, posY - heightObj / 2),
             rotatePoint(posX, posY, angle, posX + widthObj / 2, posY + heightObj / 2),
             rotatePoint(posX, posY, angle, posX - widthObj / 2, posY + heightObj / 2)
          };

          vec rectB[4] =
          {
             rotatePoint(thatX, thatY, thatAngle, thatX -  thatWidth/ 2, thatY - thatHeight / 2),
             rotatePoint(thatX, thatY, thatAngle, thatX + thatWidth / 2, thatY - thatHeight  / 2),
             rotatePoint(thatX, thatY, thatAngle, thatX + thatWidth / 2, thatY + thatHeight  / 2),
             rotatePoint(thatX, thatY, thatAngle, thatX - thatWidth / 2, thatY + thatHeight  / 2)
          };

         // SAT (Separating Axis Theorem)
         vec axes[4] =
         {
            {rectA[1].fi - rectA[0].fi, rectA[1].se - rectA[0].se},
            {rectA[1].fi - rectA[2].fi, rectA[1].se - rectA[2].se},
            {rectB[0].fi - rectB[3].fi, rectB[0].se - rectB[3].se},
            {rectB[0].fi - rectB[1].fi, rectB[0].se - rectB[1].se}
         };

        for (int i = 0; i < 4; i++) {
            float length = sqrt(axes[i].fi * axes[i].fi + axes[i].se * axes[i].se);
            axes[i].fi /= length;
            axes[i].se /= length;
        }

        for (int i = 0; i < 4; i++)
        {

            float minA = INFINITY, maxA = -INFINITY;
            float minB = INFINITY, maxB = -INFINITY;

            for (int j = 0; j < 4; j++) {
                float projection = rectA[j].fi * axes[i].fi + rectA[j].se * axes[i].se;
                minA = fmin(minA, projection);
                maxA = fmax(maxA, projection);
            }

            for (int j = 0; j < 4; j++) {
                float projection = rectB[j].fi * axes[i].fi + rectB[j].se * axes[i].se;
                minB = fmin(minB, projection);
                maxB = fmax(maxB, projection);
            }

            if (maxA < minB || maxB < minA)
            {
                return false;
            }
        }

        return true;
    }
};

#endif // _Objects__H



