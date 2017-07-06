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
    Camera(double positionX, double positionY, std::string direction);
    Camera(double positionX, double positionY, std::string direction, int angleOfVision, int range, int initialAngle);
    ~Camera();
    void update(double timeElapsed);
    void draw();
    int getRange();
    FieldOfVision* getFieldOfVision();
private:
    void initializeVision(int p_range, int p_angleOfVision, std::string direction);
    void initializeAnimator(std::string filename);
    int range;
    int angleOfVision;
    FieldOfVision* fieldOfVision;
    Animation* animator;
};

#endif
