#ifndef _healthBar__H
#define _healthBar__H

#include ".\GameSetup\GameBoard.h"

class healthbar {
  private:
    float health;
    float realHealth;
  public:
    void setUpHealth(float num) { health = realHealth = num; }
    bool decHealth(float num) {
      realHealth -= num;
      if(realHealth <= 0) {realHealth = 0; return true;}
      return false;
    }

    void renderHealth(float x, float y, float width, float height) {
        SDL_FRect rect = { x, y, width * (realHealth/health), height};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRectF(renderer, &rect);
    }

  virtual ~healthbar() = default;
};

#endif // _healthBar__H