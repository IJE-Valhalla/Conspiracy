#include "paper.hpp"

Paper::Paper(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 1, 4, 0.5);
    editing_bar = new ProgressBar(positionX-7, positionY-5, 45, 5);
    animator->addAction("idle",0,0);
    animator->addAction("beingEdited",1,3);
    edited = false;
    isBeingEdited = false;
}

Paper::~Paper(){}

void Paper::update(double timeElapsed){
    timeElapsed = timeElapsed;
    if(isBeingEdited){
        editing_bar->update(timeElapsed);
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
    editing_bar->draw();
    std::cout << "HERE" <<std::endl;
}

void Paper::stopAnimation(){
    isBeingEdited = false;
}

bool Paper::isEdited(){
    return edited;
}

void Paper::draw(){
    INFO("Paper DRAW");
    animator->draw(getPositionX(), getPositionY());
    if(isBeingEdited){
        AnimationManager::instance.addProgressBar(editing_bar);
    }
}

Animation * Paper::getAnimation(){
  return animator;
}

double Paper::getEditingBarPercent(){
    return editing_bar->getPercent();
}

void Paper::resetEditingProgress(){
    editing_bar->resetPercent();
}
