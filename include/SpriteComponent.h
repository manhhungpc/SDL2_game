#pragma once
#include "Components.h"
#include "SDL2/SDL.h"
#include "TextureManager.hpp"

class SpriteComponent : public Component
{
private:
    TransformComponent *transforms;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        setTex(path);
    }
    ~SpriteComponent(){
        SDL_DestroyTexture(texture);
    }

    void setTex(const char* path){
        texture = textureManager::loadTexture(path);
    }

    void init() override
    {
        transforms = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = transforms->width;
        srcRect.h = transforms->height;

    }
    void update() override
    {
        destRect.x = static_cast<int>(transforms->position.x);
        destRect.y = static_cast<int>(transforms->position.y);
        destRect.w = transforms->width * transforms->scale;
        destRect.h = transforms->height * transforms->scale;
    }
    void draw() override
    {
        textureManager::draw(texture, srcRect, destRect);
    }

};
