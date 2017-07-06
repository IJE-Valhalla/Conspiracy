#ifndef CAMERA_SWITCH_HPP
#define CAMERA_SWITCH_HPP

#include "engine.hpp"

using namespace engine;

class CameraSwitch: public GameObject{
public:
    CameraSwitch(double positionX, double positionY, std::string direction);
    ~CameraSwitch();
    void update(double timeElapsed);
    void draw();
    bool isWorking();
    void turnOff();
private:
    Animation* animator;
    bool working;
};

#endif
