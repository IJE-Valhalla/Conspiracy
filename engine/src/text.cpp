#include "text.hpp"
#include "log.h"
#include "engine.hpp"

using namespace engine;

Text::Text( std::string  newText, std::string newFontPath, int newSize, bool isHighQuality, Color *newBackground, Color *newTextColor){
    text = newText;
    fontPath = newFontPath;
    size = newSize;
    font = NULL;
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

    loadFont();

    if(font == NULL){
        exit(-1);
    }

    SDL_Color color = {textColor->r, textColor->g, textColor->b, textColor->a};
    SDL_Color bg_color = {background->r, background->g, background->b, background->a};

    SDL_Surface * surface = NULL;

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

    if(surface == NULL){
        exit(-1);
    }

    texture = SDL_CreateTextureFromSurface(WindowManager::getGameCanvas(), surface);

    if (texture == NULL){
        exit(-1);
    }

    width = surface->w;
    height = surface->h;

    SDL_FreeSurface(surface);
}

void Text::shutdown(){
    INFO("Shutdown Text");

    SDL_DestroyTexture(texture);
    texture = NULL;

    font = NULL;

}

void Text::draw(int x, int y){
    SDL_Rect renderQuad = {
        x,  y, width, height
    };

    SDL_RenderCopy(WindowManager::getGameCanvas(), texture, NULL, &renderQuad);
}

void Text::loadFont(){
    font = TTF_OpenFont(fontPath.c_str(), size);

            if(font == NULL){
                    ERROR("Font invalid!");
                    exit(-1);
            }

}
