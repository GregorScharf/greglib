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
    greg::FileData data;
    greg::SDL2::FrameHandle Frames;
    int *data_array;
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

    void init(const char* filename, int data_amount){
        data.file_name = filename;
        data.data_amount = data_amount;
        data_array = new int[data_amount];
        greg::String content = data.Read();
        greg::char_to_num<int>(content.get_ptr(), data_array);
        Frames.init(data_array[0]);
        running = true;
        if(window == NULL || renderer == NULL){
            window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
    }
    void quit(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        data.Write<int>(data_array);
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