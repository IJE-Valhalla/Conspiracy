#include "stage_two.hpp"

using namespace engine;

StageTwo::StageTwo(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageTwo::createGuards(){
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

void StageTwo::createAliens(){
    std::pair <int, int> biluPos (880, 550);
    std::pair <int, int> etemerPos (900, 550);
    std::pair <int, int> varginhaPos (920, 550);

    gameObjectsList.push_back(new Player(biluPos, etemerPos, varginhaPos));
}

void StageTwo::createDoorSystems(){
    std::pair<int,int> doorOnePosition (183, 240);
    std::pair<int,int> switchOnePosition (610, 50);

    std::pair<int,int> doorTwoPosition (460, 240);
    std::pair<int,int> switchTwoPosition (800, 50);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "RIGHT"));
}

void StageTwo::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 30, 250, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 350, 170, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 30, 490, 60, 34));
}
