#include "alien_etemer.hpp"
#include "chair.hpp"
#include "guard.hpp"

#define FILENAME "assets/sprites/etemer_sheet.png"
#define WIDTH 10
#define HEIGHT 22

Etemer::Etemer(double positionX, double positionY) : Alien(FILENAME, positionX, positionY, WIDTH, HEIGHT){
        animator->addAction("special_right",14,17);
        animator->addAction("special_left",10,13);

        isSelected = true;
        talking = false;
        inPosition = false;
}

void Etemer::update(double timeElapsed){
        inPosition = false;
        if (blockMovement) {
                animator->setTotalTime(1.0);
        }else{
                animator->setTotalTime(0.3);
        }

        auto incY = 0.15*timeElapsed;
        auto incX = 0.15*timeElapsed;

        if(!blockMovement && isSelected) {
                walkInX(incX);
                walkInY(incY, incX);
        }

        if(incX == 0.0 && incY == 0.0 && !blockMovement) {
                if(idleAnimationNumber) {
                        animator->setInterval("idle_right");
                }else{
                        animator->setInterval("idle_left");
                }
        }

        FinishPoint* finishPoint = (FinishPoint*)CollisionManager::instance.verifyCollisionWithFinishPoints(this);
        if(finishPoint != NULL){
            if(finishPoint->getAlienNames().find("E") != std::string::npos){
                inPosition = true;
            }
        }

        moveChair();

        if(CollisionManager::instance.verifyCollisionWithCameras(this)) {
            setEnabled(false);
        }
        animator->update();
}
void Etemer::specialAction(GameObject * guard, double distance){
        if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE) && guard != NULL && isSelected) {
                animator->setTotalTime(1.0);
                //TODO Change distance.
                if(!talking && distance < 60) {
                        talking = true;
                        blockMovement = true;
                        if(((Guard *) (guard))->getPositionX() > getPositionX()) {
                                ((Guard *)(guard))->talkingToETemer("left");
                        }else{
                                ((Guard *)(guard))->talkingToETemer("right");
                        }
                }

        }

        if(talking) {
                if(((Guard *) (guard))->getPositionX() >= getPositionX()) {
                        animator->setInterval("special_right");
                        idleAnimationNumber = 5;
                }else{
                        animator->setInterval("special_left");
                        idleAnimationNumber = 0;
                }
                if(((Guard *) (guard))->getTalkingBarPercent() <= 0.0) {
                        talking = false;
                        blockMovement = false;
                        if(idleAnimationNumber) {
                                animator->setInterval("idle_right");
                        }else{
                                animator->setInterval("idle_left");
                        }
                }
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
                if(animator->getInterval().first == chair.first) {
                        ((Chair *) (chair.second))->setMoving(true);
                        ((Chair *) (chair.second))->setDirection(chair.first);
                }else{
                        ((Chair *) (chair.second))->setMoving(false);
                }
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

void Etemer::verifyDistance(GameObject* guard){
        double distance = sqrt((pow(getPositionX() - guard->getPositionX(), 2.0)) +  (pow(getPositionY() - guard->getPositionY(), 2.0)));

        if(distance < 60){
            specialAction(guard, distance);
        }
}
