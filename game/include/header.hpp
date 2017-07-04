#ifndef SELECT_ALIEN_HPP
#define SELECT_ALIEN_HPP

#include "animation.hpp"
#include "game_object.hpp"

using namespace engine;

class Header: public GameObject{
public:
    Header(std::string objectName, double positionX, double positionY, int width, int height);
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
