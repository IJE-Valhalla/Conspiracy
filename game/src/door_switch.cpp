#include "door_switch.hpp"

DoorSwitch::DoorSwitch(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 1, 6, 0.5);

    hacking_effect = new Audio("assets/sounds/PCNOISE.wav", "EFFECT", 60);
    hacking_bar = new ProgressBar(positionX-7, positionY-10, 45, 5, 0.002);

    animator->addAction("beingHacked", 1,5);
    animator->addAction("idle", 0, 0);
    pressed = false;
}

DoorSwitch::~DoorSwitch(){}

void DoorSwitch::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
    if(isPressed()){
        hacking_bar->update(timeElapsed);
    }
}

void DoorSwitch::draw(){
    INFO("DoorSwitch DRAW");
    if(isPressed()){
        animator->setInterval("beingHacked");
        AnimationManager::instance.addProgressBar(hacking_bar);
        if(hacking_bar->getPercent() <= 0.0){
            pressed = false;
            setEnabled(false);
        }
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
}

void DoorSwitch::stopAnimation(){
    pressed = false;
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

double DoorSwitch::getHackingBarPercent(){
    return hacking_bar->getPercent();
}

void DoorSwitch::resetHackingProgress(){
    hacking_bar->resetPercent();
}
