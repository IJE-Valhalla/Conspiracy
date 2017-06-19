#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "game_object.hpp"
#include "text.hpp"

using namespace engine;

class Button: public GameObject{
public:
    Button(std::string objectName, double positionX, double positionY, int width, int height, std::string title, int sizeTitle);
    ~Button();
    void update(double timeElapsed);
    void setTextColor(Color * newTextColor);
    void draw();
    void init();
protected:
    Text * text;
};

#endif
