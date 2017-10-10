#include "text.hpp"
#include "log.h"
#include "engine.hpp"
#include "text_manager.hpp"

using namespace engine;

Text::Text( std::string  newText, std::string newFontPath, int newSize, bool isHighQuality, const Color &newBackground, const Color &newTextColor){
    text = newText;
    fontPath = newFontPath;
    size = newSize;
    highQuality = isHighQuality;
    background = newBackground;
    textColor = newTextColor;
    init();
}


void Text::init(){

    if (fontPath == ""){
        WARN("Invalid path for font!");
        exit(-1);
    }

    font = TextManager::instance.loadFont(fontPath, size);

    SDL_Color color{textColor.r, textColor.g, textColor.b, textColor.a};
    SDL_Color bg_color{background.r, background.g, background.b, background.a};

    SDL_Surface * surface = nullptr;

    if (highQuality && bg_color.a == 0x00){
        surface = TTF_RenderText_Blended(
            font, text.c_str(), color
        );
    }
    else if (highQuality){
        surface = TTF_RenderText_Shaded(
            font, text.c_str(), color, bg_color
        );
    }
    else{
        surface = TTF_RenderText_Solid(
            font, text.c_str(), color
        );
    }

    if(surface == nullptr){
        exit(-1);
    }

    if(texture != nullptr){
                SDL_DestroyTexture(texture);
        }

    texture = SDL_CreateTextureFromSurface(WindowManager::getGameCanvas(), surface);

    if (texture == nullptr){
        exit(-1);
    }

    width = surface->w;
    height = surface->h;

    SDL_FreeSurface(surface);
}

void Text::shutdown(){
    INFO("Shutdown Text");

    SDL_DestroyTexture(texture);
    texture = nullptr;

    font = nullptr;

}

void Text::draw(int x, int y){
    SDL_Rect renderQuad = {
        x,  y, width, height
    };

    SDL_RenderCopy(WindowManager::getGameCanvas(), texture, NULL, &renderQuad);
}


void Text::setBackground(const Color &newBackground){
    background = newBackground;
    init();
}

void Text::setTextColor(const Color &newTextColor){
    textColor = newTextColor;
    init();
}
