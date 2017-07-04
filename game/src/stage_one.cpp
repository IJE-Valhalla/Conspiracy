#include "stage_one.hpp"

using namespace engine;

StageOne::StageOne(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageOne::createGuards(){
    std::pair <std::string, int> wayOne ("right", 480);
    std::pair <std::string, int> wayTwo ("up", HEADER_SIZE + 20);
    std::pair <std::string, int> wayThree ("left", 220);
    std::pair <std::string, int> wayFour ("down", HEADER_SIZE + 120);

    Guard * guard = new Guard("assets/sprites/seguranca_sheet.png", 220, HEADER_SIZE + 120, 18, 35, "right");
    guard->addWay(1, wayOne);
    guard->addWay(2, wayTwo);
    guard->addWay(3, wayThree);
    guard->addWay(4, wayFour);

    gameObjectsList.push_back(guard);
}

void StageOne::createAliens(){
    std::pair <int, int> biluPos (10, HEADER_SIZE + 500);
    std::pair <int, int> etemerPos (30, HEADER_SIZE + 510);
    std::pair <int, int> varginhaPos (50, HEADER_SIZE + 500);

    gameObjectsList.push_back(new Player(biluPos, etemerPos, varginhaPos));
}

void StageOne::createDoorSystems(){
    std::pair<int,int> doorOnePosition (360, HEADER_SIZE + 240);
    std::pair<int,int> switchOnePosition (60, HEADER_SIZE + 50);


    std::pair<int,int> doorTwoPosition (660, HEADER_SIZE + 381);
    std::pair<int,int> switchTwoPosition (650, HEADER_SIZE + 50);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "DOWN"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "DOWN"));
}

void StageOne::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 100, HEADER_SIZE + 200, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 600, HEADER_SIZE + 220, 60, 34));
}
