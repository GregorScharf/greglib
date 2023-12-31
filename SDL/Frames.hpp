#include <SDL2/SDL.h>

#ifndef FRAMES_HPP
#define FRAMES_HPP

namespace greg{
namespace SDL2{
class FrameHandle{
    public:
    Uint32 targetFrameTime;
    Uint32 currentTime, lastTime;
    Uint32 deltaTime;
    void init(int targetFPS){
        targetFrameTime = 1000/targetFPS;
        currentTime = 0;
        lastTime = 0;
        deltaTime = 0;
    }
    // call at the start of every loop
    void handle_start(){
        currentTime = SDL_GetTicks();
        deltaTime = currentTime - lastTime;

        if (deltaTime < targetFrameTime){
            SDL_Delay(targetFrameTime - deltaTime);
        }
    }
    // call at the end of every loop
    void handle_end(){
        lastTime = currentTime;
    }
};
}
}
#endif