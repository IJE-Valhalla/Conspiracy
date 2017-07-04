#ifndef CHAIR_HPP
#define CHAIR_HPP

#include "engine.hpp"
#include "sprite.hpp"
#include "game_object.hpp"

using namespace engine;

class Chair: public GameObject{
public:
    Chair(std::string objectName, double positionX, double positionY, int width, int height);
    ~Chair();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
    void setMoving(bool move);
    void setDirection(std::string currentDirection);
protected:
    Animation* animator;
    bool isMoving;
    std::string direction;
    void moveInX(double incX);
    void moveInY(double incY);
};

#endif
