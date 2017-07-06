#include "header.hpp"
#include "log.h"

#define FILENAME "assets/sprites/selecao_personagens_sheet(68X20).png"
#define WIDTH 68
#define HEIGHT 20

Header::Header(double positionX, double positionY) : GameObject(FILENAME, positionX, positionY, WIDTH, HEIGHT){
        animator = new Animation(FILENAME, 1, 4, 0.5);

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
