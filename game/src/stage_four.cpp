#include "stage_four.hpp"

using namespace engine;

StageFour::StageFour(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageFour::createGuards(){
    std::pair <std::string, int> wayOne ("right", 480);
    std::pair <std::string, int> wayTwo ("up", 20);
    std::pair <std::string, int> wayThree ("left", 220);
    std::pair <std::string, int> wayFour ("down", 120);

    Guard * guard = new Guard("assets/sprites/seguranca_sheet.png", 220, 120, 18, 35, "right");
    guard->addWay(1, wayOne);
    guard->addWay(2, wayTwo);
    guard->addWay(3, wayThree);
    guard->addWay(4, wayFour);

    gameObjectsList.push_back(guard);
}

void StageFour::createAliens(){
    std::pair <int, int> biluPos (40, 290);
    std::pair <int, int> etemerPos (35, 270);
    std::pair <int, int> varginhaPos (30, 310);

    gameObjectsList.push_back(new Player(biluPos, etemerPos, varginhaPos));
}

void StageFour::createDoorSystems(){
    std::pair<int,int> doorOnePosition (183, 240);
    std::pair<int,int> switchOnePosition (880, 300);

    std::pair<int,int> doorTwoPosition (460, 240);
    std::pair<int,int> switchTwoPosition (460, 350);

    std::pair<int,int> doorThreePosition (250, 50);
    std::pair<int,int> switchThreePosition (20, 50);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorThreePosition,switchThreePosition, "DOWN"));
}

void StageFour::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 880, 50, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 880, 520, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 610, 270, 60, 34));
}

void StageFour::createTables(){
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 890, 360, 60, 34));
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 828, 360, 60, 34));

    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 890, 460, 60, 34));
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 828, 460, 60, 34));
}
