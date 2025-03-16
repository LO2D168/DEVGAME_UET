#ifndef _FuncSettings__H
#define _FuncSettings__H

#include "GameSettings.h"

//----------IMG Functions ---------

void errorWarningAndExit(const char* str, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", str, error);
    close();
}

void quitProgram(SDL_Texture* render)
{
    SDL_DestroyTexture( render );
    render = NULL;
}

SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) errorWarningAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    return renderer;
}

void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
    if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return texture;
}

//---------------------------------

#endif