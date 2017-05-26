#include "alien.hpp"

Alien::Alien(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 2, 10, 0.5);
    idleAnimationNumber = 0;
}

Alien::~Alien(){}

void Alien::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    auto incY = 0.15*timeElapsed;
    auto incX = 0.15*timeElapsed;

    walkInX(incX);
    walkInY(incY);

    if(incX == 0 && incY == 0){
        animator->setInterval(idleAnimationNumber, idleAnimationNumber);
    }
    specialAction();
    animator->update();
}

void Alien::walkInX(double & incX){

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        incX = incX;
        idleAnimationNumber = 5;
        animator->setInterval(6,9);
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        incX = incX * (0-1);
        idleAnimationNumber = 0;
        animator->setInterval(1,4);
    }
    else {
        incX = 0;
    }
    setPositionX(getPositionX()+incX);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        setPositionX(getPositionX()+(incX*(0-1)));
    }
}

void Alien::walkInY(double & incY){

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        incY = incY * (0-1);
        idleAnimationNumber = 0;
        animator->setInterval(1,4);
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        incY = incY;
        idleAnimationNumber = 5;
        animator->setInterval(6,9);
    }
    else {
        incY = 0;
    }
    setPositionY(getPositionY()+incY);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        setPositionY(getPositionY()+(incY*(0-1)));
    }
}

void Alien::specialAction(){
    if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
        if(idleAnimationNumber == 5){
            animator->setInterval(13,14);
        }else{
            animator->setInterval(11,12);
        }
    }
}

void Alien::draw(){
    INFO("ALIEN DRAW");
    animator->draw(getPositionX(), getPositionY());
}

Animation * Alien::getAnimation(){
  return animator;
}
