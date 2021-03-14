#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component{

public:
    vector2D position;
    vector2D velocity;

    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 3;
    TransformComponent(){
        position.zero();
    }
    TransformComponent(int sc){
        position.zero();
        scale = sc;
    }

    TransformComponent(float x,float y){
        position.zero();
    }

    TransformComponent(float x,float y, int h, int w, int sc){
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    void init() override{
        velocity.zero();
    }
    void update() override{
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};
