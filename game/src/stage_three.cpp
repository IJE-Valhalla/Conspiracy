#include "stage_three.hpp"

using namespace engine;
#define PAPERQUANTITY 3
#define STAGENUMBER 3
StageThree::StageThree(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageThree::createGuards(){
    std::pair <std::string, int> wayOne1 ("right", 600);
    std::pair <std::string, int> wayTwo1 ("up", HEADER_SIZE + 30);
    std::pair <std::string, int> wayThree1 ("left", 30);
    std::pair <std::string, int> wayFour1 ("down", HEADER_SIZE + 180);
    std::pair <std::string, int> wayFive1 ("left", 30);

    Guard * guard1 = new Guard("assets/sprites/seguranca_sheet.png", 30, HEADER_SIZE + 180, 18, 35, "right", 2, 10);
    guard1->addWay(1, wayOne1);
    guard1->addWay(2, wayTwo1);
    guard1->addWay(3, wayThree1);
    guard1->addWay(4, wayFour1);
    guard1->addWay(5, wayFive1);

    gameObjectsList.push_back(guard1);

    std::pair <std::string, int> wayOne2 ("left", 450);
    std::pair <std::string, int> wayTwo2 ("down", HEADER_SIZE + 300);
    std::pair <std::string, int> wayThree2 ("right", 640);
    std::pair <std::string, int> wayFour2 ("down", HEADER_SIZE + 300);
    std::pair <std::string, int> wayFive2 ("right", 920);
    std::pair <std::string, int> waySix2 ("up", HEADER_SIZE + 50);
    std::pair <std::string, int> waySeven2 ("left", 770);
    std::pair <std::string, int> wayEight2 ("up", HEADER_SIZE + 50);
    std::pair <std::string, int> wayNine2 ("left", 770);

    Guard * guard2 = new Guard("assets/sprites/seguranca_sheet.png", 750, HEADER_SIZE + 50, 18, 35, "left", 2, 10);
    guard2->addWay(1, wayOne2);
    guard2->addWay(2, wayTwo2);
    guard2->addWay(3, wayThree2);
    guard2->addWay(4, wayFour2);
    guard2->addWay(5, wayFive2);
    guard2->addWay(6, waySix2);
    guard2->addWay(7, waySeven2);
    guard2->addWay(8, wayEight2);
    guard2->addWay(9, wayNine2);

    gameObjectsList.push_back(guard2);

    std::pair <std::string, int> wayOne3 ("right", 900);
    std::pair <std::string, int> wayTwo3 ("left", 300);

    Guard * guard3 = new Guard("assets/sprites/seguranca_sheet.png", 500, HEADER_SIZE + 420, 18, 35, "right", 2, 10);
    guard3->addWay(1, wayOne3);
    guard3->addWay(2, wayTwo3);

    gameObjectsList.push_back(guard3);

    std::pair <std::string, int> wayOne4 ("down", HEADER_SIZE + 600);
    std::pair <std::string, int> wayTwo4 ("right", 950);
    std::pair <std::string, int> wayThree4 ("up", HEADER_SIZE + 420);
    std::pair <std::string, int> wayFour4 ("left", 720);
    std::pair <std::string, int> wayFive4 ("down", HEADER_SIZE + 600);


    Guard * guard4 = new Guard("assets/sprites/seguranca_sheet.png", 720, HEADER_SIZE + 420, 18, 35, "up", 2, 10);
    guard4->addWay(1, wayOne4);
    guard4->addWay(2, wayTwo4);
    guard4->addWay(3, wayThree4);
    guard4->addWay(4, wayFour4);
    guard4->addWay(5, wayFive4);

    gameObjectsList.push_back(guard4);


    CameraSwitch* cameraSwitch1 = new CameraSwitch(460, 460, "right");
    Camera* camera1 = new Camera(350,425,"upleft",80,220,120);
    CameraSystem* cameraSystem1 = new CameraSystem(camera1,cameraSwitch1);

    gameObjectsList.push_back(cameraSystem1);


    CameraSwitch* cameraSwitch2 = new CameraSwitch(460, 100, "right");
    Camera* camera2 = new Camera(450,40,"left",80,180,235);
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
    gameObjectsList.push_back(new FinishPoint("assets/sprites/cenary/tapete_lateral.png", 940, 260, 34, 34, "EBV"));
}
