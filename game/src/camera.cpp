#include "camera.hpp"

Camera::Camera(std::string objectName, double positionX, double positionY,
             int width, int height) : Enemy(objectName,
                                            positionX,
                                            positionY,
                                            width, height){

        animator = new Animation(objectName, 1, 4, 0.1);

        range = 150;
        int angleOfVision = 60;

        fieldOfVision = new FieldOfVision(positionX+width/2,positionY, range, angleOfVision);

}

Camera::~Camera(){
}

void Camera::update(double timeElapsed){
        animator->update();
}

void Camera::draw(){
        animator->draw(getPositionX()-10, getPositionY()-10);
        animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
        fieldOfVision->draw();
}

int Camera::getRange(){
        return range;
}

FieldOfVision* Camera::getFieldOfVision(){
        return fieldOfVision;
}
