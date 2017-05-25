#include "alien.hpp"

Alien::Alien(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 1, 4, 0.5);
}

Alien::~Alien(){}

void Alien::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    auto incY = 0.15*timeElapsed;
    auto incX = 0.15*timeElapsed;

    walkInX(incX);
    walkInY(incY);

    if(incX == 0 && incY == 0){
        animator->setInterval(animator->getInterval().first, animator->getInterval().first);
    }
    animator->update();
}

void Alien::walkInX(double & incX){

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        incX = incX;
        animator->setInterval(0,3);
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        incX = incX * (0-1);
        animator->setInterval(0,3);
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
        animator->setInterval(0,3);
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        incY = incY;
        animator->setInterval(0,3);
    }
    else {
        incY = 0;
    }


    setPositionY(getPositionY()+incY);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        setPositionY(getPositionY()+(incY*(0-1)));
    }
}

void Alien::draw(){
    INFO("ALIEN DRAW");
    animator->draw(getPositionX(), getPositionY());
}

Animation * Alien::getAnimation(){
  return animator;
}
