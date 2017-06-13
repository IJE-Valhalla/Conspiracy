#include "alien_varginha.hpp"

Varginha::Varginha(std::string objectName, double positionX, double positionY,
                                   int width, int height) : Alien(objectName,
                                                                       positionX,
                                                                       positionY,
                                                                       width, height){
   animator->addAction("special_right",12,13);
   animator->addAction("special_left",10,11);
   animator->addAction("invisible_right", 13, 13);
   animator->addAction("invisible_left", 11, 11);
   isInvisible = false;
   isSelected = false;
}

void Varginha::specialAction(){
    std::pair<int, int> interval;

    if(isInvisible){
        if(idleAnimationNumber == 5){
            animator->setInterval("invisible_right");
        }else{
            animator->setInterval("invisible_left");
        }
    }else if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
        blockMovement = true;
        isInvisible = true;
        if(idleAnimationNumber == 5){
            animator->setInterval("special_right");
        }else{
            animator->setInterval("special_left");
        }
    }
    if(InputManager::instance.isKeyReleased(InputManager::KEY_PRESS_SPACE)){
        isInvisible = false;
        blockMovement = false;
    }
}
