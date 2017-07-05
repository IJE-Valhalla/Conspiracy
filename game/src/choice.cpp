#include "choice.hpp"

Choice::Choice(std::string objectName, double positionX, double positionY,
                                     int width, int height, std::string title, int sizeTitle) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    button = new Button("assets/fonts/font.ttf", positionX + (width/2)*0.2, positionY + height, 200, 150, title, sizeTitle);
    sprite = new Sprite(objectName);
}

Choice::~Choice(){}

void Choice::update(double timeElapsed){
    timeElapsed = timeElapsed;
    INFO(timeElapsed);

}

void Choice::draw(){
    INFO("TEXT DRAW");
    sprite->draw(getPositionX(), getPositionY());
    button->draw();
}

void Choice::setTextColor(Color * newTextColor){
    button->setTextColor(newTextColor);
}

void Choice::setBackgroundColor(Color * newBackgroundColor){
    button->setTextColor(newBackgroundColor);
}

Text * Choice::getText(){
    return button->getText();
}
