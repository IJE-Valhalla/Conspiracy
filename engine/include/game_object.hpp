#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <iostream>
#include <string>

namespace engine{
    class GameObject{
    public:
        GameObject() {}
        GameObject(std::string objectName, int positionX, int positionY,int width, int height);
        virtual ~GameObject() {}

        virtual void draw(){}
        virtual void update(){}

        std::string getName();
        int getPositionX();
        int getPositionY();
        int getWidth();
        int getHeight();

        void setName(std::string newName);
        void setPositionX(int newPosition);
        void setPositionY(int newPosition);
        void setWidth(int newWidth);
        void setHeight(int newHeight);

    private:
        std::string name;

        // X position and Y position in pixels
        std::pair <int, int> position;

        // Width and Height in pixels
        std::pair <int, int> size;

    };
}
#endif
