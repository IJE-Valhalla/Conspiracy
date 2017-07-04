#include "arrow.hpp"
#include "log.h"

Arrow::Arrow(std::string objectName, double positionX, double positionY,
             int width, int height) : GameObject(objectName,
                                                 positionX,
                                                 positionY,
                                                 width, height){
        animator = new Animation(objectName, 1, 17, 2.0);
        animator->addAction("select",0,16);
        animator->setInterval("select");
}

Arrow::~Arrow(){

}

void Arrow::update(double timeElapsed){
        timeElapsed = timeElapsed;
        if(isEnabled()){
                animator->update();
        }
}

void Arrow::draw(){
        if(isEnabled()) {
                animator->draw(getPositionX(), getPositionY());
        }
}
