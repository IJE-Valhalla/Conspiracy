#include "stage_one.hpp"

using namespace engine;

#define PAPERQUANTITY 2
#define STAGENUMBER 1
StageOne::StageOne(int id, std::string newTiledFile) : GameScene (id, newTiledFile, "assets/sounds/TEMA1.wav"){

}

void StageOne::createGuards(){
    std::pair <std::string, int> wayOne1 ("right", 470);
    std::pair <std::string, int> wayTwo1 ("up", HEADER_SIZE + 30);
    std::pair <std::string, int> wayThree1 ("left", 220);
    std::pair <std::string, int> wayFour1 ("down", HEADER_SIZE + 120);
    std::pair <std::string, int> wayFive1 ("right", 470);

    Guard * guard1 = new Guard("assets/sprites/seguranca_sheet.png", 220, HEADER_SIZE + 120, 18, 35, "right", 2, 15);
    guard1->addWay(1, wayOne1);
    guard1->addWay(2, wayTwo1);
    guard1->addWay(3, wayThree1);
    guard1->addWay(4, wayFour1);
    guard1->addWay(5, wayFive1);

    gameObjectsList.push_back(guard1);

    std::pair <std::string, int> wayOne2 ("right", 920);
    std::pair <std::string, int> wayTwo2 ("down", HEADER_SIZE + 550);
    std::pair <std::string, int> wayThree2 ("left", 860);
    std::pair <std::string, int> wayFour2 ("up", HEADER_SIZE + 50);
    std::pair <std::string, int> wayFive2 ("right", 880);
    std::pair <std::string, int> waySix2 ("down", HEADER_SIZE + 550);

    Guard * guard2 = new Guard("assets/sprites/seguranca_sheet.png", 880, HEADER_SIZE + 50, 18, 35, "down", 2, 15);
    guard2->addWay(1, wayOne2);
    guard2->addWay(2, wayTwo2);
    guard2->addWay(3, wayThree2);
    guard2->addWay(4, wayFour2);

    guard2->addWay(5, wayOne2);
    guard2->addWay(6, wayTwo2);
    guard2->addWay(7, wayThree2);
    guard2->addWay(8, wayFour2);
    guard2->addWay(9, wayFive2);
    guard2->addWay(10, waySix2);

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
    gameObjectsList.push_back(new FinishPoint("assets/sprites/cenary/tapete.png", 550, 100, 34, 34, "EBV"));
}
