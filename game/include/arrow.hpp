#ifndef ARROW_HPP
#define ARROW_HPP

#include "engine.hpp"
#include "sprite.hpp"
#include "game_object.hpp"

using namespace engine;

class Arrow: public GameObject{
public:
    Arrow(std::string objectName, double positionX, double positionY, int width, int height);
    ~Arrow();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
protected:
    Animation* animator;
};

#endif
