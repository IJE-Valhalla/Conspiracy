#include "alien.hpp"

Alien::Alien(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 4, 9, 1.0);
}

Alien::~Alien(){}

void Alien::update(int timeElapsed){
    // To Do: Use Time Elapsed in inc.
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        auto inc = 0.15*timeElapsed;
        setPositionX(getPositionX()+inc);
        animator->setInterval(27,35);
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        auto inc = 0.15*timeElapsed;
        setPositionX(getPositionX()-inc);
        animator->setInterval(9,17);
    }

    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        auto inc = 0.15*timeElapsed;
        WARN("INCREMENTO//:" << inc <<"POSITION" << getPositionY());
        setPositionY(getPositionY()-inc);
        WARN("INCREMENTO//:" << inc <<"POSITION" << getPositionY());
        animator->setInterval(0,8);
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        auto inc = 0.15*timeElapsed;
        WARN("INCREMENTO//:" << inc <<"POSITION" << getPositionY());
        setPositionY(getPositionY()+inc);
        WARN("INCREMENTO//:" << inc <<"POSITION" << getPositionY());
        animator->setInterval(18,26);
    }
    else {
        animator->setInterval(animator->getInterval().first, animator->getInterval().first);
    }

    animator->update();
}

void Alien::draw(){
    INFO("ALIEN DRAW");
    animator->draw(getPositionX(), getPositionY());
}

Animation * Alien::getAnimation(){
  return animator;
}
