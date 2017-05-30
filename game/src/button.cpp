#include "button.hpp"

Button::Button(std::string objectName, double positionX, double positionY,
                                     int width, int height, std::string title, int size) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    text = new Text(title, objectName, size, true, new Color(0,0,0,0), new Color(255,255,255,255));
}

Button::~Button(){}

void Button::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.

}

void Button::draw(){
    INFO("TEXT DRAW");
    text->draw(getPositionX(), getPositionY());
}
