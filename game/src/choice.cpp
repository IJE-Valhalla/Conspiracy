#include "choice.hpp"

Choice::Choice(std::string objectName, double positionX, double positionY,
                                     int width, int height, std::string title, int sizeTitle) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    button = new Button("assets/fonts/font.ttf", positionX + (width/2)*0.2, positionY + height, 200, 150, title, sizeTitle);
    sprite = new Sprite(objectName);
    padlock = new Sprite("assets/sprites/padlock.png");
    chosen = false;
    unlock = false;
    Color *color = new Color(0, 0, 0, 150);
    rectangle = new Rectangle("Rectangle", positionX, positionY, width, height, true, color);
}

Choice::~Choice(){}

void Choice::update(double timeElapsed){
    if(chosen && unlock){
        rectangle->setEnabled(false);
    }else{
        rectangle->setEnabled(true);
    }
    rectangle->update(timeElapsed);

}

void Choice::draw(){
    INFO("TEXT DRAW");
    sprite->draw(getPositionX(), getPositionY());
    if(!unlock){
        padlock->draw(getPositionX()+ (getWidth()/2)*0.8, getPositionY()+ (getHeight()/2)*0.8);
    }
    button->draw();
    rectangle->draw();
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

void Choice::setChosen(bool isChosen){
  chosen = isChosen;
}

void Choice::setUnlock(bool isUnlock){
    unlock = isUnlock;
}

bool Choice::getUnlock(){
    return unlock;
}
