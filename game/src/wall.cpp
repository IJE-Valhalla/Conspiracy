#include "wall.hpp"
#include "log.h"

Wall::Wall(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
animator = new Animation(objectName, 1, 1, 0.5);
}

Wall::~Wall(){}
void Wall::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
}

void Wall::draw(){
    animator->draw(getPositionX(), getPositionY());
}
