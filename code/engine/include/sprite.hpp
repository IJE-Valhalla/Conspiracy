#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include <iostream>
#include <string>
#include <memory>

#include "sdl2includes.hpp"

namespace engine{

    class Sprite{
    public:
        Sprite(){}
        Sprite(std::string newDirectory);
        virtual ~Sprite(){}

        virtual void init();
        virtual void draw(int x, int y);
        virtual void shutdown();
        void setDrawSize(int w, int h);
    protected:
        std::shared_ptr<SDL_Texture> texture{nullptr};
        std::string directory{};
        std::pair<int, int> lenght{}; // Width and height from image.
        std::pair<int, int> axis{};
        SDL_Rect renderQuad{};
        SDL_Rect clipRect{};
        int drawWidth{0};
        int drawHeight{0};
    };
}

#endif
