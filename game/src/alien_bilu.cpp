#include "alien_bilu.hpp"
#include "collision_manager.hpp"
#include "paper.hpp"
#include "door_switch.hpp"

Bilu::Bilu(std::string objectName, double positionX, double positionY,
                                   int width, int height) : Alien(objectName,
                                                                       positionX,
                                                                       positionY,
                                                                       width, height){
   animator->addAction("special_right",14,17);
   animator->addAction("special_left",10,13);

   isSelected = true;
}

void Bilu::update(double timeElapsed){
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

void Bilu::specialAction(){
    std::pair<int, int> interval;

    if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
        blockMovement = true;
        GameObject* paper = CollisionManager::instance.verifyCollisionWithPapers(this);
        if(paper != NULL){
            ((Paper*)paper)->animate();
        }
        GameObject* doorSwitch = CollisionManager::instance.verifyCollisionWithSwitches(this);
        if(doorSwitch != NULL){
            ((DoorSwitch*)(doorSwitch))->animate();
        }
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

void Bilu::draw(){
    INFO("Bilu DRAW");
    animator->draw(getPositionX()-11, getPositionY()-20);
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}
