#include "animation.hpp"
#include "sprite.hpp"
#include "engine.hpp"
#include "log.h"

namespace engine{

    Animation::Animation(std::string newDirectory, int rows, int columns, double allTime){
        directory = newDirectory;
        matrix.first = rows;
        matrix.second = columns;
        totalTime = allTime;
        currentPositionFrame = 0;
    }

    Animation::~Animation(){

    }


    void Animation::init(){
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

        widthFrame = lenght.first/matrix.second;
        heightFrame = lenght.second/matrix.first;

        quantity = static_cast<int>(lenght.first/matrix.second * lenght.second/matrix.first);

        SDL_FreeSurface(image);

    }

    void Animation::update(int x, int y){
        axis.first = x;
        axis.second = y;
        // TODO Calculate time per frame.
        int Y = (currentPositionFrame / (lenght.first / widthFrame));
        int X = (currentPositionFrame % (lenght.first  / widthFrame));

        clipRect = {X*widthFrame, Y*heightFrame, widthFrame, heightFrame};
        DEBUG("Axis in X:" << X*widthFrame << " Axis in Y:" << Y*heightFrame << " Position:" << currentPositionFrame);
    }

    void Animation::draw(){
        // Rendering in screen
        renderQuad = {axis.first, axis.second, clipRect.w, clipRect.h };

        SDL_RenderCopy(WindowManager::getGameCanvas(), texture, &clipRect, &renderQuad);
    }

    void Animation::next(){
        currentPositionFrame ++;

        if(currentPositionFrame > interval.second){
           currentPositionFrame = interval.first;
        }
    }

    void Animation::setCurrentPositionFrame(int positionFrame){
        currentPositionFrame = positionFrame;
    }

    void Animation::setInterval(int firstPosition, int lastPosition){
        if(firstPosition != interval.first || lastPosition != interval.second){
            currentPositionFrame = firstPosition;
            interval.first = firstPosition;
            interval.second = lastPosition;
            DEBUG("First Position: " << firstPosition << " Last Position: " << lastPosition);
        }
    }

    void Animation::shutdown(){
        INFO("Destroy sprite.");
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}
