#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "animation.hpp"
#include "enemy.hpp"
#include "field_of_vision.hpp"

using namespace engine;

class Camera: public Enemy{
public:
    Camera(std::string objectName, double positionX, double positionY, int width, int height);
    ~Camera();
    void update(double timeElapsed);
    void draw();
    int getRange();
    FieldOfVision* getFieldOfVision();
private:
    int range;
    FieldOfVision* fieldOfVision;
    Animation* animator;
};

#endif
