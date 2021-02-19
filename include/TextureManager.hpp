#pragma once
#include "../include/game.hpp"
class textureManager{

public:
    static SDL_Texture* loadTexture(const char* fileName);
    static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};
