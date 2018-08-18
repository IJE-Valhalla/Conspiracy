#ifndef GROUND_HPP
#define GROUND_HPP

#include "animation.hpp"
#include "game_object.hpp"

using namespace engine;

class Ground: public GameObject{
public:
    Ground(std::string objectName, double positionX, double positionY, int width, int height);
    ~Ground();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
private:
    Animation* animator;
};
#endif
