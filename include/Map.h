#pragma once
#include "game.hpp"

class Map{
public:
    Map();
    ~Map();

    void loadMap(int a[100][100]);
    void drawMap();

private:

    SDL_Rect src, dest;

    SDL_Texture* floor1;
    SDL_Texture* floor2;
    SDL_Texture* floor3;
    SDL_Texture* floor4;

    int gameMap[100][100];
};
