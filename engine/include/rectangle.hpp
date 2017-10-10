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
    Rectangle(std::string objectName, double positionX, double positionY, int width, int height, bool newAlphaActive, const Color &newColor);
    ~Rectangle();
    void update(double timeElapsed);
    void draw();
    void init();
    void setAlphaActive(bool isActive);
    bool getAlphaActive();
    void setColor(const Color &newColor);
private:
    bool alphaActive{false};
    SDL_Texture* texture{nullptr};
    Color color{0,0,0,0};

    void verifyAlpha();
};

#endif
