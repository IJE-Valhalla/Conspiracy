#include "alien_varginha.hpp"

Varginha::Varginha(std::string objectName, double positionX, double positionY,
                                   int width, int height) : Alien(objectName,
                                                                       positionX,
                                                                       positionY,
                                                                       width, height){
    isInvisible = false;
}

void Varginha::specialAction(){
    std::pair<int, int> interval;

    if(isInvisible){
        if(idleAnimationNumber == 5){
            animator->setInterval(13, 13);
        }else{
            animator->setInterval(11, 11);
        }
    }else if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
        blockMovement = true;
        isInvisible = true;
        if(idleAnimationNumber == 5){
            interval.first = 12;
            interval.second = 13;
        }else{
            interval.first = 10;
            interval.second = 11;
        }
    }
    if(InputManager::instance.isKeyReleased(InputManager::KEY_PRESS_SPACE)){
        isInvisible = false;
        blockMovement = false;
    }
}
