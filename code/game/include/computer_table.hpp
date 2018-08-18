#ifndef COMPUTER_TABLE_HPP
#define COMPUTER_TABLE_HPP

#include "engine.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "table.hpp"
#include "door_switch.hpp"


using namespace engine;

class ComputerTable: public GameObject{
public:
    ComputerTable(std::string objectName, double positionX, double positionY, int width, int height);
    ~ComputerTable();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
    DoorSwitch* getDoorSwitch();
    Table* getTable();
protected:
    Animation* animator;
    DoorSwitch* doorSwitch;
    Table* table;
};

#endif
