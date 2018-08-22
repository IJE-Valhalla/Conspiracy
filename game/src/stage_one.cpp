#include "stage_one.hpp"

using namespace engine;

#define PAPERQUANTITY 2
#define STAGENUMBER 1
StageOne::StageOne(int id, std::string newTiledFile) : GameScene (id, newTiledFile, "assets/sounds/TEMA1.wav"){

}

void StageOne::createGuards(){

    Guard * guard1 = new Guard(220, HEADER_SIZE + 120, 18, 35, "right", 15);
    guard1->addWay(1, "right", 470);
    guard1->addWay(2, "up", HEADER_SIZE + 30);
    guard1->addWay(3, "left", 220);
    guard1->addWay(4, "down", HEADER_SIZE + 120);
    guard1->addWay(5, "right", 470);

    gameObjectsList.push_back(guard1);

    Guard * guard2 = new Guard(880, HEADER_SIZE + 50, 18, 35, "down", 15);
    guard2->addWay(1, "right", 920);
    guard2->addWay(2, "down", HEADER_SIZE + 550);
    guard2->addWay(3, "left", 860);
    guard2->addWay(4, "up", HEADER_SIZE + 50);

    guard2->addWay(5, "right", 920);
    guard2->addWay(6, "down", HEADER_SIZE + 550);
    guard2->addWay(7, "left", 860);
    guard2->addWay(8, "up", HEADER_SIZE + 50);
    guard2->addWay(9, "right", 880);
    guard2->addWay(10, "down", HEADER_SIZE + 550);

    gameObjectsList.push_back(guard2);

}

void StageOne::createAliens(){
    std::pair <int, int> biluPos (10, HEADER_SIZE + 500);
    std::pair <int, int> etemerPos (30, HEADER_SIZE + 510);
    std::pair <int, int> varginhaPos (50, HEADER_SIZE + 500);

    player = new Player(biluPos, etemerPos, varginhaPos, PAPERQUANTITY, STAGENUMBER);

    gameObjectsList.push_back(player);
}

void StageOne::createDoorSystems(){
    std::pair<int,int> doorOnePosition (323, HEADER_SIZE + 220);
    std::pair<int,int> switchOnePosition (60, HEADER_SIZE + 50);


    std::pair<int,int> doorTwoPosition (660, HEADER_SIZE + 381);
    std::pair<int,int> switchTwoPosition (650, HEADER_SIZE + 50);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "DOWN"));
}

void StageOne::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 100, HEADER_SIZE + 200, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 600, HEADER_SIZE + 220, 60, 34));
}

void StageOne::createFinishPoints(){
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 550, 100, 34, 34, "EBV"));
}
