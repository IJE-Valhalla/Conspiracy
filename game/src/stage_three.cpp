#include "stage_three.hpp"

using namespace engine;

StageThree::StageThree(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageThree::createGuards(){
    std::pair <std::string, int> wayOne ("right", 480);
    std::pair <std::string, int> wayTwo ("up", HEADER_SIZE + 20);
    std::pair <std::string, int> wayThree ("left", 220);
    std::pair <std::string, int> wayFour ("down", HEADER_SIZE + 120);

    Guard * guard = new Guard("assets/sprites/seguranca_sheet.png", 220, HEADER_SIZE + 120, 18, 35, "right", 10);
    guard->addWay(1, wayOne);
    guard->addWay(2, wayTwo);
    guard->addWay(3, wayThree);
    guard->addWay(4, wayFour);

    gameObjectsList.push_back(guard);
}

void StageThree::createAliens(){
    std::pair <int, int> biluPos (280, HEADER_SIZE + 560);
    std::pair <int, int> etemerPos (300, HEADER_SIZE + 560);
    std::pair <int, int> varginhaPos (620, HEADER_SIZE + 550);

    player = new Player(biluPos, etemerPos, varginhaPos);
    gameObjectsList.push_back(player);
}

void StageThree::createDoorSystems(){
    std::pair<int,int> doorOnePosition (357, HEADER_SIZE + 298);
    std::pair<int,int> switchOnePosition (880, HEADER_SIZE + 50);

    std::pair<int,int> doorTwoPosition (583, HEADER_SIZE + 178);
    std::pair<int,int> switchTwoPosition (10, HEADER_SIZE + 430);

    std::pair<int,int> doorThreePosition (700, HEADER_SIZE + 339);
    std::pair<int,int> switchThreePosition (150, HEADER_SIZE + 50);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "LEFT"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorThreePosition,switchThreePosition, "DOWN"));
}

void StageThree::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 30, HEADER_SIZE + 250, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 475, HEADER_SIZE + 170, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 400, HEADER_SIZE + 290, 60, 34));
}
