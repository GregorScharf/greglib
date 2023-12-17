#include <SDL2/SDL.h>
#include <vector>
#include "../FileData.hpp"

#ifndef GAME_HPP
#define GAME_HPP

namespace greg{
namespace SDL2{

class Game{
    public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<int> data;
    Game(const char* window_name, int x, int y, int width, int heigth, SDL_WindowFlags Flags){
        window = SDL_CreateWindow(window_name, x, y, width, heigth, Flags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

};

}
}






#endif