#ifndef CHOICE_HPP
#define CHOICE_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "game_object.hpp"
#include "button.hpp"
#include "sprite.hpp"
#include "color.hpp"
#include "rectangle.hpp"

using namespace engine;

class Choice: public GameObject{
public:
    Choice(std::string objectName, double positionX, double positionY, int width, int height, std::string title, int sizeTitle);
    ~Choice();
    void update(double timeElapsed);
    void setTextColor(Color * newTextColor);
    void setBackgroundColor(Color * newBackgroundColor);
    void setChosen(bool isChosen);
    void draw();
    void init();
    Text * getText();
private:
    Sprite * sprite;
    Button * button;
    Rectangle * rectangle;
    bool unlock;
    bool chosen;
};

#endif
