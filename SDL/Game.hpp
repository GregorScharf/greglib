#include <SDL2/SDL.h>
#include "../all.hpp"
#include "object.hpp"

#ifndef GAME_HPP
#define GAME_HPP

namespace greg{
namespace SDL2{

class Game{
    public:
    greg::SDL2::Rect screen_rect;
    SDL_Window* window;
    SDL_Renderer* renderer;
    greg::FileData data = greg::FileData(1, "test.txt");
    greg::SDL2::FrameHandle Frames;
    int *targetFPS;
    bool running;
    Game(const char* window_name, const int x, const int y, const int width, const int heigth, SDL_WindowFlags Flags){
        window = SDL_CreateWindow(window_name, x, y, width, heigth, Flags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        running = true;
        screen_rect.self.x = x;
        screen_rect.self.y = y;
        screen_rect.self.w = width;
        screen_rect.self.h = heigth;
    }

    void init(const char* file_name, int data_amount){
        greg::String content = data.Read();
        greg::char_to_num<int>(content.get_array(), targetFPS);
        content.~String();
        Frames.init(targetFPS[0]);
        running = true;
        if(window == NULL || renderer == NULL){
            window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
        
    }
    void quit(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        data.Write<int>(targetFPS);
        SDL_Quit();
    }
    Game(){
        window = NULL;
        renderer = NULL;
        running = false;
    }

};
}
}

#endif