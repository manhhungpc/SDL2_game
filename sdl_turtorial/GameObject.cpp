#include "../include/GameObject.h"
#include "../include/TextureManager.hpp"

gameObject::gameObject(const char* texturesheet, int x, int y){
    objTexture = textureManager::loadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void gameObject::Update(){
    xpos++;
    ypos++;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void gameObject::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
