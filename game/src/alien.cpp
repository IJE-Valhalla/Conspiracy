#include "alien.hpp"

Alien::Alien(std::string objectName, int positionX, int positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation("assets/sprites/bomberman2.png", 4, 9, 1.0);
}

Alien::~Alien(){}

void Alien::update(int timeElapsed){
    if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_RIGHT)){
        auto inc = 1*timeElapsed;
        setPositionX(getPositionX()+inc);
        animator->setInterval(27,35);
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_LEFT)){
        auto inc = 1*timeElapsed;
        setPositionX(getPositionX()-inc);
        animator->setInterval(9,17);
    }

    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_UP)){
        auto inc = 1*timeElapsed;
        setPositionY(getPositionY()-inc);
        animator->setInterval(0,8);
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        auto inc = 1*timeElapsed;
        setPositionY(getPositionY()+inc);
        animator->setInterval(18,26);
    }
    else {
        animator->setInterval(18, 26);
    }

    animator->update();
}

void Alien::draw(){
    animator->draw(getPositionX(), getPositionY());
}
