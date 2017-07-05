#include "camera.hpp"

Camera::Camera(std::string objectName, double positionX, double positionY,
               int width, int height, std::string direction) : Enemy(objectName,
                                              positionX,
                                              positionY,
                                              width, height){

    animator = new Animation(objectName, 1, 4, 0.1);
    animator->addAction("right",0,0);
    animator->addAction("left",2,2);

    animator->setInterval(direction);
    range = 180;
    int angleOfVision = 80;
    int centralizeVisionX = 4;
    if(direction == "right"){
        fieldOfVision = new FieldOfVision(positionX+centralizeVisionX+width/2,positionY+7, range, angleOfVision);
        fieldOfVision->setAngle(305);
    }else{
        fieldOfVision = new FieldOfVision(positionX-centralizeVisionX+width/2,positionY+7, range, angleOfVision);
        fieldOfVision->setAngle(220);
    }

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
