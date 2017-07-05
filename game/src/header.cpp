#include "header.hpp"
#include "log.h"

Header::Header(std::string objectName, double positionX, double positionY,
                         int width, int height) : GameObject(objectName,
                                                             positionX,
                                                             positionY,
                                                             width, height){
        animator = new Animation(objectName, 1, 4, 0.5);

        animator->addAction("none", 0,0);
        animator->addAction("Etemer", 1,1);
        animator->addAction("Etbilu", 2,2);
        animator->addAction("Etvarginha", 3,3);

        alienSelect = 1;
}

Header::~Header(){
}
void Header::update(double timeElapsed){
        timeElapsed = timeElapsed;
        verifySelect();
        animator->update();
}

void Header::draw(){
        animator->draw(getPositionX()+5, getPositionY()+5);
}

void Header::verifySelect(){
        switch(alienSelect) {
        case 0:
                animator->setInterval("none");
                break;
        case 1:
                animator->setInterval("Etemer");
                break;
        case 2:
                animator->setInterval("Etbilu");
                break;
        case 3:
                animator->setInterval("Etvarginha");
                break;
        default:
                // Nothing to do.
                break;
        }
}

void Header::setAlienSelect(int select){
        alienSelect = select;
}
