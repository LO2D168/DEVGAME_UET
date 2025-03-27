#ifndef _SpaceShip__H
#define _SpaceShip__H

#include "C:\DevGame\GameSetup\GameBoard.h"
#include "C:\DevGame\Objects\Bullet\Bullet.h"

class SpaceShip : public Obj
{
protected:
    double vx = 0.0f, vy = 0.0f;
    double angleObj = 0;
    int typeShip = 0;
    int idShip = 0;
    int targetX = 0, targetY = 0;
public:
    SpaceShip(const char* c, const int Speed, const int wobj, const int hobj) : Obj(c, Speed, wobj, hobj) {}

    void trackingMainObj(int x, int y)
    {
        vx = x - posX;
        vy = y - posY;

        targetX = x;
        targetY = y;

        double length = sqrt(vx*vx + vy*vy);
        vx /= length;
        vy /= length;

        angleObj = atan2(vy, vx) * (360.0 / M_PI);
    }

    int getType() {return typeShip;}

    double getAngle() { return angleObj; }

    virtual void appear()
    {
        int type = rand() % 3;

        switch (type) {
            case 0:
                posX = -widthObj;
                posY = rand() % (SCREEN_HEIGHT / 2) - heightObj;
                break;
            case 1:
                posX = rand() % SCREEN_WIDTH - widthObj;
                posY = -heightObj;
                break;
            case 2:
                posX = SCREEN_WIDTH;
                posY = rand() % (SCREEN_HEIGHT / 2) - heightObj;
                break;
        }
    }

    int dist(int x, int y, int u, int v) {
        return (u - x) * (u - x) + (v - y) * (v - y);
    }

    void move()
    {
        vector<tuple<int, int, int>> listChoice;
        for (int i = -speed; i <= speed; i++) {
            for (int j = -speed; j <= speed; j++) {
                if (abs(i) + abs(j) <= 2 * speed) {
                    listChoice.push_back(make_tuple(dist(targetX, targetY, posX + i, posY + j), posX + i, posY + j));
                }
            }
        }
        sort(listChoice.begin(), listChoice.end());
        posX = get<1>(listChoice[0]);
        posY = get<2>(listChoice[1]);
    }

    void render()
    {
        double angle = atan2(vy, vx) * (360.0 / M_PI);
        SDL_Rect rectObj = {posX, posY, widthObj, heightObj};
        SDL_RenderCopyEx(renderer, pointerToImg, NULL, &rectObj, angle, NULL, SDL_FLIP_NONE);
    }

    void getId(int val) {
        idShip = val;
    }

    virtual ~SpaceShip() = default;
};

#include "SpaceShipType1.h"
#include "SpaceShipType2.h"
#include "SpaceShipType3.h"
#include "SpaceShipType4.h"
#include "SpaceShipType5.h"
#include "SpaceShipType6.h"
#include "SpaceShipType7.h"
#endif // _SpaceShip__H
