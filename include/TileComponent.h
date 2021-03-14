#pragma once
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL2/SDL.h"

class tileComponent : public Component
{
public:
    TransformComponent *transforms;
    SpriteComponent *sprite;

    SDL_Rect tileRect;
    int tileID;
    const char *path;

    tileComponent()=default;
    tileComponent(int x, int y, int w, int h, int id){
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;

        switch (tileID){
            case 0:
                path = "assest_img/knight_f_idle_anim_f0.png";
                break;
            case 1:
                path = "assest_img/floor_1.png";
                break;
            case 2:
                path = "assest_img/floor_2.png";
                break;
            case 3:
                path = "assest_img/floor_3.png";
                break;
            case 4:
                path = "assest_img/floor_4.png";
                break;
            default:
                break;
        }
    }

    void init() override{
        entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
        transforms = &entity->getComponent<TransformComponent>();

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};
