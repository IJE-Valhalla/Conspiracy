#ifndef CAMERA_LEVER_HPP
#define CAMERA_LEVER_HPP

#include "engine.hpp"
#include <memory>

using namespace engine;

class CameraLever: public GameObject{
public:
    CameraLever(double positionX, double positionY, std::string direction);
    ~CameraLever() = default;
    void update(double timeElapsed);
    void draw();
    int getState();
    void nextState();
private:
    std::unique_ptr<Animation> animator{nullptr};
    int state{0};
    int stateInc{0};
};

#endif
