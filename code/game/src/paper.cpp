#include "paper.hpp"

Paper::Paper(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 1, 4, 0.5);

    std::vector<unsigned int> backColor = {22, 206, 26, 1};
    std::vector<unsigned int> frontColor = {116, 225, 117, 1};
    editing_bar = new ProgressBar(positionX-3, positionY-8, 22.5, 5, 0.005, backColor, frontColor);

    paperEditingSound = new Audio("assets/sounds/PAPEROISE.wav", "EFFECT", 100);

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
        if(editing_bar->getPercent() <= 0.0){
            isBeingEdited = false;
            edited = true;
        }
    }else{
        animator->setInterval("idle");
    }
    animator->update();
}

void Paper::animate(){
    isBeingEdited = true;
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
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
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

void Paper::playEffect(){
    paperEditingSound->play(0);
}

void Paper::stopEffect(){
    paperEditingSound->stop();
}
