#ifndef WALL_HPP
#define WALL_HPP

#include "engine.hpp"
#include "animation.hpp"
#include "game_object.hpp"

using namespace engine;

class Wall: public GameObject{
public:
    Wall(std::string objectName, double positionX, double positionY, int width, int height);
    ~Wall();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
private:
    Animation* animator;
};
#endif
