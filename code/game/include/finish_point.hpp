#ifndef FINISH_POINT_HPP
#define FINISH_POINT_HPP

#include "game_object.hpp"
#include "animation.hpp"

using namespace engine;

class FinishPoint: public GameObject{
public:
    FinishPoint(std::string objectName, double positionX, double positionY,int width, int height, std::string alienNames);
    void update(double timeElapsed);
    void draw();
    std::string getAlienNames();
private:
    std::string aliens;
    std::string orientation;
    Animation* animator;
    Animation* biluAnim;
    Animation* etemerAnim;
    Animation* varginhaAnim;
};

#endif
