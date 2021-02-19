#pragma once
#include "game.hpp"

class Map{
public:
    Map();
    ~Map();

    void loadMap(int a[10][15]);
    void drawMap();

private:

    SDL_Rect src, dest;

    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int gameMap[10][15];
};
