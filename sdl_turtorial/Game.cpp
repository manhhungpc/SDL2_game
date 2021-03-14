#include "../include/game.hpp"
#include "../include/TextureManager.hpp"
#include "../include/Map.h"
#include "../include/Components.h"
#include "../include/Vector2D.h"
#include "../include/Collision.h"
#include <iostream>

using namespace std;


Map *gameMap;
Manager manager;

SDL_Renderer *Game::renderer = 0;
SDL_Event Game::event;
vector<colliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());
auto& tile3(manager.addEntity());

Game::Game(){}
Game::~Game(){}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        cout<<"Subsystems initialize.."<<endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            cout<<"Window created"<<endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout<<"Window created"<<endl;
        }
        isRunning = true;
    }
    else {
        isRunning = false;
    }
    gameMap = new Map();

    tile1.addComponent<tileComponent>(200,200,32,32,1);
    tile2.addComponent<tileComponent>(250,250,32,32,2);
    tile2.addComponent<colliderComponent>("floor1");
    tile3.addComponent<tileComponent>(150,150,32,32,3);
    tile3.addComponent<colliderComponent>("floor2");

    player.addComponent<TransformComponent>(2);
    //player.addComponent<SpriteComponent>("assest_img/knight_f_idle_anim_f0.png");
    player.addComponent<tileComponent>(2,2,48,32,0);
    player.addComponent<KeyBoardController>();
    player.addComponent<colliderComponent>("player");

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 200, 1);
    wall.addComponent<SpriteComponent>("assest_img/wall_banner_red.png");
    wall.addComponent<colliderComponent>("wall");
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    manager.refresh();
    manager.update();
    for(auto cc:colliders){
        Collision::AABB(player.getComponent<colliderComponent>(), *cc);
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //gameMap->drawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout<<"Game cleaned"<<endl;
}
