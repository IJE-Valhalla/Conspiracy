#include "game_object.hpp"
#include "log.h"

using namespace engine;

GameObject::GameObject(std::string objectName, double positionX, double positionY,
                                               int width, int height){
        setName(objectName);
        setPositionX(positionX);
        setPositionY(positionY);
        setWidth(width);
        setHeight(height);
        setEnabled(true);
}

GameObject::GameObject(){}

GameObject::~GameObject(){}

//void GameObject::update(double timeElapsed){}

std::string GameObject::getName(){
    return name;
}

double GameObject::getPositionX(){
    return position.first;
}

double GameObject::getPositionY(){
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

void GameObject::setPositionX(double newX){
    position.first = newX;
}

void GameObject::setPositionY(double newY){
    position.second = newY;
}

void GameObject::setWidth(int newWidth){
    size.first = newWidth;
}

void GameObject::setHeight(int newHeight){
    size.second = newHeight;
}

void GameObject::setEnabled(bool paramEnabled){
    enabled = paramEnabled;
}

bool GameObject::isEnabled(){
    return enabled;
}
