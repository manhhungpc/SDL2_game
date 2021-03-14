#pragma once
#include <string>
#include "SDL2/SDL.h"
#include "Components.h"
//#include "ECS.h"

class colliderComponent : public Component
{
public:
    SDL_Rect collider;
    std::string tag;
    TransformComponent* transforms;
    colliderComponent(std::string t){
        tag = t;
    }

    void init() override{
        if(!entity->hasComponent<TransformComponent>()){
            entity->addComponent<TransformComponent>();
        }
        transforms = &entity->getComponent<TransformComponent>();
        Game::colliders.push_back(this);
    }

    void update() override{
        collider.x = static_cast<int>(transforms->position.x);
        collider.y = static_cast<int>(transforms->position.y);
        collider.w = transforms->width * transforms->scale;
        collider.h = transforms->height * transforms->scale;
    }
};
