#ifndef SELECT_ALIEN_HPP
#define SELECT_ALIEN_HPP

#include "animation.hpp"
#include "game_object.hpp"
#include "text.hpp"

using namespace engine;

class Header: public GameObject{
public:
    Header(double positionX, double positionY, int maxPapers, int stageNumber);
    ~Header();
    void update(double timeElapsed);
    void draw();
    void init();
    void setAlienSelect(int select);
    Animation * getAnimation();
    void updatePaperQuantity(int newValue);
private:
    Animation* animator;
    Animation* paperIcon;
    Text* paperText;
    Text* stageText;
    int totalPapers;
    int alienSelect;
    Text* convertToText(int newValue);
    void verifySelect();

};
#endif
