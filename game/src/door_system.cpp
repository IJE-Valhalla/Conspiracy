#include "log.h"
#include "door_system.hpp"

using namespace engine;

DoorSystem::DoorSystem(std::pair<int,int> doorPosition,
                       std::pair<int,int> switchPosition, std::string doorSide){

    if(doorSide.compare("RIGHT") == 0 || doorSide.compare("LEFT") == 0){
        door = new Door("assets/sprites/cenary/porta_anima_lateral(40X59).png", doorPosition.first, doorPosition.second, 40, 60, doorSide);
    }else{
        door = new Door("assets/sprites/cenary/porta_anima.png", doorPosition.first, doorPosition.second, 79, 58, doorSide);
    }

    computerTable = new ComputerTable("assets/sprites/PC_sprites(34X20).png", switchPosition.first,switchPosition.second, 60, 24);
}
DoorSystem::~DoorSystem(){}

void DoorSystem::update(double timeElapsed){
    door->update(timeElapsed);
    computerTable->update(timeElapsed);
    if(!computerTable->getDoorSwitch()->isEnabled() && !door->isOpen()){
        door->setOpen(true);
        door->setEnabled(false);
        door->playEffect();
    }
}

void DoorSystem::draw(){
    door->draw();
    computerTable->draw();
}

GameObject* DoorSystem::getDoor(){
    return door;
}

GameObject* DoorSystem::getSwitch(){
    return computerTable->getDoorSwitch();
}

GameObject* DoorSystem::getTable(){
    return computerTable->getTable();
}
