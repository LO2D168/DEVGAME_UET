#ifndef _FuncSettings__H
#define _FuncSettings__H

#include "GameSettings.h"

//----------IMG Functions ---------

inline void quitProgram(SDL_Texture* render)
{
    SDL_DestroyTexture( render );
    render = NULL;
}

inline SDL_Renderer* createRenderer(SDL_Window* windows)
{
    SDL_Renderer* render = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (render == nullptr) errorWarningAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(render, SCREEN_WIDTH, SCREEN_HEIGHT);

    return render;
}

inline void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* render)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(render, texture, NULL, &dest);
}

inline SDL_Texture *loadTexture(const char *filename, SDL_Renderer* render)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    SDL_Texture *texture = IMG_LoadTexture(render, filename);
    if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return texture;
}

inline TTF_Font* loadFont(const char* path, int size)
{
    TTF_Font* gFont = TTF_OpenFont( path, size );
    if (gFont == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
                       "Load font %s", TTF_GetError());
    }
    return gFont;
}

inline  SDL_Texture* renderText(const char* text,
                            TTF_Font* font, SDL_Color textColor)
{
    SDL_Surface* textSurface =
            TTF_RenderText_Solid( font, text, textColor );
    if( textSurface == nullptr ) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
                       "Render text surface %s", TTF_GetError());
        return nullptr;
    }

    SDL_Texture* texture =
            SDL_CreateTextureFromSurface( renderer, textSurface );
    if( texture == nullptr ) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
                       "Create texture from text %s", SDL_GetError());
    }
    SDL_FreeSurface( textSurface );
    return texture;
}

inline void renderTextQ(SDL_Texture *texture, int x, int y, bool type)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    if (type) dest.x -= dest.w/2;
    SDL_RenderCopy(renderer, texture, NULL, &dest);
    SDL_RenderPresent(renderer);
}


//---------------------------------
inline int randW() {
    int sum = 0;
    for (int i = 1; i <= 7; i++) {
        sum += (1 << i);
    }

    int num = rand() % sum + 1;

    for (int i = 7; i >= 1; i--) {
        if (num <= (1 << i)) { return 7 - i + 1; }
        num -= (1 << i);
    }

    return num;
}



//---------------------------------

//---------------------------------

#endif // _FuncSettings__H

