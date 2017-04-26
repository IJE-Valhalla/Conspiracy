#include "sprite.hpp"
#include "engine.hpp"
#include "log.h"


namespace engine{

    Sprite::Sprite(std::string newDirectory){
        directory = newDirectory;
    }

    Sprite::~Sprite(){

    }

    void Sprite::init(){
        INFO("Init sprite.");
        SDL_Surface * image = NULL;
        image = IMG_Load(directory.c_str());

        if(image == NULL){
            ERROR("INIT SPRITE ERROR.");
            exit(-1);
        }

        texture = SDL_CreateTextureFromSurface(getGameCanvas(), image);

        if(texture == NULL){
            ERROR("CREATE TEXTURE SPRITE ERROR.");
            exit(-1);
        }

        setClip(0, 0, image->w, image->h);

        SDL_FreeSurface(image);

    }

    void Sprite::shutdown(){
        INFO("Destroy sprite.");
        SDL_DestroyTexture(texture);
        texture = NULL;
    }

    void Sprite::draw(int x, int y){
        SDL_Rect renderQuad = SDL_Rect{x, y, clipRect.w, clipRect.h};

        SDL_RenderCopy(getGameCanvas(), texture, NULL, &renderQuad);
    }

    void Sprite::setClip(int x, int y, int w, int h){
        clipRect = SDL_Rect{x, y, w, h};
    }
}
