#ifndef _Meteorite__H
#define _Meteorite__H

#include "C:/DevGame/GameSetup/GameBoard.h"
inline int timeForNewEvent = meteoEventSpeed;

class Meteo : public Obj
{
protected:
    int state = 0;
public:

    Meteo(const char* c, const int speed, const int wobj, const int hobj) : Obj(c, speed, wobj, hobj) {}

    int getState()
    {
        return state / 16;
    }

    void moveToY(int inrc = 0) override
    {
        state++;
        state %= numMeteoImg*16;
        posY += speed;
    }

    virtual ~Meteo() {}
};

#endif // _Meteorite__H