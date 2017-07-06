#include "alien_varginha.hpp"

#define FILENAME "assets/sprites/varginha_sheet.png"
#define WIDTH 10
#define HEIGHT 15

Varginha::Varginha(double positionX, double positionY) : Alien(FILENAME, positionX, positionY, WIDTH, HEIGHT){

   animator->addAction("special_right",12,13);
   animator->addAction("special_left",10,11);
   animator->addAction("invisible_right", 13, 13);
   animator->addAction("invisible_left", 11, 11);
   isInvisible = false;
   isSelected = false;
   inPosition = false;
}

void Varginha::update(double timeElapsed){
    inPosition = false;
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

    if(CollisionManager::instance.verifyCollisionWithGuards(this)){
        setEnabled(false);
    }

    FinishPoint* finishPoint = (FinishPoint*)CollisionManager::instance.verifyCollisionWithFinishPoints(this);
    if(finishPoint != NULL){
        if(finishPoint->getAlienNames().find("V") != std::string::npos){
            inPosition = true;
        }
    }

    animator->update();
}

void Varginha::specialAction(){
    std::pair<int, int> interval;

    if(isInvisible){
        if(idleAnimationNumber == 5){
            animator->setInterval("invisible_right");
        }else{
            animator->setInterval("invisible_left");
        }
    }else if(isSelected){
            CameraSwitch* cameraSwitch = NULL;
            CameraLever* cameraLever = NULL;
            cameraSwitch = (CameraSwitch*)CollisionManager::instance.verifyCollisionWithCameraSwitches(this);
            cameraLever = (CameraLever*)CollisionManager::instance.verifyCollisionWithCameraLevers(this);

            if((cameraSwitch != NULL) || (cameraLever != NULL)){
                   if(InputManager::instance.isKeyTriggered(InputManager::KEY_PRESS_SPACE)){
                       if(cameraSwitch!= NULL){
                           cameraSwitch->turnOff();
                       }else if(cameraLever != NULL){
                           cameraLever->nextState();
                       }
                   }
           }else if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)){
               blockMovement = true;
               isInvisible = true;
               setVisible(false);
               if(idleAnimationNumber == 5){
                   animator->setInterval("special_right");
               }else{
                   animator->setInterval("special_left");
               }
           }
   }
   if(InputManager::instance.isKeyReleased(InputManager::KEY_PRESS_SPACE) && isSelected){
        setDefault();
   }
}

void Varginha::setDefault(){
    isInvisible = false;
    setVisible(true);
    blockMovement = false;
}

void Varginha::draw(){
    INFO("Varginha DRAW");
    animator->draw(getPositionX()-15, getPositionY()-25);
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}
