#ifndef _Menu__H
#define _Menu__H

#include "GameSetup/GameBoard.h"
#include "GameScene/Scence.h"
#include "Objects/Obj.h"
#include "Data/DataVocal.h"
#include "Data/DataGame.h"

using namespace std;

bool playButtonCheck(int x, int y) {
    float X = 260.00 / 1024.00 * float(SCREEN_WIDTH);
    float Y = 817.00 / 1536.00 * float(SCREEN_HEIGHT);

    float width = 500.00 * float(SCREEN_WIDTH) / 1024.00;
    float height = 118.00 * float(SCREEN_HEIGHT) / 1536.00;

    return ((X <= x) && (X + width >= x) && (Y <= y) && (Y + height >= y));
}

bool settingButtonCheck(int x, int y) {
    float X = 260.00 / 1024.00 * float(SCREEN_WIDTH);
    float Y = 985.00 / 1536.00 * float(SCREEN_HEIGHT);

    float width = 500.00 * float(SCREEN_WIDTH) / 1024.00;
    float height = 118.00 * float(SCREEN_HEIGHT) / 1536.00;

    return ((X <= x) && (X + width >= x) && (Y <= y) && (Y + height >= y));
}

bool turtorialButtonCheck(int x, int y) {
    float X = 260.00 / 1024.00 * float(SCREEN_WIDTH);
    float Y = 1148.00 / 1536.00 * float(SCREEN_HEIGHT);

    float width = 500.00 * float(SCREEN_WIDTH) / 1024.00;
    float height = 118.00 * float(SCREEN_HEIGHT) / 1536.00;

    return ((X <= x) && (X + width >= x) && (Y <= y) && (Y + height >= y));
}

bool exitButtonCheck(int x, int y) {
    float X = 260.00 / 1024.00 * float(SCREEN_WIDTH);
    float Y = 1315.00 / 1536.00 * float(SCREEN_HEIGHT);

    float width = 500.00 * float(SCREEN_WIDTH) / 1024.00;
    float height = 118.00 * float(SCREEN_HEIGHT) / 1536.00;

    return ((X <= x) && (X + width >= x) && (Y <= y) && (Y + height >= y));
}

void renderButton(SDL_Texture* img, float num) {
    float X = 260.00 / 1024.00 * float(SCREEN_WIDTH) - 15.00;
    float Y = num / 1536.00 * float(SCREEN_HEIGHT) - 15.00;

    float width = 500.00 * float(SCREEN_WIDTH) / 1024.00 + 30.00;
    float height = 118.00 * float(SCREEN_HEIGHT) / 1536.00 + 30.00;

    SDL_FRect rect = {X, Y, width, height};
    SDL_RenderCopyF(renderer, img, NULL, &rect);
}

inline int renderMenu(SDL_Event &e)
{
    int num = 5;
    SDL_Rect Rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_RenderCopy(renderer, menuPointerImg, NULL, &Rect);
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    bool check = (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT);
    if (playButtonCheck(mouseX, mouseY)) {
        if (check) num = 1;
        renderButton(buttonPointerImg[0], 817);
    }

    if (settingButtonCheck(mouseX, mouseY)) {
        if (check) num = 2;
        renderButton(buttonPointerImg[1], 985);
    }

    if (turtorialButtonCheck(mouseX, mouseY)) {
        if (check) num = 3;
        renderButton(buttonPointerImg[2], 1148);
    }

    if (exitButtonCheck(mouseX, mouseY)) {
        if (check) num = 4;
        renderButton(buttonPointerImg[3], 1315);
    }

    Rect = {mouseX, mouseY, 30, 30};
    SDL_RenderCopy(renderer, mousePointerImg, NULL, &Rect);


    SDL_RenderPresent(renderer);

    SDL_Delay(10);
    return num;
}

#endif // _Menu__H
