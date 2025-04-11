#ifndef _SETTINGBUTTON__H
#define _SETTINGBUTTON__H

#include "Menu.h"

class Slider {
    private:
        int posX, posY;
        const int heightSlider = 30, widthSlider = 300;
        const int heightButton = 50, widthButton = 50;
        int posXButton, posYButton;
    public:
        Slider(int a, int b, int type) {
            posX = a;
            posY = b;
            if (type) {
                posXButton = posX + (widthSlider/2 - 25);
                posYButton = posY + (heightSlider/2- 20);
            }
            else {
                posXButton = posX - 25;
                posYButton = posY - 5;
            }
        }

        bool checkInside(int x, int y) {
            return (posXButton <= x && x <= posXButton + widthButton && posYButton <= y && y <= posYButton + heightButton);
        }

        void update(int x) {
            if (x > posX + widthSlider) {x = posX + widthSlider;}
            if (x < posX) {x = posX;}
            posXButton = x - 20;
        }

        void render() {
            SDL_Rect rect = {posX, posY, abs(posXButton - posX + 20), heightSlider};
            SDL_RenderCopy(renderer, sliderPointerImg, NULL, &rect);
            rect = {posXButton, posYButton, widthButton, heightButton};
            SDL_RenderCopy(renderer, sliderButtonPointerImg, NULL, &rect);
        }

        void change(int &num, const float flag) {
            num = (flag * max(float(posXButton + 20) - posX, 0.0f)/widthSlider);
        }
};
Slider volObject(150, 275, 1), volBackground(150, 410, 1), gameLevel(150, 545, 0);
combatText objSetting;

void renderBackground(string &str, int delay, SDL_Rect &rect, SDL_Rect &fogRect) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundSettingPointerImg, NULL, &rect);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 139, 180);
    SDL_RenderFillRect(renderer, &fogRect);
    objSetting.renderTextRand(str, SCREEN_WIDTH - 82, SCREEN_HEIGHT * 2 / 9 - 40, 3);
    SDL_RenderPresent(renderer);
    SDL_Delay(delay);
}

inline void settingButton(SDL_Event &e) {
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, backgroundSettingPointerImg, NULL, &rect);

    for (int i = SCREEN_HEIGHT / 2; i >= SCREEN_HEIGHT/9; i -= 5) {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 0, 0, 139, 15);
        SDL_Rect fogRect = { 50, i, SCREEN_WIDTH - 100, SCREEN_HEIGHT - i * 2};
        SDL_RenderFillRect(renderer, &fogRect);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_Rect fogRect = { 50, SCREEN_HEIGHT/9, SCREEN_WIDTH - 100, SCREEN_HEIGHT * 7 / 9};
    SDL_Delay(100);

    string tmp, str = "setting board";
    for (auto c: str) {
        tmp.push_back(c);
        renderBackground(tmp, 50, rect, fogRect);
    }


    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    while (true) {
        SDL_RenderClear(renderer);
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        SDL_Rect Rect = {mouseX, mouseY, 30, 30};
        SDL_RenderCopy(renderer, back2PointerImg, NULL, &rect);
        volObject.render();
        volBackground.render();
        gameLevel.render();
        SDL_RenderCopy(renderer, mousePointerImg, NULL, &Rect);
        objSetting.renderTextRand("character sound:", 485, 250, 5, 3);
        objSetting.renderTextRand("background sound:", 510, 385, 5, 3);
        objSetting.renderTextRand("game difficulty:", 475, 520, 5, 3);
        SDL_RenderPresent(renderer);

        if ((SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT)) break;
        bool check = (e.button.button == SDL_BUTTON_LEFT);
        if (check) {
            if (volObject.checkInside(mouseX, mouseY)) {
                volObject.update(mouseX);
            }
            if (volBackground.checkInside(mouseX, mouseY)) {
                volBackground.update(mouseX);
            }
            if (gameLevel.checkInside(mouseX, mouseY)) {
                gameLevel.update(mouseX);
            }
        }

        volObject.change(volObj, constVolObj);
        Mix_VolumeChunk(mainShoot, volObj);
        Mix_VolumeChunk(shipShoot, volObj);
        Mix_VolumeChunk(shipExplore, volObj);
        Mix_VolumeChunk(shipExplore, volObj);
        Mix_VolumeChunk(TransButton, volObj);
        volBackground.change(volBack, constVolBack);
        Mix_VolumeMusic(volBack);
        gameLevel.change(levelGame, constLevelGame);

        keyboardState = SDL_GetKeyboardState(NULL);
        if (keyboardState[SDL_SCANCODE_RETURN]) break;
        SDL_Delay(2);
    }
}
#endif // _SETTINGBUTTON__H