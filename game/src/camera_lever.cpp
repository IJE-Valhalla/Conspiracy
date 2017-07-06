#include "camera_lever.hpp"

using namespace engine;

#define FILENAME "assets/sprites/exclamation2.png"
#define WIDTH 7
#define HEIGHT 7

CameraLever::CameraLever(double positionX, double positionY, std::string direction) : GameObject(FILENAME,positionX,positionY,
                                                                     WIDTH, HEIGHT){
    animator = new Animation(FILENAME, 2, 4, 0.1);
    animator->addAction("up", 0,0);
    animator->addAction("mid",1,1);
    animator->addAction("down", 2,2);
    animator->setInterval("mid");
    direction = direction;
    stateInc = 1;
    state = 1;
}

void CameraLever::draw(){
    animator->draw(getPositionX(), getPositionY());
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}

void CameraLever::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
}

int CameraLever::getState(){
    return state;
}

void CameraLever::nextState(){
    if(state >= 2 || state <= 0){
        stateInc *= -1;
    }
    state += stateInc;
    switch(state){
        case 0: animator->setInterval("up"); break;
        case 1: animator->setInterval("mid"); break;
        case 2: animator->setInterval("down"); break;
    }
}
