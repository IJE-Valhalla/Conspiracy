#include "alien_etemer.hpp"
#include "chair.hpp"

Etemer::Etemer(std::string objectName, double positionX, double positionY,
                                   int width, int height) : Alien(objectName,
                                                                       positionX,
                                                                       positionY,
                                                                       width, height){
    animator->addAction("special_right",14,17);
    animator->addAction("special_left",10,13);

    isSelected = false;
}

void Etemer::update(double timeElapsed){
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
    moveChair();

    animator->update();
}
void Etemer::specialAction(){
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

void Etemer::draw(){
    INFO("Etemer DRAW");
    animator->draw(getPositionX()-15, getPositionY()-20);
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}

void Etemer::moveChair(){
        std::pair<std::string, GameObject *> chair = CollisionManager::instance.verifyCollisionWithChairs(this);
        if(chair.second != NULL) {
                ((Chair *) (chair.second))->setMoving(true);
                ((Chair *) (chair.second))->setDirection(chair.first);
        }
}
