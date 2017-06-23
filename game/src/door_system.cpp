#include "log.h"
#include "door_system.hpp"

using namespace engine;

DoorSystem::DoorSystem(std::pair<int,int> doorPosition, std::pair<int,int> switchPosition){
    door = new Door("assets/sprites//cenary/porta_anima.png", doorPosition.first, doorPosition.second, 79, 58);
    doorSwitch = new DoorSwitch("assets/sprites/PC_sprites(34X20).png", switchPosition.first,switchPosition.second, 34, 20);
}
DoorSystem::~DoorSystem(){}

void DoorSystem::update(double timeElapsed){
    door->update(timeElapsed);
    doorSwitch->update(timeElapsed);
    if(!doorSwitch->isEnabled() && !door->isOpen()){
        door->setOpen(true);
        door->setEnabled(false);
        door->playEffect();
    }
}

void DoorSystem::draw(){
    door->draw();
    doorSwitch->draw();
}

GameObject* DoorSystem::getDoor(){
    return door;
}

GameObject* DoorSystem::getSwitch(){
    return doorSwitch;
}
