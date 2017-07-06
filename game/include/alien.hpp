#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "collision_manager.hpp"
#include "audio.hpp"
#include "finish_point.hpp"

using namespace engine;

class Alien: public GameObject{
public:
    Alien(std::string objectName, double positionX, double positionY, int width, int height);
    ~Alien();
    virtual void update(double timeElapsed) = 0;
    void draw();
    void init();
    Animation * getAnimation();
    void setAlienSelected();
    void setAlienDeselect();
    bool isInPosition();

protected:
    void walkInX(double & incX);
    void walkInY(double & incY, double incX);
    Animation* animator;
    int idleAnimationNumber;
    std::string alienName;
    bool blockMovement;
    bool isSelected;
    bool inPosition;
    Audio *movement_sound_effect;
};

#endif
