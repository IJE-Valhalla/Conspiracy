#include "camera_switch.hpp"

using namespace engine;

#define FILENAME "assets/sprites/exclamation2.png"
#define WIDTH 10
#define HEIGHT 10

CameraSwitch::CameraSwitch(double positionX, double positionY, std::string direction) : GameObject(FILENAME,positionX,positionY,
                                                                     WIDTH, HEIGHT){
    animator = new Animation(FILENAME, 1, 2, 0.1);
    animator->addAction("on", 0,0);
    animator->addAction("off",1,1);
    animator->setInterval("on");
    working = true;
}

void CameraSwitch::draw(){
    animator->draw(getPositionX(), getPositionY());
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
    working = false;
    animator->setInterval("off");
}
