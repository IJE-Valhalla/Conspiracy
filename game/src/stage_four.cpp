#include "stage_four.hpp"
#include "chair.hpp"

using namespace engine;
#define PAPERQUANTITY 3
#define STAGENUMBER 4
StageFour::StageFour(int id, std::string newTiledFile) : GameScene (id, newTiledFile, "assets/sounds/TEMA4.wav"){

}

void StageFour::createGuards(){

    Guard * guard1 = new Guard(20, HEADER_SIZE + 400, 18, 35, "right", 10);
    guard1->addWay(1, "right", 220);
    guard1->addWay(2, "down", HEADER_SIZE + 700);
    guard1->addWay(3, "right", 600);
    guard1->addWay(4, "up", HEADER_SIZE + 300);
    guard1->addWay(5, "left", 300);
    guard1->addWay(6, "up", HEADER_SIZE + 400);
    guard1->addWay(7, "left", 220);

    gameObjectsList.push_back(guard1);

    Guard * guard2 = new Guard(750, HEADER_SIZE + 400, 18, 35, "left", 10);
    guard2->addWay(1, "left", 450);
    guard2->addWay(2, "right", 900);

    gameObjectsList.push_back(guard2);

    Guard * guard3 = new Guard(550, HEADER_SIZE + 420, 18, 35, "up", 10);
    guard3->addWay(1, "up", HEADER_SIZE + 200);
    guard3->addWay(2, "down", HEADER_SIZE + 420);
    guard3->addWay(3, "left", 300);
    guard3->addWay(4, "right", 550);
    guard3->addWay(5, "up", HEADER_SIZE + 200);

    gameObjectsList.push_back(guard3);

    Guard * guard4 = new Guard(750, HEADER_SIZE + 330, 18, 35, "right", 10);
    guard4->addWay(1, "left", 450);
    guard4->addWay(2, "right", 900);

    gameObjectsList.push_back(guard4);

    Guard * guard5 = new Guard(650, HEADER_SIZE + 330, 18, 35, "down", 10);
    guard5->addWay(1, "down", HEADER_SIZE + 600);
    guard5->addWay(2, "up", HEADER_SIZE + 300);

    gameObjectsList.push_back(guard5);

    Guard * guard6 = new Guard(350, HEADER_SIZE + 230, 18, 35, "down", 10);
    guard6->addWay(1, "up", HEADER_SIZE + 80);
    guard6->addWay(2, "left", 20);
    guard6->addWay(3, "right",350);
    guard6->addWay(4, "down", HEADER_SIZE + 300);

    gameObjectsList.push_back(guard6);

    Guard * guard7 = new Guard(400, HEADER_SIZE + 30, 18, 35, "down", 10);
    guard7->addWay(1, "down", HEADER_SIZE + 200);
    guard7->addWay(2, "right", 800);
    guard7->addWay(3, "left", 400);
    guard7->addWay(4, "up", HEADER_SIZE + 30);

    gameObjectsList.push_back(guard7);


    CameraSwitch* cameraSwitch1 = new CameraSwitch(205, 80, "right");
    Camera* camera1 = new Camera(217,70,"right", 70, 220, 295);
    CameraSystem* cameraSystem1 = new CameraSystem(camera1,cameraSwitch1);

    gameObjectsList.push_back(cameraSystem1);

    CameraSwitch* cameraSwitch2 = new CameraSwitch(945, 380, "right");
    Camera* camera2 = new Camera(945,220,"left", 60, 300, 190);
    CameraSystem* cameraSystem2 = new CameraSystem(camera2,cameraSwitch2);

    gameObjectsList.push_back(cameraSystem2);

    CameraSwitch* cameraSwitch3 = new CameraSwitch(5, 420, "right");
    Camera* camera3 = new Camera(5,370,"right",55,400,338);
    CameraSystem* cameraSystem3 = new CameraSystem(camera3,cameraSwitch3);

    gameObjectsList.push_back(cameraSystem3);


    CameraSwitch* cameraSwitch4 = new CameraSwitch(185, 600, "right");
    Camera* camera4 = new Camera(197,625,"upright");
    CameraSystem* cameraSystem4 = new CameraSystem(camera4,cameraSwitch4);

    gameObjectsList.push_back(cameraSystem4);

}

void StageFour::createAliens(){
    std::pair <int, int> biluPos (40, HEADER_SIZE + 290);
    std::pair <int, int> etemerPos (35, HEADER_SIZE + 270);
    std::pair <int, int> varginhaPos (30, HEADER_SIZE + 310);


    player = new Player(biluPos, etemerPos, varginhaPos, PAPERQUANTITY, STAGENUMBER);

    gameObjectsList.push_back(player);
}

void StageFour::createDoorSystems(){
    std::pair<int,int> doorOnePosition (780, HEADER_SIZE + 120);
    std::pair<int,int> switchOnePosition (880, HEADER_SIZE + 300);

    std::pair<int,int> doorTwoPosition (163, HEADER_SIZE + 500);
    std::pair<int,int> switchTwoPosition (460, HEADER_SIZE + 350);

    std::pair<int,int> doorThreePosition (780, HEADER_SIZE + 220);
    std::pair<int,int> switchThreePosition (20, HEADER_SIZE + 50);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "DOWN"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "RIGHT"));
    gameObjectsList.push_back(new DoorSystem(doorThreePosition,switchThreePosition, "DOWN"));
}

void StageFour::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 880, HEADER_SIZE + 60, 60, 24));
    gameObjectsList.push_back(new PaperTable("Paper", 880, HEADER_SIZE + 530, 60, 24));
    gameObjectsList.push_back(new PaperTable("Paper", 610, HEADER_SIZE + 280, 60, 24));
}

void StageFour::createTables(){
    gameObjectsList.push_back(new Table(TABLEASSET, 890, HEADER_SIZE + 370, 60, 24));
    gameObjectsList.push_back(new Table(TABLEASSET, 828, HEADER_SIZE + 370, 60, 24));

    gameObjectsList.push_back(new Table(TABLEASSET, 890, HEADER_SIZE + 470, 60, 24));
    gameObjectsList.push_back(new Table(TABLEASSET, 828, HEADER_SIZE + 470, 60, 24));
}

void StageFour::createFinishPoints(){
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 100, 595, 34, 34, "V"));
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 540, 595, 34, 34, "B"));
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 740, 595, 34, 34, "E"));
}

void StageFour::createChairs(){
    gameObjectsList.push_back(new Chair(CHAIRASSET, 800, HEADER_SIZE + 380, 20, 16));
    gameObjectsList.push_back(new Chair(CHAIRASSET, 800, HEADER_SIZE + 480, 20, 16));
    gameObjectsList.push_back(new Chair(CHAIRASSET, 380, HEADER_SIZE + 400, 20, 16));
    gameObjectsList.push_back(new Chair(CHAIRASSET, 300, HEADER_SIZE + 250, 20, 16));
}
