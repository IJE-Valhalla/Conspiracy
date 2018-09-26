#include "stage_two.hpp"

using namespace engine;
#define PAPERQUANTITY 3
#define STAGENUMBER 2
StageTwo::StageTwo(int id, std::string newTiledFile) : GameScene (id, newTiledFile, "assets/sounds/TEMA2.wav"){

}

void StageTwo::createGuards(){

    Guard * guard1 = new Guard(20, HEADER_SIZE + 120, 18, 35, "right", 10);
    guard1->addWay(1, "right", 300);
    guard1->addWay(2, "up", HEADER_SIZE + 30);
    guard1->addWay(3, "left", 20);
    guard1->addWay(4, "down", HEADER_SIZE + 120);
    guard1->addWay(5, "right", 300);

    gameObjectsList.push_back(guard1);

    Guard * guard2 = new Guard(750, HEADER_SIZE + 50, 18, 35, "down", 10);
    guard2->addWay(1, "left", 700);
    guard2->addWay(2, "down", HEADER_SIZE + 400);
    guard2->addWay(3, "right", 920);
    guard2->addWay(4, "up", HEADER_SIZE + 200);
    guard2->addWay(5, "left", 750);
    guard2->addWay(6, "up", HEADER_SIZE + 50);

    gameObjectsList.push_back(guard2);

    Guard * guard3 = new Guard(500, HEADER_SIZE + 200, 18, 35, "down", 10);
    guard3->addWay(1, "down", HEADER_SIZE + 430);
    guard3->addWay(2, "left", 300);
    guard3->addWay(3, "down", HEADER_SIZE + 500);
    guard3->addWay(4, "right", 650);
    guard3->addWay(5, "up", HEADER_SIZE + 300);
    guard3->addWay(6, "left", 520);
    guard3->addWay(7, "up", HEADER_SIZE + 210);
    guard3->addWay(8, "right", 650);
    guard3->addWay(9, "down", HEADER_SIZE + 350);
    guard3->addWay(10, "left", 300);
    guard3->addWay(11, "up", HEADER_SIZE + 210);
    guard3->addWay(12, "right", 505);
    guard3->addWay(13, "down", HEADER_SIZE + 210);


    gameObjectsList.push_back(guard3);

    CameraSwitch* cameraSwitch1 = new CameraSwitch(660, 500, "right");
    Camera* camera1 = new Camera(680,510,"right");
    CameraSystem* cameraSystem1 = new CameraSystem(camera1,cameraSwitch1);

    gameObjectsList.push_back(cameraSystem1);


    CameraSwitch* cameraSwitch2 = new CameraSwitch(942, 150, "right");
    Camera* camera2 = new Camera(942,250,"left", 80, 180, 200);

    CameraSystem* cameraSystem2 = new CameraSystem(camera2,cameraSwitch2);

    gameObjectsList.push_back(cameraSystem2);
}

void StageTwo::createAliens(){
    std::pair <int, int> biluPos (880, HEADER_SIZE + 550);
    std::pair <int, int> etemerPos (900, HEADER_SIZE + 550);
    std::pair <int, int> varginhaPos (920, HEADER_SIZE + 550);

    player = new Player(biluPos, etemerPos, varginhaPos, PAPERQUANTITY, STAGENUMBER);
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

void StageTwo::createFinishPoints(){
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 550, 100, 34, 34, "EB"));
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 250, 45, 34, 34, "V"));
}
