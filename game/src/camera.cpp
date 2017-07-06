#include "camera.hpp"


#define FILENAME "assets/sprites/camera(11X8).png"
#define WIDTH 11
#define HEIGHT 8

Camera::Camera(double positionX, double positionY, std::string direction) : Enemy(FILENAME,positionX,positionY,
                                                                     WIDTH, HEIGHT){
    initializeAnimator(FILENAME);
    animator->setInterval(direction);

    int default_range = 180;
    int default_angleOfVision = 80;

    initializeVision(default_range, default_angleOfVision, direction);
}

Camera::Camera(double positionX, double positionY, std::string direction,
               int p_angleOfVision, int p_range, int initialAngle): Enemy(FILENAME,positionX,positionY,
                                                                     WIDTH, HEIGHT){
    initializeAnimator(FILENAME);
    animator->setInterval(direction);

    initializeVision(p_range, p_angleOfVision, direction);
    fieldOfVision->setAngle(initialAngle);
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

void Camera::initializeAnimator(std::string filename){
    animator = new Animation(filename, 2, 4, 0.1);
    animator->addAction("right",0,0);
    animator->addAction("left",2,2);
    animator->addAction("upright",4,4);
    animator->addAction("upleft",6,6);
}

void Camera::initializeVision(int p_range, int p_angleOfVision, std::string direction){
    range = p_range;
    angleOfVision = p_angleOfVision;

    if(direction == "right"){
        fieldOfVision = new FieldOfVision(getPositionX()+4+getWidth()/2,getPositionY()+7, range, angleOfVision);
        fieldOfVision->setAngle(305);
    }else if(direction  == "left"){
        fieldOfVision = new FieldOfVision(getPositionX()-4+getWidth()/2,getPositionY()+7, range, angleOfVision);
        fieldOfVision->setAngle(220);
    }else if(direction == "upleft"){
        fieldOfVision = new FieldOfVision(getPositionX()-6+getWidth()/2,getPositionY(), range, angleOfVision);
        fieldOfVision->setAngle(140);
    }else{
        fieldOfVision = new FieldOfVision(getPositionX()+5+getWidth()/2,getPositionY(), range, angleOfVision);
        fieldOfVision->setAngle(45);
    }
}

int Camera::getRange(){
    return range;
}

FieldOfVision* Camera::getFieldOfVision(){
    return fieldOfVision;
}
