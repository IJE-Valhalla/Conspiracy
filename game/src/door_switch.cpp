#include "door_switch.hpp"

DoorSwitch::DoorSwitch(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 1, 6, 1.5);
    animator->addAction("beingHacked", 1,5);
    animator->addAction("idle", 0, 0);
}

DoorSwitch::~DoorSwitch(){}

void DoorSwitch::update(double timeElapsed){
    animator->update();
}

void DoorSwitch::draw(){
    INFO("DoorSwitch DRAW");
    if(isPressed()){
        pressed = false;
        animator->setInterval("beingHacked");
    }else{
        animator->setInterval("idle");
    }
    animator->draw(getPositionX(), getPositionY());
}

Animation * DoorSwitch::getAnimation(){
  return animator;
}

void DoorSwitch::animate(){
    pressed = true;
    setEnabled(false);
}

bool DoorSwitch::isPressed(){
    return pressed;
}
