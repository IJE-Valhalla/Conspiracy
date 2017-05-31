#ifndef DOOR_HPP
#define DOOR_HPP

#include "engine.hpp"
#include "animation.hpp"
#include "game_object.hpp"

using namespace engine;

class Door: public GameObject{
public:
    Door(std::string objectName, double positionX, double positionY, int width, int height);
    ~Door();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
protected:
    Animation* animator;
};

#endif
