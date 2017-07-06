#include "camera.hpp"

Camera::Camera(std::string objectName, double positionX, double positionY,
               int width, int height, std::string direction) : Enemy(objectName,
                                              positionX,
                                              positionY,
                                              width, height){

    animator = new Animation(objectName, 2, 4, 0.1);
    animator->addAction("right",0,0);
    animator->addAction("left",2,2);
    animator->addAction("upright",4,4);
    animator->addAction("upleft",6,6);

    animator->setInterval(direction);
    range = 180;
    int angleOfVision = 80;
    int centralizeVisionX = 4;
    if(direction == "right"){
        fieldOfVision = new FieldOfVision(positionX+centralizeVisionX+width/2,positionY+7, range, angleOfVision);
        fieldOfVision->setAngle(305);
    }else if(direction  == "left"){
        fieldOfVision = new FieldOfVision(positionX-centralizeVisionX+width/2,positionY+7, range, angleOfVision);
        fieldOfVision->setAngle(220);
    }else if(direction == "upleft"){
        fieldOfVision = new FieldOfVision(positionX-centralizeVisionX-2+width/2,positionY, range, angleOfVision);
        fieldOfVision->setAngle(140);
    }else{
        fieldOfVision = new FieldOfVision(positionX-centralizeVisionX+9+width/2,positionY, range, angleOfVision);
        fieldOfVision->setAngle(45);
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
