#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include <iostream>
#include <string>

#include "sdl2includes.hpp"

namespace engine{

    class Sprite{
    public:
        Sprite(std::string newDirectory);
        ~Sprite();

        void init();
        virtual void update(int x, int y);
        virtual void draw();
        virtual void shutdown();

    private:
        SDL_Texture * texture;
        std::string directory;
        std::pair<int, int> lenght;
        std::pair<int, int> axis;
        SDL_Rect renderQuad;
        SDL_Rect clipRect;
    };
}

#endif
