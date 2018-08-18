#ifndef CAMERA_SYSTEM_HPP
#define CAMERA_SYSTEM_HPP

#include "camera.hpp"
#include "camera_switch.hpp"
#include "camera_lever.hpp"

using namespace engine;

class CameraSystem: public GameObject{
public:
    CameraSystem(Camera* camera, CameraSwitch* cameraSwitch);
    CameraSystem(Camera* camera, CameraSwitch* cameraSwitch, CameraLever* cameraLever);
    ~CameraSystem() = default;
    void update(double timeElapsed);
    void draw();
    Camera* getCamera();
    CameraLever* getCameraLever();
    CameraSwitch* getCameraSwitch();
private:
    Camera* camera;
    CameraSwitch* cameraSwitch;
    CameraLever* cameraLever;
    int lastLeverState;
};

#endif
