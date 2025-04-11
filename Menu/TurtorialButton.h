#ifndef _TurtorialButton_H_
#define _TurtorialButton_H_

#include "Menu.h"

void printScore(int stX, int stY, int st, int en) {
    SDL_Color color = {255, 255, 255, 255};
    for (int i = st; i <= en; i++) {
        string num = to_string(scoreList[i]);
        string text = to_string(i + 1) + ": " + num;
        SDL_Texture* Text = renderText(text.c_str(), font, color);
        renderTextQ(Text, stX, stY, 0);
        int tx, ty;
        SDL_QueryTexture(Text, NULL, NULL, &tx, &ty);
        stY += ty + 1;
        SDL_Delay(100);
    }
}
inline void scoreBoardSide(SDL_Event &e) {
    font = loadFont("../font/FiraCode-Bold.ttf",40);
    loadData();

    char* str = "PRESS ESC TO EXIT";
    SDL_Color color = { 255, 0, 0, 255 };
    string tmp;
    for (int i = 0; i < std::strlen(str); i++) {
        SDL_RenderClear(renderer);
        SDL_Rect rectTurtorial = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
        SDL_RenderCopy(renderer, scoreBoardPointerImg, NULL, &rectTurtorial);
        tmp.push_back(str[i]);
        SDL_Texture* Text = renderText(tmp.c_str(), font, color);
        renderTextQ(Text, SCREEN_WIDTH / 2 + 20, 50, 1);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }

    SDL_RenderClear(renderer);
    SDL_Rect rectTurtorial = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, scoreBoardPointerImg, NULL, &rectTurtorial);
    SDL_Texture* Text = renderText(tmp.c_str(), font, color);
    renderTextQ(Text, SCREEN_WIDTH / 2, 50, 1);
    SDL_RenderPresent(renderer);

    printScore(100, 150, 0, 9);
    printScore(SCREEN_WIDTH - 260, 150, 10, 19);

    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    while (true) {
        if ((SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT)) break;
        keyboardState = SDL_GetKeyboardState(NULL);
        if (keyboardState[SDL_SCANCODE_ESCAPE]) {
            break;
        }
        SDL_Delay(16);
    }

    font = loadFont("../font/FiraCode-Bold.ttf",30);
}

void showScreen() {

    char* str = "HIT SPACE TO SEE YOUR SCORE";
    SDL_Color color = { 65, 105, 225, 255 };
    string tmp;
    for (int i = 0; i < std::strlen(str); i++) {
        SDL_RenderClear(renderer);
        SDL_Rect rectTurtorial = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
        SDL_RenderCopy(renderer, turtorialPointerImg, NULL, &rectTurtorial);
        tmp.push_back(str[i]);
        SDL_Texture* Text = renderText(tmp.c_str(), font, color);
        renderTextQ(Text, SCREEN_WIDTH / 2, 70, 1);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }

    SDL_RenderClear(renderer);
    SDL_Rect rectTurtorial = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, turtorialPointerImg, NULL, &rectTurtorial);
    SDL_Texture* Text = renderText(tmp.c_str(), font, color);
    renderTextQ(Text, SCREEN_WIDTH / 2, 70, 1);
    SDL_RenderPresent(renderer);
}

inline void turtorialButton(SDL_Event &e) {

    font = loadFont("../font/FiraCode-Bold.ttf",30);
    showScreen();

    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    while (true) {
        if ((SDL_PollEvent(&e) != 0) && (e.type == SDL_QUIT)) break;
        keyboardState = SDL_GetKeyboardState(NULL);
        if (keyboardState[SDL_SCANCODE_RETURN]) {
            break;
        }
        if (keyboardState[SDL_SCANCODE_SPACE]) {
            Mix_PlayChannel(-1, TransButton, 0);
            scoreBoardSide(e);
            showScreen();
            Mix_PlayChannel(-1, TransButton, 0);
        }
        SDL_Delay(16);
    }
    Mix_PlayChannel(-1, TransButton, 0);

    font = loadFont("../font/FiraCode-Bold.ttf",50);
}

#endif // _TurtorialButton_H_