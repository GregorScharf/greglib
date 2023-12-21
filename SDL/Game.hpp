#include <SDL2/SDL.h>
#include "../all.hpp"

#ifndef GAME_HPP
#define GAME_HPP

namespace greg{
namespace SDL2{

class Game{
    public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    greg::FileData data;
    greg::SDL2::FrameHandle Frames;
    bool running;
    Game(const char* window_name, int x, int y, int width, int heigth, SDL_WindowFlags Flags){
        window = SDL_CreateWindow(window_name, x, y, width, heigth, Flags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        running = true;
    }
    void init(const char* file_name, int data_amount){
        data.init(data_amount, file_name);
        greg::String content = data.Read();
        int targetFPS[data_amount];
        greg::char_to_num<int>(content.get_array(), targetFPS);
        Frames.init(targetFPS[0]);
    }
};
}
}

#endif