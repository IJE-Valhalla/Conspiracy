#include "computer_table.hpp"
#include "log.h"

ComputerTable::ComputerTable(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
table = new Table("assets/sprites/mesa.png", positionX, positionY, width, height);
doorSwitch = new DoorSwitch("assets/sprites/PC_sprites(34X20).png", positionX + 15, positionY - 7, 34, 60);
}

ComputerTable::~ComputerTable(){

}

void ComputerTable::update(double timeElapsed){
   table->update(timeElapsed);
    doorSwitch->update(timeElapsed);
}

void ComputerTable::draw(){
   table->draw();
   doorSwitch->draw();
}

DoorSwitch* ComputerTable::getDoorSwitch(){
    return doorSwitch;
}

Table* ComputerTable::getTable(){
    return table;
}
