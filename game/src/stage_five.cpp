#include "stage_five.hpp"
#include "chair.hpp"

using namespace engine;
#define PAPERQUANTITY 5
#define STAGENUMBER 5

StageFive::StageFive(int id, std::string newTiledFile) : GameScene (id, newTiledFile, "assets/sounds/TEMA5.wav"){

}

void StageFive::createGuards(){

    Guard * guard1 = new Guard(800, HEADER_SIZE + 430, 18, 35, "down", 10);
    guard1->addWay(1, "down", 900);
    guard1->addWay(2, "up", 450);

    gameObjectsList.push_back(guard1);

    Guard * guard2 = new Guard(800, HEADER_SIZE + 465, 18, 35, "right", 10);
    guard2->addWay(1, "right", 900);
    guard2->addWay(2, "left", 450);

    gameObjectsList.push_back(guard2);

    Guard * guard3 = new Guard(800, HEADER_SIZE + 100, 18, 35, "right", 10);
    guard3->addWay(1, "right", 900);
    guard3->addWay(2, "left", 450);

    gameObjectsList.push_back(guard3);

    //HIDDEN CAMERAS SWITCHES, CAMERAS CAN'T BE DISABLED IN STAGE 5

    CameraSwitch* cameraSwitch1 = new CameraSwitch(1000, 1000, "right");
    CameraSwitch* cameraSwitch2 = new CameraSwitch(1000, 1000, "right");
    CameraSwitch* cameraSwitch3 = new CameraSwitch(1000, 1000, "right");
    CameraSwitch* cameraSwitch4 = new CameraSwitch(1000, 1000, "right");
    CameraSwitch* cameraSwitch5 = new CameraSwitch(1000, 1000, "right");
    CameraSwitch* cameraSwitch6 = new CameraSwitch(1000, 1000, "right");

    CameraLever* cameraLever1 = new CameraLever(100,140,"right");
    CameraLever* cameraLever2 = new CameraLever(100,160,"right");
    CameraLever* cameraLever3 = new CameraLever(100,180,"right");
    CameraLever* cameraLever4 = new CameraLever(180,140,"right");
    CameraLever* cameraLever5 = new CameraLever(180,160,"right");
    CameraLever* cameraLever6 = new CameraLever(180,180,"right");

    int camera_range = 200;
    int camera_angle = 35;
    int angleInc = 35;
    Camera* camera1 = new Camera(2,450,"upright", camera_angle, camera_range, -1);
    camera1->setStates(10, 80);
    CameraSystem* cameraSystem1 = new CameraSystem(camera1,cameraSwitch1, cameraLever1);

    gameObjectsList.push_back(cameraSystem1);

    Camera* camera2 = new Camera(435,340,"upleft", camera_angle, camera_range, 175);
    camera2->setStates(175-angleInc, 175+angleInc);
    CameraSystem* cameraSystem2 = new CameraSystem(camera2,cameraSwitch2, cameraLever2);

    gameObjectsList.push_back(cameraSystem2);

    Camera* camera3 = new Camera(600,340,"upright", camera_angle, camera_range, 10);
    camera3->setStates(10+angleInc, 10-angleInc);
    CameraSystem* cameraSystem3 = new CameraSystem(camera3,cameraSwitch3, cameraLever3);

    gameObjectsList.push_back(cameraSystem3);

    Camera* camera4 = new Camera(945,280,"left", camera_angle, camera_range+80, 200);
    camera4->setStates(200+angleInc, 200-angleInc);
    CameraSystem* cameraSystem4 = new CameraSystem(camera4,cameraSwitch4, cameraLever4);

    gameObjectsList.push_back(cameraSystem4);

    Camera* camera5 = new Camera(430,625,"upleft", camera_angle, camera_range, 135);
    camera5->setStates(135+angleInc, 135-angleInc);
    CameraSystem* cameraSystem5 = new CameraSystem(camera5,cameraSwitch5, cameraLever5);

    gameObjectsList.push_back(cameraSystem5);

    Camera* camera6 = new Camera(730,625,"upleft", camera_angle, camera_range, 135);
    camera6->setStates(135+angleInc, 135-angleInc);
    CameraSystem* cameraSystem6 = new CameraSystem(camera6,cameraSwitch6, cameraLever6);

    gameObjectsList.push_back(cameraSystem6);
}

void StageFive::createAliens(){
    std::pair <int, int> biluPos (480, 130);
    std::pair <int, int> etemerPos (780, 130);
    std::pair <int, int> varginhaPos (130, 130);

    player = new Player(biluPos, etemerPos, varginhaPos, PAPERQUANTITY, STAGENUMBER);
    gameObjectsList.push_back(player);
}

void StageFive::createDoorSystems(){
    std::pair<int,int> doorOnePosition (437, 540);
    std::pair<int,int> switchOnePosition (210, 510);

    std::pair<int,int> doorTwoPosition (737, 540);
    std::pair<int,int> switchTwoPosition (490, 390);

    std::pair<int,int> doorThreePosition (780, 201);
    std::pair<int,int> switchThreePosition (760, 350);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition, "LEFT"));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition, "LEFT"));
    gameObjectsList.push_back(new DoorSystem(doorThreePosition,switchThreePosition, "DOWN"));
}

void StageFive::createPapers(){
    gameObjectsList.push_back(new PaperTable("Paper", 880, 550, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 10, 560, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 530, 530, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 550, 100, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 650, 140, 60, 34));
}

void StageFive::createTables(){
    gameObjectsList.push_back(new Table(TABLEASSET, 890, 470, 60, 34));
    gameObjectsList.push_back(new Table(TABLEASSET, 828, 470, 60, 34));
}

void StageFive::createFinishPoints(){
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 130, 100, 34, 34, "V"));
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 480, 100, 34, 34, "B"));
    gameObjectsList.push_back(new FinishPoint(FINISHPOINTASSET, 780, 100, 34, 34, "E"));
}

void StageFive::createChairs(){
    gameObjectsList.push_back(new Chair(CHAIRASSET, 830, HEADER_SIZE + 540, 20, 16));
    gameObjectsList.push_back(new Chair(CHAIRASSET, 670, HEADER_SIZE + 140, 20, 16));
}
