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
        Text( std::string  newText, std::string newFontPath, int newSize, bool isHighQuality, const Color &newBackground, const Color &newTextColor);
         ~Text(){}

        void init();
        void draw(int x, int y);
        void shutdown();
        void loadFont();
        void setBackground(const Color &newBackground);
        void setTextColor(const Color &newTextColor);
    protected:
        SDL_Texture * texture{nullptr};
        TTF_Font * font{nullptr};

        std::string text{};
        std::string fontPath{};
        int size{0};
        bool highQuality{false};

        Color background{0,0,0,0};
        Color textColor{0,0,0,0};
        int width{0};
        int height{0};
    };
}

#endif
