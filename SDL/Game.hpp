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
    greg::File data;
    greg::SDL2::FrameHandle Frames;
    greg::Dy_Array<int> data_array;
    bool running;
    int data_amount;
    Game(const char* window_name, const int x, const int y, const int width, const int heigth, SDL_WindowFlags Flags){
        window = SDL_CreateWindow(window_name, x, y, width, heigth, Flags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        running = true;
        screen_rect.self.x = x;
        screen_rect.self.y = y;
        screen_rect.self.w = width;
        screen_rect.self.h = heigth;
        if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
            running = false;
            greg::costum_error("SDL could not initialize! SDL_Error: \n");
        }
    }

    void init(const char* filename, int _data_amount){
        data.set_path(filename);
        const char* content_buffer = data.read();
        data_amount = _data_amount;
        data_array = greg::char_to_num<int>(content_buffer);
        delete[] content_buffer;
        
        
        Frames.init(data_array[0]);
        running = true;
        if(window == NULL || renderer == NULL){
            window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
        loop();
    }
    void quit(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        greg::String content;
        for(int i = 0; i < data_amount; i++){
            content += greg::long_to_char(data_array[i]);
            content.append("\n");
        }
        data.write(content.get_ptr());
        SDL_Quit();
    }

    void loop(){
        while(running){
            Frames.handle_start();
            event_handler();
            const Uint8* key_state = SDL_GetKeyboardState(NULL);
            input_handler(key_state);
            update();
            render();
            Frames.handle_end();
        }
        quit();
    }

    void event_handler();
    void input_handler(const Uint8* key_state);
    void update();
    void render();

    Game(){
        window = NULL;
        renderer = NULL;
        running = false;
    }

};
}
}

#endif