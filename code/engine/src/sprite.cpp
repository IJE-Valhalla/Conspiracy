#include "sprite.hpp"
#include "engine.hpp"
#include "log.h"

using namespace engine;

    Sprite::Sprite(std::string newDirectory){
        directory = newDirectory;
        init();
    }

    void Sprite::init(){
        INFO("Init sprite.");
        SDL_Surface * image = IMG_Load(directory.c_str());

        if(image == nullptr){
            ERROR("INIT SPRITE ERROR.");
            exit(-1);
        }

        texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(WindowManager::getGameCanvas(), image), [=](SDL_Texture *t)
        {
            INFO("Destroy sprite.");
            SDL_DestroyTexture(t);
        });

        if(texture == nullptr){
            ERROR("CREATE TEXTURE SPRITE ERROR.");
            exit(-1);
        }

        drawWidth = lenght.first = image->w;
        drawHeight = lenght.second = image->h;
        SDL_FreeSurface(image);

    }

    void Sprite::shutdown(){

    }
    void Sprite::setDrawSize(int w, int h){
        drawWidth = w;
        drawHeight = h;
    }
    void Sprite::draw(int x, int y){
        axis.first = x;
        axis.second = y;
         //Crop image
        clipRect = {0, 0, lenght.first, lenght.second};

        // Rendering in screen
        renderQuad = {axis.first, axis.second, drawWidth, drawHeight };

        SDL_RenderCopy(WindowManager::getGameCanvas(), texture.get(), &clipRect, &renderQuad);
    }
