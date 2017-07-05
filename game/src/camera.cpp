#include "camera.hpp"

Camera::Camera(std::string objectName, double positionX, double positionY,
               int width, int height) : Enemy(objectName,
                                              positionX,
                                              positionY,
                                              width, height){

    animator = new Animation(objectName, 1, 4, 0.1);
    animator->addAction("right",0,0);
    animator->setInterval("right");
    range = 150;
    int angleOfVision = 60;

    fieldOfVision = new FieldOfVision(positionX+4+width/2,positionY+7, range, angleOfVision);
    fieldOfVision->setAngle(305);
}

Camera::~Camera(){
}

void Camera::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
}

void Camera::draw(){
    animator->draw(getPositionX(), getPositionY());
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
    fieldOfVision->draw();
}

int Camera::getRange(){
    return range;
}

FieldOfVision* Camera::getFieldOfVision(){
    return fieldOfVision;
}
