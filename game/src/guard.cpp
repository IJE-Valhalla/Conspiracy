#include "guard.hpp"

Guard::Guard(std::string objectName, double positionX, double positionY,
                                     int width, int height, std::string initialDirection) : Enemy(objectName,
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
    direction = initialDirection;
}

Guard::~Guard(){}

void Guard::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    auto incY = 0.1*timeElapsed;
    auto incX = 0.1*timeElapsed;

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

    if(direction == "right"){
        incX = incX * (1);
        idleAnimationNumber = 5;
        animator->setInterval(direction);
    }else if(direction == "left"){
        incX = incX * (-1);
        idleAnimationNumber = 0;
        animator->setInterval(direction);
    }else {
        incX = 0;
    }
    setPositionX(getPositionX()+incX);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        if(direction == "left"){
          direction = "right";
        }else{
          direction = "left";
        }
        setPositionX(getPositionX()+(incX*(0-1)));
    }
}

void Guard::walkInY(double & incY){

  if(direction == "down"){
      incY = incY * (1);
      idleAnimationNumber = 5;
      animator->setInterval(direction);
  }else if(direction == "up"){
      incY = incY * (-1);
      idleAnimationNumber = 0;
      animator->setInterval(direction);
  }else {
      incY = 0;
  }
  setPositionY(getPositionY()+incY);
  if(CollisionManager::instance.verifyCollisionWithWalls(this)){
      if(direction == "down"){
        direction = "up";
      }else{
        direction = "down";
      }
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
