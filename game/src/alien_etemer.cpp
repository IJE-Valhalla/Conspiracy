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

        if(!blockMovement && isSelected) {
                walkInX(incX);
                walkInY(incY, incX);
        }

        if(incX == 0 && incY == 0) {
                if(idleAnimationNumber) {
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

        if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)) {
                blockMovement = true;
                if(idleAnimationNumber == 5) {
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


void Etemer::walkInX(double & incX){

        if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)) {
                incX = incX;
                idleAnimationNumber = 5;
                animator->setInterval("right");
        }
        else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)) {
                //movement_sound_effect->play(-1);
                incX = incX * (0-1);
                idleAnimationNumber = 0;
                animator->setInterval("left");
        }
        else {
                incX = 0;
        }
        setPositionX(getPositionX()+incX);

        if(CollisionManager::instance.verifyCollisionWithWallsAndChairs(this)) {
                setPositionX(getPositionX()+(incX*(0-1)));
        }
}

void Etemer::walkInY(double & incY, double incX){

        if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)) {
                incY = incY * (0-1);
                idleAnimationNumber = 5;
                if(incX == 0) {
                        animator->setInterval("up");
                }
        }
        else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)) {
                incY = incY;
                idleAnimationNumber = 0;
                if(incX == 0) {
                        animator->setInterval("down");
                }
        }
        else {
                incY = 0;
        }
        setPositionY(getPositionY()+incY);

        if(CollisionManager::instance.verifyCollisionWithWallsAndChairs(this)) {
                setPositionY(getPositionY()+(incY*(0-1)));
        }
}
