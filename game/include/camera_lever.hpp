#ifndef CAMERA_LEVER_HPP
#define CAMERA_LEVER_HPP

#include "engine.hpp"

using namespace engine;

class CameraLever: public GameObject{
public:
    CameraLever(double positionX, double positionY, std::string direction);
    ~CameraLever();
    void update(double timeElapsed);
    void draw();
    int getState();
    void nextState();
private:
    Animation* animator;
    int state;
    int stateInc;
};

#endif
