#ifndef _GameBoard__H
#define _GameBoard__H

#include "GameSettings.h"
#include "FuncSettings.h"
#include "Objects.h"

inline int score = 0;

inline vector<SDL_Texture*> listPointerMeteo;
inline vector<SDL_Texture*> listPointerBulletForMainObj;
inline vector<SDL_Texture*> listPointerBulletType1;
inline vector<SDL_Texture*> listPointerBulletType2;
inline vector<SDL_Texture*> listPointerBulletType3;

inline int levelGame = 0;

inline void loadImg()
{
    for(int i = 0; i < numMeteoImg; i++)
    {
        SDL_Texture* pointerObj = loadTexture(meteoArray[i], renderer);
        listPointerMeteo.push_back(pointerObj);
    }

    pointerToHeartImg = loadTexture(linkToHeartImg, renderer);

    for(int i = 0; i < numTypeSpaceShip; i++)
    {
        SDL_Texture* pointerObj = loadTexture(linkToSpaceShip[i], renderer);
        listImgSpaceShip.push_back(pointerObj);
    }

    for (int i = 0; i < numBulletMain; i++) {
        SDL_Texture* pointerObj = loadTexture(bulletArray[i], renderer);
        listPointerBulletForMainObj.push_back(pointerObj);
    }

    for (int i = numBulletMain; i < numBulletMain + numBulletTyp1; i++) {
        SDL_Texture* pointerObj = loadTexture(bulletArray[i], renderer);
        listPointerBulletType1.push_back(pointerObj);
    }

    for (int i = numBulletMain + numBulletTyp1; i < numBulletMain + numBulletTyp1 + numBulletTyp2; i++) {
        SDL_Texture* pointerObj = loadTexture(bulletArray[i], renderer);
        listPointerBulletType2.push_back(pointerObj);
    }

    for (int i = numBulletMain + numBulletTyp1 + numBulletTyp2; i < numBulletMain + numBulletTyp1 + numBulletTyp2 + numBulletTyp3; i++) {
        SDL_Texture* pointerObj = loadTexture(bulletArray[i], renderer);
        listPointerBulletType3.push_back(pointerObj);
    }

    for (int i = 0; i <= 9; i++) {
        SDL_Texture* pointerObj = loadTexture(digit[i], renderer);
        digitPointerToImg[i] = pointerObj;
    }

    for (int i = 0; i < 26; i++) {
        SDL_Texture* pointerObj = loadTexture(alphabet[i], renderer);
        alphabetPointerToImg[i] = pointerObj;
    }

    for (int i = 0; i < 4; i++) {
        SDL_Texture* pointerObj = loadTexture(button[i], renderer);
        buttonPointerImg[i] = pointerObj;
    }
    menuPointerImg = loadTexture(menuImage, renderer);
    mousePointerImg = loadTexture(mouse, renderer);
    pausedPointerImg = loadTexture(pausedImg, renderer);
    endGamePointerImg = loadTexture(endGameImg, renderer);
}
#endif // _GameBoard__H