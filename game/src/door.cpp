#include "door.hpp"

Door::Door(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 1, 4, 0.5);
    animator->addAction("closed", 0,0);
    animator->addAction("open",1,3);
    animator->setDrawSize(width,height);
    open = false;
}

Door::~Door(){}

void Door::update(double timeElapsed){
    timeElapsed = timeElapsed;
    if(animator->getCurrentPositionFrame()!=3){
        animator->update();
    }
    if(isOpen()){
        animator->setInterval("open");
    }else{
        animator->setInterval("closed");
    }
}

void Door::draw(){
    INFO("Door DRAW");
    animator->draw(getPositionX(), getPositionY());
}

Animation * Door::getAnimation(){
  return animator;
}

bool Door::isOpen(){
        return open;
}

void Door::setOpen(bool status){
        open = status;
}
