#include "alien.hpp"

Alien::Alien(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    if(objectName.compare("assets/sprites/bilu_sheet.png") == 0){
        alienName = "Bilu";
    }else if(objectName.compare("assets/sprites/varginha_sheet.png") == 0){
        alienName = "Varginha";
    }else if(objectName.compare("assets/sprites/etemer_sheet.png") == 0){
        alienName = "Etemer";
    }
    animator = new Animation(objectName, 2, 10, 0.5);

    animator->addAction("right",6,9);
    animator->addAction("left",1,4);
    animator->addAction("up",6,9);
    animator->addAction("down",1,4);
    animator->addAction("idle_right",5,5);
    animator->addAction("idle_left",0,0);
    animator->addAction("idle_up",5,5);
    animator->addAction("idle_down",0,0);

    idleAnimationNumber = 5;
    blockMovement = false;
    inPosition = false;
    movement_sound_effect = new Audio("assets/sounds/FOOTSTEP.wav", "EFFECT", 128);
}

Alien::~Alien(){}

void Alien::walkInX(double & incX){

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        incX = incX;
        idleAnimationNumber = 5;
        animator->setInterval("right");
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        //movement_sound_effect->play(-1);
        incX = incX * (0-1);
        idleAnimationNumber = 0;
        animator->setInterval("left");
    }
    else {
        incX = 0;
    }
    setPositionX(getPositionX()+incX);
    if(CollisionManager::instance.verifyCollisionWithWallsAndChairs(this)){
        setPositionX(getPositionX()+(incX*(0-1)));
    }
}

void Alien::walkInY(double & incY, double incX){

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        incY = incY * (0-1);
        idleAnimationNumber = 5;
        if(incX == 0){
            animator->setInterval("up");
        }
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        incY = incY;
        idleAnimationNumber = 0;
        if(incX == 0){
            animator->setInterval("down");
        }
    }
    else {
        incY = 0;
    }
    setPositionY(getPositionY()+incY);
    if(CollisionManager::instance.verifyCollisionWithWallsAndChairs(this)){
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

void Alien::setAlienSelected(){
    isSelected = true;
}

void Alien::setAlienDeselect(){
    isSelected = false;
}

bool Alien::isInPosition(){
    return inPosition;
}
