#include "button.hpp"

Button::Button(std::string objectName, double positionX, double positionY,
                                     int width, int height, std::string title, int sizeTitle) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    text = new Text(title, objectName, sizeTitle, true, new Color(100,100,100,255), new Color(0,0,0,0));
}

Button::~Button(){}

void Button::update(double timeElapsed){
    timeElapsed = timeElapsed;
    INFO(timeElapsed);

}

void Button::draw(){
    INFO("TEXT DRAW");
    text->draw(getPositionX(), getPositionY());
}
