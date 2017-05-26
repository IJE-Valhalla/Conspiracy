#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "collision_manager.hpp"

using namespace engine;

class Alien: public GameObject{
public:
    Alien(std::string objectName, double positionX, double positionY, int width, int height);
    ~Alien();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
private:
    void walkInX(double & incX);
    void walkInY(double & incY);
    void specialAction();
    Animation* animator;
    int idleAnimationNumber;
};

#endif
