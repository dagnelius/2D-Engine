#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* player;
GameObject* enemy;
// SDL_Texture* playerTex;
// SDL_Rect srcR, dstR;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    
    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialised!" << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window) {
            std::cout << "Window Created!" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created!" << std::endl;
        }
        
        isRunning = true;
        
        player = new GameObject("../../../Assets/man1.bmp", 0, 0);
        enemy = new GameObject("../../../Assets/man2.bmp", 50, 50);
        map = new Map();

        std::cout << SDL_GetError() << std::endl;
        
        
    } else {
        
        isRunning = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
}

void Game::update() {
    player->Update();
    enemy->Update();
//    cnt++;
//    dstR.h = 64;
//    dstR.w = 64;
//    dstR.x = cnt;
//    std::cout << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->Render();
    enemy->Render();
    
    SDL_RenderPresent(renderer);
//    SDL_RenderClear(renderer);
//    SDL_RenderCopy(renderer, playerTex, NULL, &dstR);
//    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}
