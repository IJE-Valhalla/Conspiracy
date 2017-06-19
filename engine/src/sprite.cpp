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
        SDL_Surface * image = NULL;
        image = IMG_Load(directory.c_str());

        if(image == NULL){
            ERROR("INIT SPRITE ERROR.");
            exit(-1);
        }

        texture = SDL_CreateTextureFromSurface(WindowManager::getGameCanvas(), image);

        if(texture == NULL){
            ERROR("CREATE TEXTURE SPRITE ERROR.");
            exit(-1);
        }

        lenght.first = image->w;
        lenght.second = image->h;
        SDL_FreeSurface(image);

    }

    void Sprite::shutdown(){
        INFO("Destroy sprite.");
        SDL_DestroyTexture(texture);
        texture = NULL;
    }

    void Sprite::draw(int x, int y){
        axis.first = x;
        axis.second = y;
         //Crop image
        clipRect = {0, 0, lenght.first, lenght.second};

        // Rendering in screen
        renderQuad = {axis.first, axis.second, clipRect.w, clipRect.h };

        SDL_RenderCopy(WindowManager::getGameCanvas(), texture, &clipRect, &renderQuad);
    }
