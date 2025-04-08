#ifndef HEART_H
#define HEART_H

#include ".\GameSetup\GameBoard.h"

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
                SDL_Rect RectObj = {SCREEN_WIDTH - (i + 1) * heathWidthObj, 0 , heathWidthObj, heathHeightObj};
                SDL_RenderCopy(renderer, pointerToHeartImg, NULL, &RectObj);
            }
        }
        if(heartPenalty) heartPenalty--;
    }

    void deleteHeart()
    {
        heartPenalty = penaltyValue;
    }

    virtual ~heart() = default;
};

#endif //HEART_H
