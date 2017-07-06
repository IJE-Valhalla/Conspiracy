#include "collision_manager.hpp"
#include "chair.hpp"
#include "log.h"

Chair::Chair(std::string objectName, double positionX, double positionY,
             int width, int height) : GameObject(objectName,
                                                 positionX,
                                                 positionY,
                                                 width, height){
        chairEffect = new Audio("assets/sounds/DRAG.wav", "EFFECT", 128);
        animator = new Animation(objectName, 1, 4, 0.5);
        animator->addAction("move",0,3);
        animator->addAction("idle",0,0);
        animator->setInterval("idle");
        isMoving = false;
}

Chair::~Chair(){

}

void Chair::update(double timeElapsed){
        auto incX = 0.15*timeElapsed;
        auto incY = 0.15*timeElapsed;

        if(isMoving) {
                moveInX(incX);
                moveInY(incY);
        }else{
          animator->setInterval("idle");
        }

        animator->update();
        setMoving(false);
}

void Chair::draw(){
        animator->draw(getPositionX(), getPositionY()-15);
        animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}

void Chair::moveInX(double incX){

        if(direction == "right") {
                incX = incX;
                animator->setInterval("move");
        }
        else if(direction == "left") {
                incX = incX * (0-1);
                animator->setInterval("move");
        }
        else {
                incX = 0;
        }
        setPositionX(getPositionX()+incX);
        if(CollisionManager::instance.verifyCollisionWithOtherChairs(this) || CollisionManager::instance.verifyCollisionWithWalls(this) || CollisionManager::instance.verifyCollisionWithGuardsBody(this)) {
                setPositionX(getPositionX()+(incX*(0-1)));
        }

}

void Chair::moveInY(double incY){

        if(direction == "down") {
                incY = incY;
                animator->setInterval("move");
        }
        else if(direction == "up") {
                incY = incY * (0-1);
                animator->setInterval("move");
        }
        else {
                incY = 0;
        }
        setPositionY(getPositionY()+incY);
        if(CollisionManager::instance.verifyCollisionWithOtherChairs(this) || CollisionManager::instance.verifyCollisionWithWalls(this) || CollisionManager::instance.verifyCollisionWithGuardsBody(this)) {
                setPositionY(getPositionY()+(incY*(0-1)));
        }

}

void Chair::setMoving(bool move){
        isMoving = move;
}

void Chair::setDirection(std::string currentDirection){
        direction = currentDirection;
}
