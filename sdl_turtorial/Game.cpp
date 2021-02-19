#include "../include/game.hpp"
#include "../include/TextureManager.hpp"
#include "../include/Map.h"
#include "../include/Components.h"
#include "../include/Vector2D.h"
#include <iostream>

using namespace std;


Map *gameMap;
Manager manager;

SDL_Renderer *Game::renderer = 0;
SDL_Event Game::event;
auto& player(manager.addEntity());

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

    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("assest_img/knight_f_idle_anim_f0.png");
    player.addComponent<KeyBoardController>();
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

}

void Game::render()
{
    SDL_RenderClear(renderer);
    gameMap->drawMap();
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
