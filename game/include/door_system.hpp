#ifndef DOOR_SYSTEM_HPP
#define DOOR_SYSTEM_HPP

#include "engine.hpp"
#include "door.hpp"
#include "door_switch.hpp"
using namespace engine;

class DoorSystem: public GameObject{
public:
    DoorSystem(std::pair<int,int> doorPosition, std::pair<int,int> switchPosition);
    ~DoorSystem();
    void update(double timeElapsed);
    void draw();
    GameObject* getDoor();
    GameObject* getSwitch();
private:
    Door* door;
    DoorSwitch* doorSwitch;
};
#endif
