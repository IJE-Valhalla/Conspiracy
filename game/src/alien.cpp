#include "alien.hpp"
#include "input_manager.hpp"

Alien::Alien(std::string objectName, int positionX, int positionY, int width, int height){
    setName(objectName);
    setPositionX(positionX);
    setPositionY(positionY);
    setWidth(width);
    setHeight(height);
    animator = new Animation("assets/sprites/bomberman2.png", 4, 9, 0.9);
}

Alien::~Alien(){

}

void Alien::init(){
    animator->init();
}

void Alien::update(int timeElapsed){
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        auto inc = 1 * timeElapsed;
        setPositionX(getPositionX()+inc);
        animator->setInterval(27,35);
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        auto inc = 1* timeElapsed;
        setPositionX(getPositionX()-inc);
        animator->setInterval(9,17);
    }

    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        auto inc = 1 * timeElapsed;
        setPositionY(getPositionY()-inc);
        animator->setInterval(0,8);
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_DOWN)){
        auto inc = 1 * timeElapsed;
        setPositionY(getPositionY()+inc);
        animator->setInterval(18,26);
    }
    else {
        std::pair <int, int> interval = animator->getInterval();
        animator->setInterval(interval.first,interval.first);
    }

    animator->update();
}

void Alien::draw(){
    animator->draw(GameObject::getPositionX(), getPositionY());
}
