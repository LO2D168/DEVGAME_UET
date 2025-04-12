#ifndef _combatText__H
#define _combatText__H

#include ".\GameSetup\GameBoard.h"
#include ".\Objects\SetObj.h"
#include ".\Data\DataVocal.h"

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
    int penaltyText = 0;
    string text;
    bool textEnd = true;
  public:
    void getText()
    {
       text = dictionary[rand() % min(mod_vocal, timeFrame/10 + 10)];
    	text = dictionary[rand() % 10];
    	//text = "ab";
    }
	void getStr(string &str) {
	    text = str;
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

        if(text.size() == 0) textEnd = true, penaltyText = 40;
	}

    bool getCheckWord()
    {
        if(penaltyText) penaltyText -= 1;
		return textEnd;
	}

   	void renderText(float postextX = startTextX, float postextY = startTextY)
    {
        float uY = postextY;

		for(int i = 0; i < text.size(); i++)
        {
            int texW = 0;
            int texH = 0;
            SDL_QueryTexture(alphabetPointerToImg[text[i] - 'a'], NULL, NULL, &texW, &texH);
            texW /= 4;
            texH = heightText / 2;
            SDL_FRect Rect = {postextX, postextY, float(texW), float(texH)};
            SDL_RenderCopyF(renderer, alphabetPointerToImg[text[i] - 'a'], NULL, &Rect);
            postextX += texW + 5;
            if(postextX >= SCREEN_WIDTH - 300)
            {
                  postextX = startTextX;
            	  if (i < text.size() - 1) postextY += texH + 10;
            }
            uY = max(uY, postextY + texH + 10);
        }

        if(penaltyText)
        {
              SDL_FRect Rect = {0, 0, 20, uY};
              SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
              SDL_RenderFillRectF(renderer, &Rect);
        }
        else
        {
              SDL_FRect Rect = {0, 0, 20, uY};
              SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
              SDL_RenderFillRectF(renderer, &Rect);
        }
	}

	void renderTextRand(string s, float qx, float qy, const int size = 6, const int sizeh = 2) {
    	reverse(s.begin(), s.end());
	    for (auto c: s) {
		    SDL_Texture *tex = NULL;
	    	if ('0' <= c && c <= '9') {tex = digitPointerToImg[c - '0'];}
	    	else if ('a' <= c && c <= 'z') {tex = alphabetPointerToImg[c - 'a'];}
	    	else if (c == ':')  {tex = specSync;}
	    	else { qx -= 10; continue;}


	    	int texW = 0;
	    	int texH = 0;
	    	SDL_QueryTexture(tex, NULL, NULL, &texW, &texH);
	    	texW /= size;
	    	texH = heightText / sizeh;

	    	if (tex == specSync) {
	    		texW = 15;
	    	}
	    	qx -= texW + 3;
	    	SDL_FRect Rect = {qx, qy, float(texW), float(texH)};
	    	SDL_RenderCopyF(renderer, tex, NULL, &Rect);
	    }
    }

	virtual ~combatText() = default;
};

#endif // _combatText__H