#pragma once

#include "game.hpp"
#include "ECS.h"
#include "Components.h"

class KeyBoardController : public Component
{
public:
    TransformComponent *transforms;
    void init() override{
        transforms = &entity->getComponent<TransformComponent>();
    }
    void update() override{
        if(Game::event.type == SDL_KEYDOWN){
            switch (Game::event.key.keysym.sym){
                case SDLK_w:
                    transforms->velocity.y = -1;
                    break;
                case SDLK_a:
                    transforms->velocity.x = -1;
                    break;
                case SDLK_s:
                    transforms->velocity.y = 1;
                    break;
                case SDLK_d:
                    transforms->velocity.x = 1;
                    break;
                default:
                    break;
            }
        }

        if(Game::event.type == SDL_KEYUP){
            switch (Game::event.key.keysym.sym){
                case SDLK_w:
                    transforms->velocity.y = 0;
                    break;
                case SDLK_a:
                    transforms->velocity.x = 0;
                    break;
                case SDLK_s:
                    transforms->velocity.y = 0;
                    break;
                case SDLK_d:
                    transforms->velocity.x = 0;
                    break;
                default:
                    break;
            }
        }
    }
};
