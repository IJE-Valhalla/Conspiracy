#ifndef GUARD_HPP
#define GUARD_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "animation.hpp"
#include "enemy.hpp"
#include "collision_manager.hpp"

using namespace engine;

class Guard: public Enemy{
public:
    Guard(std::string objectName, double positionX, double positionY, int width, int height, std::string initialDirection);
    ~Guard();
    void update(double timeElapsed);
    void draw();
    Animation * getAnimation();
private:
    void walkInX(double & incX);
    void walkInY(double & incY);
    void specialAction();
    int idleAnimationNumber;
    Animation* animator;
    std::string direction;
};

#endif
