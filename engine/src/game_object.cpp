#include "game_object.hpp"
#include "log.h"

using namespace engine;
GameObject::GameObject(std::string objectName, int positionX, int positionY, int width, int height){
            setName(objectName);
            setPositionX(positionX);
            setPositionY(positionY);
            setWidth(width);
            setHeight(height);
        }

std::string GameObject::getName(){
    return name;
}

int GameObject::getPositionX(){
    return position.first;
}

int GameObject::getPositionY(){
    return position.second;
}

int GameObject::getWidth(){
    return size.first;
}

int GameObject::getHeight(){
    return size.second;
}

void GameObject::setName(std::string newName){
    name = newName;
}

void GameObject::setPositionX(int newX){
    position.first = newX;
}

void GameObject::setPositionY(int newY){
    position.second = newY;
}

void GameObject::setWidth(int newWidth){
    size.first = newWidth;
}

void GameObject::setHeight(int newHeight){
    size.second = newHeight;
}
