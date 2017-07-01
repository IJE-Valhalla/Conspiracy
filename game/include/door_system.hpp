#ifndef DOOR_SYSTEM_HPP
#define DOOR_SYSTEM_HPP

#include "engine.hpp"
#include "door.hpp"
#include "door_switch.hpp"
#include "computer_table.hpp"

using namespace engine;

class DoorSystem: public GameObject{
public:
    DoorSystem(std::pair<int,int> doorPosition, std::pair<int,int> switchPosition, std::string doorSide);
    ~DoorSystem();
    void update(double timeElapsed);
    void draw();
    GameObject* getDoor();
    GameObject* getSwitch();
    GameObject* getTable();
private:
    Door* door;
    ComputerTable * computerTable;
};
#endif
