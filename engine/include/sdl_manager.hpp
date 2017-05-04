#ifndef SDL_MANAGER_HPP
#define SDL_MANAGER_HPP

#include <string>
#include "sdl2includes.hpp"

namespace engine{
    class SDLManager{
    public:
        bool initSDL();
        bool finalizeSDL();
    };
}
#endif
