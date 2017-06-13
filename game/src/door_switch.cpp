#include "door_switch.hpp"

DoorSwitch::DoorSwitch(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 1, 6, 0.5);
    hacking_effect = new Audio("assets/sounds/PCNOISE.wav", "EFFECT", 128);
    animator->addAction("beingHacked", 1,5);
    animator->addAction("idle", 0, 0);
    pressed = false;
}

DoorSwitch::~DoorSwitch(){}

void DoorSwitch::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
}

void DoorSwitch::draw(){
    INFO("DoorSwitch DRAW");
    if(isPressed()){
        // pressed = false;
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

void DoorSwitch::stopAnimation(){
    pressed = false;
    setEnabled(true);
}

bool DoorSwitch::isPressed(){
    return pressed;
}

void DoorSwitch::playEffect(){
    hacking_effect->play(2);
}

void DoorSwitch::stopEffect(){
    hacking_effect->stop();
}
