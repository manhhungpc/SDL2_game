#pragma once
#include "SDL2/SDL.h"

class colliderComponent;
class Collision
{
public:
    static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
    static bool AABB(const colliderComponent& colA, const colliderComponent& colB);
};
