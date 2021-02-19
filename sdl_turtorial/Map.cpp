#include "../include/Map.h"
#include "../include/TextureManager.hpp"

int lvl_1[10][15] = {
    { 0,0,1,1,1,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
    { 2,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 2,2,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 2,2,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
Map::Map(){
    dirt = textureManager::loadTexture("assest_img/floor_2.png");
    grass = textureManager::loadTexture("assest_img/floor_ladder.png");
    water = textureManager::loadTexture("assest_img/floor_spikes_anim_f3.png");

    loadMap(lvl_1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

void Map::loadMap(int a[10][15]){
    for(int row=0; row<10; row++){
        for(int col=0; col<15; col++){
            gameMap[row][col] = a[row][col];
        }
    }
}

void Map::drawMap(){
    int type = 0;
    for(int row=0; row<10; row++){
        for(int col=0; col<15; col++){
            type = gameMap[row][col];

            dest.x = col*32;
            dest.y = row*32;
            switch (type)
            {
            case 0:
                textureManager::draw(water, src, dest);
                break;
            case 1:
                textureManager::draw(grass, src, dest);
                break;
            case 2:
                textureManager::draw(dirt, src, dest);
                break;
            default:
                break;
            }
        }
    }
}
