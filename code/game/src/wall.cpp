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
    if(getName().compare("assets/sprites/cenary/parede2.png") == 0){
        animator->draw(getPositionX(), getPositionY()-25);
    }else{
        animator->draw(getPositionX(), getPositionY());
    }
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}
