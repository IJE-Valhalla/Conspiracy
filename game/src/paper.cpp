#include "paper.hpp"

Paper::Paper(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 1, 4, 0.5);
    animator->addAction("idle",0,0);
    animator->addAction("beingEdited",1,3);
    edited = false;
    isBeingEdited = false;
}

Paper::~Paper(){}

void Paper::update(double timeElapsed){
    timeElapsed = timeElapsed;
    if(isBeingEdited){
        animator->setInterval("beingEdited");
        isBeingEdited = false;
    }else{
        animator->setInterval("idle");
    }
    animator->update();
}

void Paper::animate(){
    edited = true;
    isBeingEdited = true;
}

bool Paper::isEdited(){
    return edited;
}

void Paper::draw(){
    INFO("Paper DRAW");
    animator->draw(getPositionX(), getPositionY());
}

Animation * Paper::getAnimation(){
  return animator;
}
