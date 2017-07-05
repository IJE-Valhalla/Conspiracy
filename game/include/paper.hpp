#ifndef PAPER_HPP
#define PAPER_HPP

#include "engine.hpp"
#include "animation.hpp"
#include "animation_manager.hpp"
#include "progress_bar.hpp"
#include "audio.hpp"

using namespace engine;

class Paper: public GameObject{
public:
    Paper(std::string objectName, double positionX, double positionY, int width, int height);
    ~Paper();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
    void animate();
    void stopAnimation();
    bool isEdited();
    double getEditingBarPercent();
    void resetEditingProgress();
    void playEffect();
    void stopEffect();
protected:
    Animation* animator;
    ProgressBar *editing_bar;
    bool edited;
    bool isBeingEdited;
    Audio* paperEditingSound;
};

#endif
