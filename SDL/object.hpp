#include "../all.hpp"
#include <SDL2/SDL.h>


#ifndef OBJECT_HPP
#define OBJECT_HPP

namespace greg{
namespace SDL2{

typedef struct{
    float x;
    float y;
}Vec2;


class Rect{
    public:
    SDL_Rect self;
    void operator=(const SDL_Rect* rect){
        self = *rect;
    }
    void operator+=(Vec2 vec){
        self.x += vec.x;
        self.y += vec.y;
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
    Object(){
        dst_rect = NULL;
        src_rect = NULL;
        surface = NULL;
    }
    int init(SDL_Rect *dst, SDL_Rect *src, const char* image_path){
        if(surface != NULL){
            return 1;
        }
        dst_rect = dst;
        src_rect = src;
        surface = SDL_LoadBMP(image_path);
    }
    void shift_dst(Vec2 vec){
        dst_rect += vec;
    }
    void shift_src(Vec2 vec){
        src_rect += vec;
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