#pragma once
#include "Components.h"
#include "SDL2/SDL.h"

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

    void setTex(const char* path){
        texture = textureManager::loadTexture(path);
    }

    void init() override
    {
        transforms = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 64;
    }
    void update() override
    {
        destRect.x = (int)transforms->position.x;
        destRect.y = (int)transforms->position.y;
    }
    void draw() override
    {
        textureManager::draw(texture, srcRect, destRect);
    }

};
