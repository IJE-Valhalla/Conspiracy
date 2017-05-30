#include "alien_bilu.hpp"

Bilu::Bilu(std::string objectName, double positionX, double positionY,
                                   int width, int height) : Alien(objectName,
                                                                       positionX,
                                                                       positionY,
                                                                       width, height){
   animator->addAction("special_right",14,17);
   animator->addAction("special_left",10,13);
}

void Bilu::specialAction(){
    std::pair<int, int> interval;

    if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
        blockMovement = true;
        if(idleAnimationNumber == 5){
            animator->setInterval("special_right");
        }else{
            animator->setInterval("special_left");
        }
        animator->setTotalTime(1.5);
    }else{
        blockMovement = false;
    }
}
