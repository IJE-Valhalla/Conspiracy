#include "stage_three.hpp"
#include "chair.hpp"

using namespace engine;
#define PAPERQUANTITY 3
#define STAGENUMBER 3
StageThree::StageThree(int id, std::string newTiledFile) : GameScene (id, newTiledFile, "assets/sounds/TEMA3.wav"){

}

void StageThree::createGuards(){

    Guard * guard1 = new Guard(30, HEADER_SIZE + 180, 18, 35, "right", 10);
    guard1->addWay(1, "right", 600);
    guard1->addWay(2, "up", HEADER_SIZE + 30);
    guard1->addWay(3, "left", 30);
    guard1->addWay(4, "down", HEADER_SIZE + 180);
    guard1->addWay(5, "left", 30);

    gameObjectsList.push_back(guard1);

    Guard * guard2 = new Guard(750, HEADER_SIZE + 50, 18, 35, "left", 10);
    guard2->addWay(1, "left", 450);
    guard2->addWay(2, "down", HEADER_SIZE + 300);
    guard2->addWay(3, "right", 640);
    guard2->addWay(4, "down", HEADER_SIZE + 300);
    guard2->addWay(5, "right", 920);
    guard2->addWay(6, "up", HEADER_SIZE + 50);
    guard2->addWay(7, "left", 770);
    guard2->addWay(8, "up", HEADER_SIZE + 50);
    guard2->addWay(9, "left", 770);

    gameObjectsList.push_back(guard2);

    Guard * guard3 = new Guard(500, HEADER_SIZE + 420, 18, 35, "right", 10);
    guard3->addWay(1, "right", 900);
    guard3->addWay(2, "left", 300);

    gameObjectsList.push_back(guard3);

    CameraSwitch* cameraSwitch1 = new CameraSwitch(460, 460, "right");
    Camera* camera1 = new Camera(350,425,"upleft",80,220,120);
    CameraSystem* cameraSystem1 = new CameraSystem(camera1,cameraSwitch1);

    gameObjectsList.push_back(cameraSystem1);


    CameraSwitch* cameraSwitch2 = new CameraSwitch(460, 100, "right");
    Camera* camera2 = new Camera(220,70,"right",80,300,320);
    CameraSystem* cameraSystem2 = new CameraSystem(camera2,cameraSwitch2);

    gameObjectsList.push_back(cameraSystem2);
}

void StageThree::createAliens(){
    std::pair <int, int> biluPos (280, HEADER_SIZE + 560);
    std::pair <int, int> etemerPos (300, HEADER_SIZE + 560);
    std::pair <int, int> varginhaPos (575, HEADER_SIZE + 550);

    player = new Player(biluPos, etemerPos, varginhaPos, PAPERQUANTITY, STAGENUMBER);
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

void StageThree::createFinishPoints(){
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 940, 260, 34, 34, "EBV"));
}

void StageThree::createChairs(){
    gameObjectsList.push_back(new Chair(CHAIRASSET, 300, HEADER_SIZE + 480, 20, 16));
    gameObjectsList.push_back(new Chair(CHAIRASSET, 750, HEADER_SIZE + 120, 20, 16));
}
