#ifndef DOOR_SWITCH_HPP
#define DOOR_SWITCH_HPP

#include "engine.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "audio.hpp"
#include "progress_bar.hpp"

using namespace engine;

class DoorSwitch: public GameObject{
public:
    DoorSwitch(std::string objectName, double positionX, double positionY, int width, int height);
    ~DoorSwitch();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
    void animate();
    void stopAnimation();
    bool isPressed();
    void playEffect();
    void stopEffect();
    double getHackingBarPercent();
    void resetHackingProgress();
protected:
    bool pressed;
    Animation* animator;
private:
    Audio *hacking_effect;
    ProgressBar *hacking_bar;
};

#endif
