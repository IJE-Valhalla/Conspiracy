#include "game_object.hpp"
#include <game_object.hpp>
#include <log.h>

namespace engine{

    GameObject::GameObject(std::string objectName, int positionX, int positionY,
            int width, int height, Sprite* objectSprite){
            setName(objectName);
            setPositionX(positionX);
            setPositionY(positionY);
            setWidth(width);
            setHeight(height);
            setSprite(objectSprite);
        }

        GameObject::~GameObject(){

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

        Sprite* GameObject::getSprite(){
            return sprite;
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

        void GameObject::setSprite(Sprite* newSprite){
            sprite = newSprite;
        }
    }
