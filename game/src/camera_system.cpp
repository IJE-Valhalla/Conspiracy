#include "camera_system.hpp"

using namespace engine;

CameraSystem::CameraSystem(Camera* p_camera, CameraSwitch* p_cameraSwitch){
    camera = p_camera;
    cameraSwitch = p_cameraSwitch;
    cameraLever = NULL;
    lastLeverState = 1;
}

CameraSystem::CameraSystem(Camera* p_camera, CameraSwitch* p_cameraSwitch, CameraLever* p_cameraLever){
    camera = p_camera;
    cameraSwitch = p_cameraSwitch;
    cameraLever = p_cameraLever;
}

void CameraSystem::update(double timeElapsed){
    camera->update(timeElapsed);
    cameraSwitch->update(timeElapsed);
    if(cameraLever != NULL){
     cameraLever->update(timeElapsed);
        if(cameraLever->getState() != lastLeverState){
            lastLeverState = cameraLever->getState();
            camera->changeState(cameraLever->getState());
        }
    }
    if(!cameraSwitch->isWorking() && camera->isTurnedOn()){
         camera->turnOff();
    }
}
void CameraSystem::draw(){
    camera->draw();
    cameraSwitch->draw();
    if(cameraLever != NULL){
        cameraLever->draw();
    }
}
Camera* CameraSystem::getCamera(){
    return camera;
}

CameraSwitch* CameraSystem::getCameraSwitch(){
    return cameraSwitch;
}

CameraLever* CameraSystem::getCameraLever(){
    return cameraLever;
}
