#include "door.hpp"

Door::Door(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 1, 1, 0.5);
}

Door::~Door(){}

void Door::update(double timeElapsed){
    animator->update();
}

void Door::draw(){
    INFO("Door DRAW");
    if(isEnabled()){
        animator->draw(getPositionX(), getPositionY());
    }
}

Animation * Door::getAnimation(){
  return animator;
}
