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
   hacking = false;
   lastAction = false;
}

void Bilu::specialAction(){
    std::pair<int, int> interval;

    GameObject* paper = CollisionManager::instance.verifyCollisionWithPapers(this);
    GameObject* doorSwitch = CollisionManager::instance.verifyCollisionWithSwitches(this);

    if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
        // Paper interaction
        if(paper != NULL){
            ((Paper*)paper)->animate();
        }

        // PC interaction
        if(doorSwitch != NULL){
            hacking = true;
        }

    }else if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_ESC)){
        hacking = false;
    }else{
        blockMovement = false;
    }

    if(doorSwitch != NULL){
        if(hacking){
            blockMovement = true;
            ((DoorSwitch*)(doorSwitch))->animate();

            if(idleAnimationNumber == 5){
                animator->setInterval("special_right");
            }else{
                animator->setInterval("special_left");
            }
            animator->setTotalTime(0.6);

            if(!lastAction){
                ((DoorSwitch*)(doorSwitch))->playEffect();
            }
        }else{
            blockMovement = false;
            ((DoorSwitch*)(doorSwitch))->stopAnimation();
            if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_ESC)){
                ((DoorSwitch*)(doorSwitch))->stopEffect();
            }
        }
    }
    lastAction = hacking;
}

void Bilu::draw(){
    INFO("Bilu DRAW");
    animator->draw(getPositionX()-11, getPositionY()-20);
    //animator->draw(getPositionX(), getPositionY());
}
