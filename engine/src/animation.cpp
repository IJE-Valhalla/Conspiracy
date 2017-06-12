#include "animation.hpp"

using namespace engine;

Animation::Animation(std::string newDirectory, int rows, int columns, double allTime){
    directory = newDirectory;
    matrix.first = rows;
    matrix.second = columns;
    totalTime = allTime;
    currentPositionFrame = 0;
    init();
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

void Animation::update(){
    double timePerFrame = static_cast<double> (totalTime / (interval.second.second - interval.second.first + 1));

    timeElapsed = (SDL_GetTicks() - stepTime) / 1000.0f;
    DEBUG("Time Per Frame: " << timePerFrame << "Time elapsed: " << timeElapsed);

    if(timeElapsed >= timePerFrame){
        next();
        stepTime = SDL_GetTicks();
    }

    int Y = (currentPositionFrame / (lenght.first / widthFrame));
    int X = (currentPositionFrame % (lenght.first  / widthFrame));

    clipRect = {X*widthFrame, Y*heightFrame, widthFrame, heightFrame};
    DEBUG("Axis in X:" << X*widthFrame << " Axis in Y:" << Y*heightFrame << " Position:" << currentPositionFrame);
}

void Animation::draw(int x, int y){
    INFO("ANIMATOR DRAW");
    // Rendering in screen
    renderQuad = {x, y, clipRect.w, clipRect.h };
    DEBUG("X: " + std::to_string(axis.first));
    DEBUG("Y: " + std::to_string(axis.second));

    AnimationQuad* newQuad = new AnimationQuad(x,y,&renderQuad,&clipRect,texture);
    AnimationManager::instance.add_animation_quad(newQuad);
}

void Animation::draw_collider(int x, int y, int width, int height){
    SDL_Rect* quad = new SDL_Rect();
    *quad = {x,y,width,height};
    AnimationManager::instance.add_collider(quad);
}
void Animation::draw_instant(int x, int y){
    INFO("ANIMATOR DRAW");
    // Rendering in screen
    renderQuad = {x, y, clipRect.w, clipRect.h };
    DEBUG("X: " + std::to_string(axis.first));
    DEBUG("Y: " + std::to_string(axis.second));
    SDL_RenderCopy(WindowManager::getGameCanvas(), texture, &clipRect, &renderQuad);

}

void Animation::next(){
    currentPositionFrame ++;

    if(currentPositionFrame > interval.second.second){
       currentPositionFrame = interval.second.first;
    }
}

void Animation::setCurrentPositionFrame(int positionFrame){
    currentPositionFrame = positionFrame;
}

void Animation::setInterval(std::string action){
    if(action != interval.first){
        startTime = SDL_GetTicks();
        stepTime = startTime;
        interval.second =  list_actions[action];
        interval.first = action;
        currentPositionFrame = interval.second.first;
        INFO("ACTION: " << action << currentPositionFrame);
    }
}
void Animation::setTotalTime(double newTotalTime){
    totalTime = newTotalTime;
}

void Animation::shutdown(){
    INFO("Destroy sprite.");
    SDL_DestroyTexture(texture);
    texture = NULL;
}

std::pair<std::string, std::pair<int, int>> Animation::getInterval(){
    return interval;
}

void Animation::addAction(std::string name_action, int initial, int last){
  list_actions[name_action] = std::pair<int, int>(initial, last);
}
