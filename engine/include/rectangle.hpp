#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "engine.hpp"
#include "game_object.hpp"
#include "sdl2includes.hpp"
#include "log.h"
#include "color.hpp"

using namespace engine;

class Rectangle: public GameObject{
public:
    Rectangle(std::string objectName, double positionX, double positionY, int width, int height, bool newAlphaActive, Color * newColor);
    ~Rectangle();
    void update(double timeElapsed);
    void draw();
    void init();
    void setAlphaActive(bool isActive);
    bool getAlphaActive();
    void setColor(Color * newColor);
private:
    bool alphaActive;
    SDL_Texture* texture;
    Color* color;

    void verifyAlpha();
};

#endif
