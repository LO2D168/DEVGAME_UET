#ifndef _PlayButton__H
#define _PlayButton__H

#include "Menu.h"
void clearDeque(auto list) {
    while (list.size()) {
        auto obj = list.back();
        list.pop_back();
        delete obj;
        obj = nullptr;
    }
}

void setUp() {
    mainObjCharc = new MainCharacter(MainCharacterIMG, mainSpeed, mainWidthObj, mainHeightObj);
    setupScroll(); score = 0;
}

void reset() {
    // delete mainObjCharc;
    // mainObjCharc = nullptr;
    score = 0;
    timeFrame = 0;
    timeForNewEvent = meteoEventSpeed;
    timeForNewEventSpaceShip = 60;

    // clearDeque(listBulletFromOtherShip);
    // clearDeque(listBulletFromMainShip);
    // clearDeque(listMeteoEvent);
    // clearDeque(listShipType1);
    // clearDeque(listShipType2);
    // clearDeque(listShipType3);
    // clearDeque(listShipType4);
    // clearDeque(listShipType5);
    // clearDeque(listShipType6);
    // clearDeque(listShipType7);

    while (listBulletFromMainShip.size()) listBulletFromMainShip.pop_back();
    while (listBulletFromOtherShip.size()) listBulletFromOtherShip.pop_back();
    while (listMeteoEvent.size()) listMeteoEvent.pop_back();
    while (listShipType1.size()) listShipType1.pop_back();
    while (listShipType2.size()) listShipType2.pop_back();
    while (listShipType3.size()) listShipType3.pop_back();
    while (listShipType4.size()) listShipType4.pop_back();
    while (listShipType5.size()) listShipType5.pop_back();
    while (listShipType6.size()) listShipType6.pop_back();
    while (listShipType7.size()) listShipType7.pop_back();
}

inline void playButton(SDL_Event &e) {
    setUp();

    bool check = false;
    while(mainObjCharc->getHealth())
    {
        timeFrame++;
        if ( (SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT)) break;
        if (!check) FixedUpdate(), ElapsedUpdate();
        Render();

        if (check) {
            SDL_Rect rect = {SCREEN_WIDTH/5, SCREEN_HEIGHT/5, SCREEN_WIDTH/5 * 3, SCREEN_HEIGHT/5 * 3};
            SDL_RenderCopy(renderer, pausedPointerImg, NULL, &rect);
            SDL_RenderPresent(renderer);
        }

        SDL_Delay(16);

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_TAB]) {
            check = true;
        }

        if (check && currentKeyStates[SDL_SCANCODE_ESCAPE]) {
            break;
        }
        if (check && currentKeyStates[SDL_SCANCODE_RETURN]) {
            reset();
            check = false;
        }
        if (check && currentKeyStates[SDL_SCANCODE_SPACE]) {
            check = false;
        }
    }

    int timeDelay = 100;

    Render();
    SDL_Rect rect = {SCREEN_WIDTH/5, SCREEN_HEIGHT/5, SCREEN_WIDTH/5 * 3, SCREEN_HEIGHT/5 * 3};
    SDL_RenderCopy(renderer, endGamePointerImg, NULL, &rect);
    SDL_RenderPresent(renderer);
    while (timeDelay--) {
        SDL_Delay(30);
    }

    updateScore(score);
    reset();
}

#endif // _PlayButton__H