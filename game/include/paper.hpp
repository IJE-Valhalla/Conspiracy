#ifndef PAPER_HPP
#define PAPER_HPP

#include "engine.hpp"
#include "animation.hpp"

using namespace engine;

class Paper: public GameObject{
public:
    Paper(std::string objectName, double positionX, double positionY, int width, int height);
    ~Paper();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
    void animate();
    bool isEdited();
protected:
    Animation* animator;
    bool edited;
    bool isBeingEdited;
};

#endif
