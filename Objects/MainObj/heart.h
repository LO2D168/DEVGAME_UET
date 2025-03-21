//
// Created by Admin on 3/21/2025.
//

#ifndef DEVGAME_HEART_H
#define DEVGAME_HEART_H

#include "C:\DevGame\GameSetup\GameBoard.h"

class heart
{
protected:
    int heartPenalty = 0;
public:
    void renderHeart(int num)
    {
        num += (heartPenalty > 0);
        for(int i = 0; i < num; i++)
        {
            if(i != num || (i == num && heartPenalty == 0) || (i == num && heartPenalty && (heartPenalty % 3 == 0)))
            {
                SDL_Rect RectObj = {i * heathWidthObj, 0 , heathWidthObj, heathHeightObj};
                SDL_RenderCopy(renderer, pointerToHeartImg, NULL, &RectObj);
            }
        }
        if(heartPenalty) heartPenalty--;
    }

    void deleteHeart()
    {
        heartPenalty = penaltyValue;
    }
};

#endif //DEVGAME_HEART_H
