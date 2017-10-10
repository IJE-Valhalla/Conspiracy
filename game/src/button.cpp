#include "button.hpp"

Button::Button(std::string objectName, double positionX, double positionY,
                                     int width, int height, std::string title, int sizeTitle) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    text = new Text(title, objectName, sizeTitle, true, Color{0,0,0,0}, Color{0,0,0,0});
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

void Button::setTextColor(const Color &newTextColor){
    text->setTextColor(newTextColor);
}

Text * Button::getText(){
    return text;
}
