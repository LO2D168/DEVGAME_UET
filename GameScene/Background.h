#ifndef _BackGround__H
#define _BackGround__H

#include "..\GameSetup\GameBoard.h"

int szHeightPic, szWidthPic;
int szPic1, szPic2;

inline void setupScroll()
{
    SDL_QueryTexture(pointerBackground, NULL, NULL, &szWidthPic, &szHeightPic);

    szPic1 = 0;
    szPic2 = -szHeightPic;
}
inline void scroll()
{
    szPic1 += scroll_speed;
    szPic2 += scroll_speed;

    if(szPic1 >= SCREEN_HEIGHT) szPic1 = szPic2 - szHeightPic;
    if(szPic2 >= SCREEN_HEIGHT) szPic2 = szPic1 - szHeightPic;

    SDL_RenderClear(renderer);
    SDL_Rect Part1 = {0, szPic1, SCREEN_WIDTH, szHeightPic};
    SDL_Rect Part2 = {0, szPic2, SCREEN_WIDTH, szHeightPic};

    SDL_RenderCopy(renderer, pointerBackground, NULL, &Part1);
    SDL_RenderCopy(renderer, pointerBackground, NULL, &Part2);
}

inline void createWindows()
{
    renderer = createRenderer(window);
    pointerBackground = loadTexture(background, renderer);
}

inline void closeWindows()
{
    //destroy renderer

    SDL_DestroyRenderer(renderer);
    quitProgram(pointerBackground);
}

#endif // _BackGround__H