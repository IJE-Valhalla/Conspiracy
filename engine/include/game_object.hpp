#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <engine.hpp>
#include <sprite.hpp>

namespace engine{
    class GameObject{
    public:
        GameObject(std::string objectName, int positionX, int positionY,
                                           int width, int height,
                                           Sprite* objectSprite);
        ~GameObject();

        void draw();
        void update();

        std::string getName();
        int getPositionX();
        int getPositionY();
        int getWidth();
        int getHeight();
        Sprite* getSprite();

        void setName(std::string newName);
        void setPositionX(int newPosition);
        void setPositionY(int newPosition);
        void setWidth(int newWidth);
        void setHeight(int newHeight);
        void setSprite(Sprite* newSprite);

    private:
        std::string name;

        // X position and Y position in pixels
        std::pair <int, int> position;

        // Width and Height in pixels
        std::pair <int, int> size;

        Sprite* sprite;
    };
}

#endif
