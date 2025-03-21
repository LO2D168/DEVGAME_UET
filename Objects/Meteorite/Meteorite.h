#ifndef _Meteorite__H
#define _Meteorite__H

#include "C:/DevGame/GameSetup/GameBoard.h"
int timeForNewEvent = meteoEventSpeed;

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

};

list<Meteo*> listMeteoEvent;

void meteoFixedUpdate()
{
    for(auto meteoObj: listMeteoEvent)
    {
        meteoObj->moveToY();
    }

    while(!listMeteoEvent.empty())
    {
        if(listMeteoEvent.front()->getPosY() > SCREEN_HEIGHT)
        {
            delete listMeteoEvent.front();
            listMeteoEvent.pop_front();
        }
        else
        {
            break;
        }
    }

}

void meteoElapsedUpdate()
{
    if(timeFrame == timeForNewEvent)
    {
        timeForNewEvent += rand() % meteoEventSpeed + meteoEventSpeed / 2;

        int num = rand() % 3;
        for(int i = 1;  i <= num; i++)
        {
            Meteo *meteoObj = new Meteo(meteoArray[0], meteoSpeed, meteoWidth, meteoHeight);
            meteoObj->changePosY((-1) * meteoObj->getHeightObj() - 20 * i);
            meteoObj->changePosX(rand() % (SCREEN_WIDTH - meteoObj->getWidthObj()));

            listMeteoEvent.push_back(meteoObj);
        }
    }
}

void meteoRender()
{
    for(auto meteoObj: listMeteoEvent)
    {
        meteoObj->render(listPointerMeteo[meteoObj->getState()]);
    }
}

#endif // _Meteorite__H