#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <iostream>
#include <string>
#include "sprite.hpp"

namespace engine{
    class GameObject{
    public:
        GameObject(std::string objectName, double positionX, double positionY,int width, int height);
        GameObject();
        ~GameObject();

        virtual void draw();
        virtual void update();

        std::string getName();
        double getPositionX();
        double getPositionY();
        int getWidth();
        int getHeight();

        void setName(std::string newName);
        void setPositionX(double newPosition);
        void setPositionY(double newPosition);
        void setWidth(int newWidth);
        void setHeight(int newHeight);

    private:
        std::string name;

        // X position and Y position in pixels
        std::pair <double, double> position;

        // Width and Height in pixels
        std::pair <int, int> size;

    };
}

#endif
