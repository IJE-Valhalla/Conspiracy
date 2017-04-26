#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <engine.hpp>

namespace engine{
    class GameObject{
    public:
        GameObject(std::string objectName, int positionX, int positionY,
                                           int width, int height);
        ~GameObject();

        void draw();
        void update();

        std::string getName();
        int getPositionX();
        int getPositionY();
        int getWidth();
        int getHeight();

        void setName(std::string newName);
        void setPositionX(int newPosition);
        void setPositionY(int newPosition);
        void setWidth(int width);
        void setHeight(int height);

    private:
        std::string name;

        // X position and Y position in pixels
        std::pair <int, int> position;

        // Width and Height in pixels
        std::pair <int, int> size;
    };
}

#endif
