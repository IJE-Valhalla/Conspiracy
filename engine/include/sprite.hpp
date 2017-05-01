#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include <iostream>
#include <string>

#include "sdl2includes.hpp"

namespace engine{

    class Sprite{
    public:
        Sprite(std::string newDirectory, int newQuantity, int width, int height,int space);
        ~Sprite();

        void init();
        void shutdown();
        void draw(int x, int y);
        void setCurrentPositionFrame(int positionFrame);
        int next();
        void update(int x, int y);
        void setInterval(int firstPositionFrame, int lastPositionFrame);


    private:
        SDL_Texture * texture;
        std::string directory;
        int widthFrame;
        int heightFrame;
        int totalWidth;
        int totalHeight;
        int currentPositionFrame;
        int quantity;
        std::pair<int, int> interval;
        int spaceFrame;
        int abscissa;
    };
}

#endif
