#include "sprite.hpp"
#include "engine.hpp"
#include "log.h"


namespace engine{

    Sprite::Sprite(std::string newDirectory, int newQuantity, int width, int height,int space){
        directory = newDirectory;
        quantity = newQuantity;
        widthFrame = width;
        heightFrame = height;
        interval.first = 1;
        interval.second = quantity;
        currentPositionFrame = interval.first;
        spaceFrame = space;
        abscissa = 0;
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

        texture = SDL_CreateTextureFromSurface(WindowManager::getGameCanvas(), image);

        if(texture == NULL){
            ERROR("CREATE TEXTURE SPRITE ERROR.");
            exit(-1);
        }

        totalWidth = image->w;
        totalHeight = image->h;

        SDL_FreeSurface(image);

    }

    void Sprite::shutdown(){
        INFO("Destroy sprite.");
        SDL_DestroyTexture(texture);
        texture = NULL;
    }

    void Sprite::draw(int x, int y){
         //Crop image
        SDL_Rect clipRect = {abscissa, 0 , widthFrame, heightFrame};

        // Rendering in screen
        SDL_Rect renderQuad = {x, y, clipRect.w, clipRect.h };

        SDL_RenderCopy(WindowManager::getGameCanvas(), texture, &clipRect, &renderQuad);
    }

    void Sprite::setInterval(int firstPosition, int lastPosition){
        if(firstPosition != interval.first || lastPosition != interval.second){
            currentPositionFrame = firstPosition;
            interval.first = firstPosition;
            interval.second = lastPosition;
            DEBUG("First Position: " << firstPosition << " Last Position: " << lastPosition);
        }
    }

    int Sprite::next(){
        if(currentPositionFrame > interval.second){
            currentPositionFrame = interval.first;
        }
        abscissa = (widthFrame + spaceFrame) * (currentPositionFrame - 1);
        currentPositionFrame ++;

        return abscissa;
    }

    void Sprite::update(int x, int y){
        abscissa = next();

        // draw(x,y);
    }

    void Sprite::setCurrentPositionFrame(int positionFrame){
        currentPositionFrame = positionFrame;
        next();
    }

}
