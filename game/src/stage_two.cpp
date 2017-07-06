#include "stage_two.hpp"

using namespace engine;

StageTwo::StageTwo(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageTwo::createGuards(){
    std::pair <std::string, int> wayOne ("right", 480);
    std::pair <std::string, int> wayTwo ("up", HEADER_SIZE + 20);
    std::pair <std::string, int> wayThree ("left", 220);
    std::pair <std::string, int> wayFour ("down", HEADER_SIZE + 120);

    Guard * guard = new Guard("assets/sprites/seguranca_sheet.png", 220, HEADER_SIZE + 120, 18, 35, "right", 10);
    guard->addWay(1, wayOne);
    guard->addWay(2, wayTwo);
    guard->addWay(3, wayThree);
    guard->addWay(4, wayFour);

    Camera* camera1 = new Camera(680,510,"right");
    gameObjectsList.push_back(camera1);

    Camera* camera2 = new Camera(942,195,"left");
    gameObjectsList.push_back(camera2);

    gameObjectsList.push_back(guard);
}

void StageTwo::createAliens(){
    std::pair <int, int> biluPos (880, HEADER_SIZE + 550);
    std::pair <int, int> etemerPos (900, HEADER_SIZE + 550);
    std::pair <int, int> varginhaPos (920, HEADER_SIZE + 550);

    player = new Player(biluPos, etemerPos, varginhaPos);
    gameObjectsList.push_back(player);
}

void StageTwo::createDoorSystems(){
    std::pair<int,int> doorOnePosition (163, HEADER_SIZE + 257);
    std::pair<int,int> switchOnePosition (610, HEADER_SIZE + 50);

    std::pair<int,int> doorTwoPosition (163, HEADER_SIZE + 497);
    std::pair<int,int> switchTwoPosition (800, HEADER_SIZE + 50);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "RIGHT"));
}

void StageTwo::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 30, HEADER_SIZE + 250, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 350, HEADER_SIZE + 170, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 30, HEADER_SIZE + 490, 60, 34));
}
