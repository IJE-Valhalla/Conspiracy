#include "guard.hpp"

Guard::Guard(std::string objectName, double positionX, double positionY,
                                     int width, int height) : Enemy(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 1, 10, 0.5);

    animator->addAction("right",6,9);
    animator->addAction("left",1,4);
    animator->addAction("up",6,9);
    animator->addAction("down",1,4);
    animator->addAction("idle_right",5,5);
    animator->addAction("idle_left",0,0);
    animator->addAction("idle_up",5,5);
    animator->addAction("idle_down",0,0);

    idleAnimationNumber = 0;
}

Guard::~Guard(){}

void Guard::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    auto incY = 0.15*timeElapsed;
    auto incX = 0.15*timeElapsed;

    walkInX(incX);
    walkInY(incY);

    if(incX == 0 && incY == 0){
        if(idleAnimationNumber){
          animator->setInterval("idle_right");
        }else{
          animator->setInterval("idle_left");
        }
    }

    specialAction();
    animator->update();
}

void Guard::walkInX(double & incX){

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        incX = incX;
        idleAnimationNumber = 5;
        animator->setInterval("right");
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        incX = incX * (0-1);
        idleAnimationNumber = 0;
        animator->setInterval("left");
    }
    else {
        incX = 0;
    }
    setPositionX(getPositionX()+incX);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        setPositionX(getPositionX()+(incX*(0-1)));
    }
}

void Guard::walkInY(double & incY){

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        incY = incY * (0-1);
        idleAnimationNumber = 5;
        animator->setInterval("up");
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        incY = incY;
        idleAnimationNumber = 0;
        animator->setInterval("down");
    }
    else {
        incY = 0;
    }
    setPositionY(getPositionY()+incY);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        setPositionY(getPositionY()+(incY*(0-1)));
    }
}

void Guard::specialAction(){
    if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
        if(idleAnimationNumber == 5){
        }else{
        }
    }
}

void Guard::draw(){
    animator->draw(getPositionX(), getPositionY());
}
