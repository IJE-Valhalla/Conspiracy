#ifndef DOOR_HPP
#define DOOR_HPP

#include "engine.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "audio.hpp"

using namespace engine;

class Door: public GameObject{
public:
    Door(std::string objectName, double positionX, double positionY,
         int width, int height, std::string doorSide);
    ~Door();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
    bool isOpen();
    void setOpen(bool status);
    void playEffect();
    std::string getDoorSide();
protected:
    Animation* animator;
private:
    Audio *door_effect;
    bool open;
    std::string side;
};

#endif
