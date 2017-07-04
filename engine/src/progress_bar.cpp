#include "progress_bar.hpp"

using namespace engine;

ProgressBar::ProgressBar(double positionX, double positionY, int width,
                                                             int height,
                                                             double increment):
                                                                      GameObject(
                                                                          positionX,
                                                                          positionY,
                                                                          width,
                                                                          height){
    percent = 1.0;
    progressIncrement = increment;

    backRect = new SDL_Rect();
    backRect->x = positionX;
    backRect->y = positionY;
    backRect->w =  width;
    backRect->h =  height;

    frontRect = new SDL_Rect();
    frontRect->x = positionX;
    frontRect->y = positionY;
    frontRect->w =  width;
    frontRect->h =  height;

    //backColor = {0, 255, 0, 255};
    backColor = {31, 65, 158, 1};
    frontColor = {161, 181, 236, 50};
    SDL_GetRenderDrawColor(WindowManager::getGameCanvas(),
                                 &oldColor.r, &oldColor.g,
                                 &oldColor.g, &oldColor.a);
}

ProgressBar::~ProgressBar(){}

void ProgressBar::update(double timeElapsed){
    timeElapsed = timeElapsed;
    if(percent > 1.0){
        percent = 1.0;
    }else if(percent < 0.0){
        percent = 0.0;
    }

    backRect->x = getPositionX();
    backRect->y = getPositionY();

    pw = (int)((double)getWidth() * percent);
    px = getPositionX() + (getWidth() - pw);

    frontRect->x = px;
    frontRect->y = getPositionY();
    frontRect->w = pw;
    frontRect->h = getHeight();
    percent -= progressIncrement;
}

void ProgressBar::draw(){
    //std::cout << "LIXO" << std::endl;
    SDL_SetRenderDrawColor(WindowManager::getGameCanvas(), backColor.r,
                                                           backColor.g,
                                                           backColor.b,
                                                           backColor.a);

    SDL_RenderFillRect(WindowManager::getGameCanvas(), backRect);

    SDL_SetRenderDrawColor(WindowManager::getGameCanvas(),
                               frontColor.r, frontColor.g,
                               frontColor.b, frontColor.a);

    SDL_RenderFillRect(WindowManager::getGameCanvas(), frontRect);

    SDL_SetRenderDrawColor(WindowManager::getGameCanvas(), oldColor.r,
                                                           oldColor.g,
                                                           oldColor.b,
                                                           oldColor.a);
}

double ProgressBar::getPercent(){
    return percent;
}

void ProgressBar::resetPercent(){
    percent = 1.0;
}
