#include "stage_four.hpp"

using namespace engine;

StageFour::StageFour(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageFour::createGuards(){
    std::pair <std::string, int> wayOne1 ("right", 220);
    std::pair <std::string, int> wayTwo1 ("down", HEADER_SIZE + 700);
    std::pair <std::string, int> wayThree1 ("right", 600);
    std::pair <std::string, int> wayFour1 ("up", HEADER_SIZE + 300);
    std::pair <std::string, int> wayFive1 ("left", 300);
    std::pair <std::string, int> waySix1 ("up", HEADER_SIZE + 400);
    std::pair <std::string, int> waySeven1 ("left", 220);


    Guard * guard1 = new Guard("assets/sprites/seguranca_sheet.png", 20, HEADER_SIZE + 400, 18, 35, "right", 2, 10);
    guard1->addWay(1, wayOne1);
    guard1->addWay(2, wayTwo1);
    guard1->addWay(3, wayThree1);
    guard1->addWay(4, wayFour1);
    guard1->addWay(5, wayFive1);
    guard1->addWay(6, waySix1);
    guard1->addWay(7, waySeven1);

    gameObjectsList.push_back(guard1);

    std::pair <std::string, int> wayOne2 ("left", 450);
    std::pair <std::string, int> wayTwo2 ("right", 900);

    Guard * guard2 = new Guard("assets/sprites/seguranca_sheet.png", 750, HEADER_SIZE + 400, 18, 35, "left", 2, 10);
    guard2->addWay(1, wayOne2);
    guard2->addWay(2, wayTwo2);

    gameObjectsList.push_back(guard2);

    std::pair <std::string, int> wayOne3 ("up", HEADER_SIZE + 200);
    std::pair <std::string, int> wayTwo3 ("down", HEADER_SIZE + 420);
    std::pair <std::string, int> wayThree3 ("left", 300);
    std::pair <std::string, int> wayFour3 ("right", 550);
    std::pair <std::string, int> wayFive3 ("up", HEADER_SIZE + 200);


    Guard * guard3 = new Guard("assets/sprites/seguranca_sheet.png", 550, HEADER_SIZE + 420, 18, 35, "up", 2, 10);
    guard3->addWay(1, wayOne3);
    guard3->addWay(2, wayTwo3);
    guard3->addWay(3, wayThree3);
    guard3->addWay(4, wayFour3);
    guard3->addWay(5, wayFive3);

    gameObjectsList.push_back(guard3);

    std::pair <std::string, int> wayOne4 ("right", 900);
    std::pair <std::string, int> wayTwo4 ("left", 450);

    Guard * guard4 = new Guard("assets/sprites/seguranca_sheet.png", 750, HEADER_SIZE + 330, 18, 35, "left", 2, 10);
    guard4->addWay(1, wayOne4);
    guard4->addWay(2, wayTwo4);

    gameObjectsList.push_back(guard4);

    Camera* camera1 = new Camera("assets/sprites/camera(11X8).png",217,40,11,8, "right");
    gameObjectsList.push_back(camera1);

    Camera* camera2 = new Camera("assets/sprites/camera(11X8).png",945,170,11,8, "left");
    gameObjectsList.push_back(camera2);

    Camera* camera3 = new Camera("assets/sprites/camera(11X8).png",2,370,11,8, "right");
    gameObjectsList.push_back(camera3);

    Camera* camera4 = new Camera("assets/sprites/camera(11X8).png",197,625,11,8, "upright");
    gameObjectsList.push_back(camera4);
}

void StageFour::createAliens(){
    std::pair <int, int> biluPos (40, HEADER_SIZE + 290);
    std::pair <int, int> etemerPos (35, HEADER_SIZE + 270);
    std::pair <int, int> varginhaPos (30, HEADER_SIZE + 310);

    player = new Player(biluPos, etemerPos, varginhaPos);
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
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 890, HEADER_SIZE + 370, 60, 24));
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 828, HEADER_SIZE + 370, 60, 24));

    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 890, HEADER_SIZE + 470, 60, 24));
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 828, HEADER_SIZE + 470, 60, 24));
}
