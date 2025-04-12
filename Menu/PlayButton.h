#ifndef _PlayButton__H
#define _PlayButton__H

#include "Menu.h"
void clearDeque(auto &list) {
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
    delete mainObjCharc;
    mainObjCharc = nullptr;
    score = 0;
    timeFrame = 0;
    timeForNewEvent = meteoEventSpeed;
    timeForNewEventSpaceShip = 60;

    clearDeque(listBulletFromOtherShip);
    clearDeque(listBulletFromMainShip);
    clearDeque(listMeteoEvent);
    clearDeque(listShipType1);
    clearDeque(listShipType2);
    clearDeque(listShipType3);
    clearDeque(listShipType4);
    clearDeque(listShipType5);
    clearDeque(listShipType6);
    clearDeque(listShipType7);
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

    SDL_Color color = {255, 255, 255, 255};
    string num = to_string(score);
    SDL_Texture* Text = renderText(num.c_str(), font, color);
    float width = SCREEN_WIDTH, height = SCREEN_HEIGHT;
    int posX = width/5 +  (512.00 / 1024.00)*(width * 3.00 /5.00);
    int posY = height/5 + (950.00 / 1536.00)*(height * 3.00 / 5.00);
    renderTextQ(Text, posX, posY, 1);

    Mix_PlayChannel(-1, TransButton, 0);
    while (timeDelay--) {
        if ((SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT)) break;
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_SPACE]) break;
        SDL_Delay(30);
    }

    updateScore(score);
    reset();
}

#endif // _PlayButton__H