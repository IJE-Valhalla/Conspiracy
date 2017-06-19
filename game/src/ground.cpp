#include "ground.hpp"
#include "log.h"

Ground::Ground(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
animator = new Animation(objectName, 1, 1, 0.5);
}

Ground::~Ground(){}
void Ground::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
}

void Ground::draw(){
    animator->draw_instant(getPositionX(), getPositionY());
}
