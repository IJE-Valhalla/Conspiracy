#include "camera_switch.hpp"

using namespace engine;

#define FILENAME "assets/sprites/cenary/switch_cameras(14X16).png"
#define WIDTH 14
#define HEIGHT 16
#define ADJUSTX 10
CameraSwitch::CameraSwitch(double positionX, double positionY, std::string direction) : GameObject(FILENAME,positionX - ADJUSTX,positionY - ADJUSTX,
                                                                     WIDTH+ADJUSTX*2, HEIGHT+ADJUSTX*2){
    animator = new Animation(FILENAME, 1, 2, 0.1);
    switchEfffect = new Audio("assets/sounds/TURNOFFCAMERA.wav", "EFFECT", 128);

    animator->addAction("on", 0,0);
    animator->addAction("off",1,1);
    animator->setInterval("on");
    direction = direction;
    working = true;
}

void CameraSwitch::draw(){
    animator->draw_instant(getPositionX()+ADJUSTX, getPositionY()+ADJUSTX);
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}

void CameraSwitch::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
}

bool CameraSwitch::isWorking(){
    return working;
}

void CameraSwitch::turnOff(){
    if(animator->getInterval().first!="off"){
        working = false;
        animator->setInterval("off");
        switchEfffect->play(0);
    }
}
