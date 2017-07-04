#include "stage_three.hpp"

using namespace engine;

StageThree::StageThree(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageThree::createGuards(){
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

void StageThree::createAliens(){
    std::pair <int, int> biluPos (280, 560);
    std::pair <int, int> etemerPos (300, 560);
    std::pair <int, int> varginhaPos (620, 550);

    gameObjectsList.push_back(new Player(biluPos, etemerPos, varginhaPos));
}

void StageThree::createDoorSystems(){
    std::pair<int,int> doorOnePosition (183, 240);
    std::pair<int,int> switchOnePosition (880, 50);

    std::pair<int,int> doorTwoPosition (460, 240);
    std::pair<int,int> switchTwoPosition (10, 430);

    std::pair<int,int> doorThreePosition (250, 50);
    std::pair<int,int> switchThreePosition (150, 50);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorThreePosition,switchThreePosition, "DOWN"));
}

void StageThree::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 30, 250, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 475, 170, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 400, 290, 60, 34));
}
