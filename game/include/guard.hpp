#ifndef GUARD_HPP
#define GUARD_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "animation.hpp"
#include "collision_manager.hpp"
#include "field_of_vision.hpp"
#include "progress_bar.hpp"
#include "timer.hpp"

using namespace engine;

class Guard: public GameObject{
public:
    Guard(double positionX, double positionY, int width, int height, std::string initialDirection, double newWaitingTime);
    ~Guard();
    void update(double timeElapsed);
    void draw();
    void addWay(int key, std::string p_direction, int point);
    void setWayActive(bool isActive);
    void verifyDistance(GameObject* alien);
    void talkingToETemer(std::string status);
    void notTalkingToETemer();
    double getTalkingBarPercent();
    void setWaitingTime(double newWaitingTime);
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
    void verifyDeadLockHorizontal();
    void verifyDeadLockVertical();
    void stop(double &incX, double &incY);
    void nextWay();
    int idleAnimationNumber;
    int wayActual;
    bool wayActive;
    bool talking;
    bool detecting;
    int range;
    int quantityRepeatWay;
    int currentRepeat;
    double waitingTime;
    FieldOfVision* fieldOfVision;
    Animation* animator;
    Animation* exclamation;
    ProgressBar * talkingBar;
    ProgressBar * detectionBar;
    std::string direction;
    std::string lastDirection;
    Timer * timerHorizontal;
    Timer * timerVertical;
    std::unordered_map< int, std::pair<std::string, int>> ways;
    std::unordered_map< int, std::pair<std::string, int>>::iterator search;
};

#endif
