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

void Varginha::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    animator->setTotalTime(0.3);
    auto incY = 0.15*timeElapsed;
    auto incX = 0.15*timeElapsed;

    if(!blockMovement && isSelected){
        walkInX(incX);
        walkInY(incY, incX);
    }

    if(incX == 0 && incY == 0){
        if(idleAnimationNumber){
          animator->setInterval("idle_right");
        }else{
          animator->setInterval("idle_left");
        }
    }
    specialAction();

    if(CollisionManager::instance.verifyCollisionWithEnemies(this)){
        setEnabled(false);
    }

    animator->update();
}

void Varginha::specialAction(){
    std::pair<int, int> interval;

    if(isInvisible){
        if(idleAnimationNumber == 5){
            animator->setInterval("invisible_right");
        }else{
            animator->setInterval("invisible_left");
        }
    }else if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE) && isSelected){
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


void Varginha::draw(){
    INFO("Varginha DRAW");
    animator->draw(getPositionX()-15, getPositionY()-25);
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}
