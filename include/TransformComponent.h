#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component{

public:
    vector2D position;
    vector2D velocity;

    int speed = 3;
    TransformComponent(){
        position.x = 0.0f;
        position.y = 0.0f;
    }
    TransformComponent(float x,float y){
        position.x = x;
        position.y = y;
    }

    void init() override{
        velocity.x = 0;
        velocity.y = 0;
    }
    void update() override{
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};
