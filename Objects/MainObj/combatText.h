#ifndef _combatText__H
#define _combatText__H

#include "C:\DevGame\GameSetup\GameBoard.h"
#include "C:\DevGame\Objects\SetObj.h"
#include "C:\DevGame\Data\DataVocal.h"

char getChar()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if(currentKeyStates[SDL_SCANCODE_A]) return 'a';
    if(currentKeyStates[SDL_SCANCODE_B]) return 'b';
    if(currentKeyStates[SDL_SCANCODE_C]) return 'c';
    if(currentKeyStates[SDL_SCANCODE_D]) return 'd';
    if(currentKeyStates[SDL_SCANCODE_E]) return 'e';
    if(currentKeyStates[SDL_SCANCODE_F]) return 'f';
    if(currentKeyStates[SDL_SCANCODE_G]) return 'g';
    if(currentKeyStates[SDL_SCANCODE_H]) return 'h';
    if(currentKeyStates[SDL_SCANCODE_I]) return 'i';
    if(currentKeyStates[SDL_SCANCODE_J]) return 'j';
    if(currentKeyStates[SDL_SCANCODE_K]) return 'k';
    if(currentKeyStates[SDL_SCANCODE_L]) return 'l';
    if(currentKeyStates[SDL_SCANCODE_M]) return 'm';
    if(currentKeyStates[SDL_SCANCODE_N]) return 'n';
    if(currentKeyStates[SDL_SCANCODE_O]) return 'o';
    if(currentKeyStates[SDL_SCANCODE_P]) return 'p';
    if(currentKeyStates[SDL_SCANCODE_Q]) return 'q';
    if(currentKeyStates[SDL_SCANCODE_R]) return 'r';
    if(currentKeyStates[SDL_SCANCODE_S]) return 's';
    if(currentKeyStates[SDL_SCANCODE_T]) return 't';
    if(currentKeyStates[SDL_SCANCODE_U]) return 'u';
    if(currentKeyStates[SDL_SCANCODE_V]) return 'v';
    if(currentKeyStates[SDL_SCANCODE_W]) return 'w';
    if(currentKeyStates[SDL_SCANCODE_X]) return 'x';
    if(currentKeyStates[SDL_SCANCODE_Y]) return 'y';
    if(currentKeyStates[SDL_SCANCODE_Z]) return 'z';
    if(currentKeyStates[SDL_SCANCODE_0]) return '0';
    if(currentKeyStates[SDL_SCANCODE_1]) return '1';
    if(currentKeyStates[SDL_SCANCODE_2]) return '2';
    if(currentKeyStates[SDL_SCANCODE_3]) return '3';
    if(currentKeyStates[SDL_SCANCODE_4]) return '4';
    if(currentKeyStates[SDL_SCANCODE_5]) return '5';
    if(currentKeyStates[SDL_SCANCODE_6]) return '6';
    if(currentKeyStates[SDL_SCANCODE_7]) return '7';
    if(currentKeyStates[SDL_SCANCODE_8]) return '8';
    if(currentKeyStates[SDL_SCANCODE_9]) return '9';
    return '/';
}

class combatText
{
  private:
    string text;
    bool textEnd = true;
  public:
    void getText()
    {
       text = dictionary[rand() % mod_vocal];
    }

    void getWord()
    {
		if(textEnd)
        {
           textEnd = false;
           getText();
        }

        char c = getChar();
        if(c == text[0])
        {
           text.erase(text.begin());
        }

        if(text.size() == 0) textEnd = true;
	}

    bool getCheckWord()
    {
		return textEnd;
	}

   	void renderText()
    {
        float postextX = startTextX;
        float postextY = startTextY;

		for(int i = 0; i < text.size(); i++)
        {
            int texW = 0;
            int texH = 0;
            SDL_QueryTexture(alphabetPointerToImg[text[i] - 'a'], NULL, NULL, &texW, &texH);
            texW /= 5;
            texH = heightText / 2;
            SDL_FRect Rect = {postextX, postextY, float(texW), float(texH)};
            SDL_RenderCopyF(renderer, alphabetPointerToImg[text[i] - 'a'], NULL, &Rect);
            postextX += texW + 5;
            if(postextX >= SCREEN_WIDTH - 300)
            {
                  postextX = startTextX;
                  postextY += texH + 10;
            }
        }
	}
};

#endif // _combatText__H