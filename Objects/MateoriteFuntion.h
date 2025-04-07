#ifndef _MateoriteFunction__H
#define _MateoriteFunction__H
#include "SetObj.h"

inline void meteoFixedUpdate()
{
    while(!listMeteoEvent.empty())
    {
        if(listMeteoEvent.front()->getPosY() > SCREEN_HEIGHT)
        {
            auto meteo = listMeteoEvent.front();
            listMeteoEvent.pop_front();
            delete meteo;
            meteo = nullptr;
        }
        else
        {
            break;
        }
    }

}

inline void meteoElapsedUpdate()
{
    for(auto meteoObj: listMeteoEvent)
    {
        meteoObj->moveToY();
    }

    if(timeFrame == timeForNewEvent)
    {
        timeForNewEvent += rand() % meteoEventSpeed + meteoEventSpeed / 2;

        int num = rand() % 2;
        for(int i = 1;  i <= num; i++)
        {
            Meteo *meteoObj = new Meteo(meteoArray[0], meteoSpeed, meteoWidth, meteoHeight);
            meteoObj->changePosY((-1) * meteoObj->getHeightObj() - 20 * i);
            meteoObj->changePosX(rand() % (SCREEN_WIDTH - meteoObj->getWidthObj()));

            listMeteoEvent.push_back(meteoObj);
        }
    }
}

inline void meteoRender()
{
    for(auto meteoObj: listMeteoEvent)
    {
        meteoObj->render(listPointerMeteo[meteoObj->getState()]);
    }
}

#endif// _MateoriteFunction__H