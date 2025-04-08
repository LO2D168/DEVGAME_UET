#ifndef _Obj__H
#define _Obj__H

#include "BulletFunction.h"
#include "MainFunction.h"
#include "SpaceShipFunction.h"
#include "MateoriteFuntion.h"

void FixedUpdate()
{
    meteoFixedUpdate();
    spaceShipFixedUpdate();
    MainFixedUpdate();
}

void ElapsedUpdate()
{
    meteoElapsedUpdate();
    spaceShipElapsedUpdate();
    bulletElapsedUpdate();
    MainElapsedUpdate();
}

void Render()
{
    scroll();
    meteoRender();
    spaceShipRender();
    bulletRender();
    MainRender();
    SDL_RenderPresent(renderer);
}

#endif // _Obj__H