#include "stage_five.hpp"

using namespace engine;

StageFive::StageFive(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageFive::createGuards(){
    std::pair <std::string, int> wayOne ("right", 480);
    std::pair <std::string, int> wayTwo ("up", 20);
    std::pair <std::string, int> wayThree ("left", 220);
    std::pair <std::string, int> wayFour ("down", 120);

    Guard * guard = new Guard("assets/sprites/seguranca_sheet.png", 220, 120, 18, 35, "right",10);
    guard->addWay(1, wayOne);
    guard->addWay(2, wayTwo);
    guard->addWay(3, wayThree);
    guard->addWay(4, wayFour);

    gameObjectsList.push_back(guard);
}

void StageFive::createAliens(){
    std::pair <int, int> biluPos (480, 130);
    std::pair <int, int> etemerPos (780, 130);
    std::pair <int, int> varginhaPos (130, 130);

    player = new Player(biluPos, etemerPos, varginhaPos);
    gameObjectsList.push_back(player);
}

void StageFive::createDoorSystems(){
    std::pair<int,int> doorOnePosition (183, 270);
    std::pair<int,int> switchOnePosition (760, 350);

    std::pair<int,int> doorTwoPosition (460, 270);
    std::pair<int,int> switchTwoPosition (490, 390);

    std::pair<int,int> doorThreePosition (780, 200);
    std::pair<int,int> switchThreePosition (210, 510);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorThreePosition,switchThreePosition, "DOWN"));
}

void StageFive::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 880, 580, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 10, 580, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 530, 530, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 550, 100, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 650, 140, 60, 34));
}

void StageFive::createTables(){
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 890, 520, 60, 34));
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 828, 520, 60, 34));
}
