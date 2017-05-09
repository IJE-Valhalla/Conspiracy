#include "alien.hpp"

Alien::Alien(std::string objectName, int positionX, int positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 4, 9, 0.9);
}

Alien::~Alien(){}

void Alien::update(int timeElapsed){
    // To Do: Use Time Elapsed in inc.
    timeElapsed = timeElapsed;
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        auto inc = 2;
        setPositionX(getPositionX()+inc);
        animator->setInterval(27,35);
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        auto inc = 2;
        setPositionX(getPositionX()-inc);
        animator->setInterval(9,17);
    }

    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        auto inc = 2;
        setPositionY(getPositionY()-inc);
        animator->setInterval(0,8);
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        auto inc = 2;
        setPositionY(getPositionY()+inc);
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
