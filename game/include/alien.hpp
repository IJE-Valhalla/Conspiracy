#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "animation.hpp"
#include "game_object.hpp"

using namespace engine;

class Alien: public GameObject{
public:
    Alien(std::string objectName, int positionX, int positionY, int width, int height);
    ~Alien();
    void update(int timeElapsed);
    void draw();
private:
    Animation* animator;
};

#endif
