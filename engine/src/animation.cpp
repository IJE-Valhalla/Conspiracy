#include "animation.hpp"

Animation::Animation(std::string newDirectory, int rows, int columns, double allTime){
    directory = newDirectory;
    matrix.first = rows;
    matrix.second = columns;
    totalTime = allTime;
    currentPositionFrame = 0;
}

Animation::~Animation(){

}

void Animation::draw(){

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

void Animation::update(int x, int y){
    axis.first = x;
    axis.second = y;


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
