#ifndef GUARD_HPP
#define GUARD_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "animation.hpp"
#include "enemy.hpp"
#include "collision_manager.hpp"
#include "field_of_vision.hpp"
#include "progress_bar.hpp"

using namespace engine;

class Guard: public Enemy{
public:
    Guard(std::string objectName, double positionX, double positionY, int width, int height, std::string initialDirection);
    ~Guard();
    void update(double timeElapsed);
    void draw();
    void addWay(int key, std::pair<std::string, int> way);
    void setWayActive(bool isActive);
    void verifyDistance(GameObject* alien);
    void talkingToETemer(std::string status);
    void notTalkingToETemer();
    double getTalkingBarPercent();
    Animation * getAnimation();
    int getRange();
    FieldOfVision* getFieldOfVision();
    std::pair<std::pair<int,int>,std::pair<int,int>> getLine();
private:
    void walkInX(double & incX);
    void walkInY(double & incY);
    void walkInXSpecial(double & incX);
    void walkInYSpecial(double & incY);
    void selectLine();
    void specialAction();
    int idleAnimationNumber;
    int wayActual;
    bool wayActive;
    bool talking;
    int range;
    FieldOfVision* fieldOfVision;
    Animation* animator;
    Animation* exclamation;
    ProgressBar * talkingBar;
    std::string direction;
    std::string lastDirection;
    std::unordered_map< int, std::pair<std::string, int>> ways;
    std::unordered_map< int, std::pair<std::string, int>>::iterator search;
};

#endif
