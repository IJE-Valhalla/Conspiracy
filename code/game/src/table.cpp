#include "table.hpp"
#include "log.h"

Table::Table(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
animator = new Animation(objectName, 1, 1, 0.5);
}

Table::~Table(){

}

void Table::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
}

void Table::draw(){
    animator->draw(getPositionX(), (getPositionY() - 10));
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());

}
