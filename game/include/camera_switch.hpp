#ifndef CAMERA_SWITCH_HPP
#define CAMERA_SWITCH_HPP

#include "engine.hpp"
#include "audio.hpp"

using namespace engine;

class CameraSwitch: public GameObject{
public:
    CameraSwitch(double positionX, double positionY, std::string direction);
    ~CameraSwitch() = default;
    void update(double timeElapsed);
    void draw();
    bool isWorking();
    void turnOff();
private:
    Audio* switchEfffect;
    Animation* animator;
    bool working;
};

#endif
