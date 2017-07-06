#include "stage_five.hpp"

using namespace engine;

StageFive::StageFive(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageFive::createGuards(){
    std::pair <std::string, int> wayOne1 ("down", 900);
    std::pair <std::string, int> wayTwo1 ("up", 450);

    Guard * guard1 = new Guard("assets/sprites/seguranca_sheet.png", 800, HEADER_SIZE + 430, 18, 35, "down", 2, 10);
    guard1->addWay(1, wayOne1);
    guard1->addWay(2, wayTwo1);

    gameObjectsList.push_back(guard1);

    std::pair <std::string, int> wayOne2 ("right", 900);
    std::pair <std::string, int> wayTwo2 ("left", 450);

    Guard * guard2 = new Guard("assets/sprites/seguranca_sheet.png", 800, HEADER_SIZE + 490, 18, 35, "right", 2, 10);
    guard2->addWay(1, wayOne2);
    guard2->addWay(2, wayTwo2);

    gameObjectsList.push_back(guard2);

    std::pair <std::string, int> wayOne3 ("right", 900);
    std::pair <std::string, int> wayTwo3 ("left", 450);

    Guard * guard3 = new Guard("assets/sprites/seguranca_sheet.png", 800, HEADER_SIZE + 100, 18, 35, "right", 2, 10);
    guard3->addWay(1, wayOne3);
    guard3->addWay(2, wayTwo3);

    gameObjectsList.push_back(guard3);

    Camera* camera1 = new Camera(2,450,"upright");
    gameObjectsList.push_back(camera1);

    Camera* camera2 = new Camera(435,340,"upleft");
    gameObjectsList.push_back(camera2);

    Camera* camera3 = new Camera(600,340,"upright");
    gameObjectsList.push_back(camera3);

    Camera* camera4 = new Camera(945,205,"left");
    gameObjectsList.push_back(camera4);

    Camera* camera5 = new Camera(430,625,"upleft");
    gameObjectsList.push_back(camera5);

    Camera* camera6 = new Camera(730,625,"upleft");
    gameObjectsList.push_back(camera6);

}

void StageFive::createAliens(){
    std::pair <int, int> biluPos (480, 130);
    std::pair <int, int> etemerPos (780, 130);
    std::pair <int, int> varginhaPos (130, 130);

    player = new Player(biluPos, etemerPos, varginhaPos);
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
    gameObjectsList.push_back(new PaperTable("Paper", 880, 570, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 10, 580, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 530, 530, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 550, 100, 60, 34));
    gameObjectsList.push_back(new PaperTable("Paper", 650, 140, 60, 34));
}

void StageFive::createTables(){
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 890, 490, 60, 34));
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 828, 490, 60, 34));
}

void StageFive::createFinishPoints(){
    gameObjectsList.push_back(new FinishPoint("assets/sprites/cenary/tapete.png", 130, 100, 34, 34, "V"));
    gameObjectsList.push_back(new FinishPoint("assets/sprites/cenary/tapete.png", 480, 100, 34, 34, "B"));
    gameObjectsList.push_back(new FinishPoint("assets/sprites/cenary/tapete.png", 780, 100, 34, 34, "E"));
}
