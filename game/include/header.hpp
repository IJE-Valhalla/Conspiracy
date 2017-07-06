#ifndef SELECT_ALIEN_HPP
#define SELECT_ALIEN_HPP

#include "animation.hpp"
#include "game_object.hpp"

using namespace engine;

class Header: public GameObject{
public:
    Header(double positionX, double positionY);
    ~Header();
    void update(double timeElapsed);
    void draw();
    void init();
    void setAlienSelect(int select);
    Animation * getAnimation();
private:
    Animation* animator;
    int alienSelect;
    void verifySelect();
};
#endif
