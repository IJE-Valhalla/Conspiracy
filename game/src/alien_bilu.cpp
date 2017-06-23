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
   editing = false;
   lastAction = false;
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

    GameObject* paper = CollisionManager::instance.verifyCollisionWithPapers(this);
    GameObject* doorSwitch = CollisionManager::instance.verifyCollisionWithSwitches(this);

    if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
        // Paper interaction
        if(paper != NULL){
            if(!editing){
                editing = true;
                blockMovement = true;
            }
        }

        // PC interaction
        if(doorSwitch != NULL){
            if(!hacking){
                hacking = true;
                blockMovement = true;
                ((DoorSwitch*)(doorSwitch))-> playEffect();
            }
        }

    }else if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_ESC)){
        if(hacking){
            hacking = false;
            blockMovement = false;
            ((DoorSwitch*)(doorSwitch))->stopEffect();
            ((DoorSwitch*)(doorSwitch))->stopAnimation();
            ((DoorSwitch*)(doorSwitch))->resetHackingProgress();
        }else if(editing){
            editing = false;
            blockMovement = false;
            //((Paper*)(paper))->stopEffect();
            ((Paper*)(paper))->stopAnimation();
            ((Paper*)(paper))->resetEditingProgress();
        }
    }

    if(hacking){
        ((DoorSwitch*)(doorSwitch))->animate();
        setSpecialActionAnimator();
        if(((DoorSwitch*)(doorSwitch))->getHackingBarPercent() <= 0.0){
            hacking = false;
            ((DoorSwitch*)(doorSwitch))->stopAnimation();
            ((DoorSwitch*)(doorSwitch))->stopEffect();
            ((DoorSwitch*)(doorSwitch))->resetHackingProgress();
            Alien::animator->setInterval("idle");
            blockMovement = false;
        }
    }else if(editing){
        ((Paper*)(paper))->animate();
        setSpecialActionAnimator();
        if(((Paper*)(paper))->getEditingBarPercent() <= 0.0){
            editing = false;
            ((Paper*)(paper))->stopAnimation();
            //((Paper*)(paper))->stopEffect();
            ((Paper*)(paper))->resetEditingProgress();
            Alien::animator->setInterval("idle");
            blockMovement = false;
        }
    }
    lastAction = hacking;
}

void Bilu::draw(){
    INFO("Bilu DRAW");
    animator->draw(getPositionX()-11, getPositionY()-20);
    //animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}

void Bilu::setSpecialActionAnimator(){
    if(idleAnimationNumber == 5){
        animator->setInterval("special_right");
    }else{
        animator->setInterval("special_left");
    }
    animator->setTotalTime(0.6);
}
