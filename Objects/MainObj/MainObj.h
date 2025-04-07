#ifndef _MainObj__H
#define _MainObj__H


#include "heart.h"
#include "combatText.h"
#include ".\GameSetup\Objects.h"
#include ".\GameSetup\GameSettings.h"


class MainCharacter : public Obj, public heart, public combatText
{
protected:
    int health = 5;
public:
    int penalty = 0;
    MainCharacter(const char* c, const int speed, const int wobj, const int hobj) : Obj(c, speed, wobj, hobj) {}

    void getDirection()
    {
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if(currentKeyStates[SDL_SCANCODE_UP]) moveToX(0), moveToY(-1);
        if(currentKeyStates[SDL_SCANCODE_DOWN]) moveToX(0), moveToY(1);
        if(currentKeyStates[SDL_SCANCODE_LEFT]) moveToX(-1), moveToY(0);
        if(currentKeyStates[SDL_SCANCODE_RIGHT]) moveToX(1), moveToY(0);

        posX = max(posX, 0.0f); posX = min(posX, SCREEN_WIDTH - widthObj);
        posY = max(posY, 0.0f); posY = min(posY, SCREEN_HEIGHT - heightObj);
    }

    void getDirectionToTarget(float targetX, float targetY) {
        float vx = targetX - posX;
        float vy = targetY - posY;

        angleObj = atan2(vy, vx) * (180.0 / M_PI);
        angleObj += 90;
    }

    void render(SDL_Texture *pointerImg) {
        SDL_FRect RectObj = {posX, posY, widthObj, heightObj};
        SDL_RenderCopyExF(renderer, pointerToImg, NULL, &RectObj, angleObj, NULL, SDL_FLIP_NONE);
        if (abs(angleObj)) {
            if (angleObj > 0) {
                    angleObj -= 0.35;
                if (angleObj < 0) {
                    angleObj = 0;
                }
            }
            else {
                angleObj += 0.35;
                if (angleObj > 0) {
                    angleObj = 0;
                }
            }
        }
    }

    void renderScore() {
        string text = "score: ";
        string num;
        int tmp = score;
        if (tmp == 0) {
            num = "0";
        }
        while (tmp) {
            int digitZ = tmp % 10;
            tmp /= 10;
            num.push_back(digitZ + '0');
        }

        text += num;
        renderTextRand(text, SCREEN_WIDTH, 50);
    }

    void gotAttack() {health--;}
    int getHealth() {return health;}
    virtual ~MainCharacter() = default;
};
#endif // _MainObj__H