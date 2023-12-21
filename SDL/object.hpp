#include "../all.hpp"
#include <SDL2/SDL.h>


#ifndef OBJECT_HPP
#define OBJECT_HPP

namespace greg{
namespace SDL2{

class Rect{
    public:
    SDL_Rect self;
    void operator=(const SDL_Rect* rect){
        self = *rect;
    }
};

// texture needs to be loaded from outside the class
class Object{
    public:
    
    Rect src_rect;
    Rect dst_rect;
    SDL_Surface* surface;
    SDL_Texture* texture;
    Object(SDL_Rect *dst, SDL_Rect *src, const char* image_path){
        dst_rect = dst;
        src_rect = src;
        surface = SDL_LoadBMP(image_path);
    }
    void shift_dst(int x, int y){
        dst_rect.self.x += x;
        dst_rect.self.y += y;
    }
    void shift_src(int x, int y){
        src_rect.self.x += x;
        src_rect.self.y += y;
    }
    
    void set_dst(SDL_Rect *rect){
        dst_rect = rect;
    }   
    void set_src(SDL_Rect *rect){
        src_rect = rect;
    }
};
}
}
#endif