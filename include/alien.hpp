#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "game_object.hpp"
#include "engine.hpp"
#include "animation.hpp"

using namespace engine;

class Alien: public GameObject{
public:
    Alien(std::string objectName, int positionX, int positionY, int width, int height);
    ~Alien();
    void update(int timeElapsed);
    void draw();
    void init();
private:
    Animation* animator;
};

#endif
