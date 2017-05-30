#include "alien_bilu.hpp"

Bilu::Bilu(std::string objectName, double positionX, double positionY,
                                   int width, int height) : Alien(objectName,
                                                                       positionX,
                                                                       positionY,
                                                                       width, height){
}

void Bilu::specialAction(){
    std::pair<int, int> interval;

    if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
        blockMovement = true;
        if(idleAnimationNumber == 5){
            interval.first = 14;
            interval.second = 17;
        }else{
            interval.first = 10;
            interval.second = 13;
        }
        animator->setInterval(interval.first,interval.second);
    }else{
        blockMovement = false;
    }
}
