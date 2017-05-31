#ifndef ENGINE_TEXT_HPP
#define ENGINE_TEXT_HPP

#include <iostream>
#include <string>

#include "sdl2includes.hpp"
#include "engine.hpp"
#include "color.hpp"

namespace engine{

    class Text{
    public:
        Text( std::string  newText, std::string newFontPath, int newSize, bool isHighQuality, Color* newBackground, Color* newTextColor);
         ~Text(){}

        void init();
        void draw(int x, int y);
        void shutdown();
        void loadFont();

    protected:
        SDL_Texture * texture;
        TTF_Font * font;

        std::string text;
        std::string fontPath;
        int size;
        bool highQuality;

        Color *background;
        Color *textColor;
        int width;
        int height;
    };
}

#endif
