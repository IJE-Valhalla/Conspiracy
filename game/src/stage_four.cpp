#include "stage_four.hpp"

using namespace engine;
#define PAPERQUANTITY 3
#define STAGENUMBER 4
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

    std::pair <std::string, int> wayOne4 ("left", 450);
    std::pair <std::string, int> wayTwo4 ("right", 900);

    Guard * guard4 = new Guard("assets/sprites/seguranca_sheet.png", 750, HEADER_SIZE + 330, 18, 35, "right", 2, 10);
    guard4->addWay(1, wayOne4);
    guard4->addWay(2, wayTwo4);

    gameObjectsList.push_back(guard4);

    std::pair <std::string, int> wayOne5 ("down", HEADER_SIZE + 600);
    std::pair <std::string, int> wayTwo5 ("up", HEADER_SIZE + 300);

    Guard * guard5 = new Guard("assets/sprites/seguranca_sheet.png", 650, HEADER_SIZE + 330, 18, 35, "down", 2, 10);
    guard5->addWay(1, wayOne5);
    guard5->addWay(2, wayTwo5);

    gameObjectsList.push_back(guard5);

    std::pair <std::string, int> wayOne6 ("up", HEADER_SIZE + 80);
    std::pair <std::string, int> wayTwo6 ("left", 20);
    std::pair <std::string, int> wayThree6 ("right",350);
    std::pair <std::string, int> wayFour6 ("down", HEADER_SIZE + 300);

    Guard * guard6 = new Guard("assets/sprites/seguranca_sheet.png", 350, HEADER_SIZE + 230, 18, 35, "down", 2, 10);
    guard6->addWay(1, wayOne6);
    guard6->addWay(2, wayTwo6);
    guard6->addWay(3, wayThree6);
    guard6->addWay(4, wayFour6);

    gameObjectsList.push_back(guard6);

    std::pair <std::string, int> wayOne7 ("down", HEADER_SIZE + 200);
    std::pair <std::string, int> wayTwo7 ("right", 800);
    std::pair <std::string, int> wayThree7 ("left", 400);
    std::pair <std::string, int> wayFour7 ("up", HEADER_SIZE + 30);

    Guard * guard7 = new Guard("assets/sprites/seguranca_sheet.png", 400, HEADER_SIZE + 30, 18, 35, "down", 2, 10);
    guard7->addWay(1, wayOne7);
    guard7->addWay(2, wayTwo7);
    guard7->addWay(3, wayThree7);
    guard7->addWay(4, wayFour7);

    gameObjectsList.push_back(guard7);


    CameraSwitch* cameraSwitch1 = new CameraSwitch(205, 80, "right");
    Camera* camera1 = new Camera(217,44,"right", 70, 220, 295);
    CameraSystem* cameraSystem1 = new CameraSystem(camera1,cameraSwitch1);

    gameObjectsList.push_back(cameraSystem1);

    CameraSwitch* cameraSwitch2 = new CameraSwitch(945, 380, "right");
    Camera* camera2 = new Camera(945,170,"left", 60, 300, 215);
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
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 890, HEADER_SIZE + 370, 60, 24));
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 828, HEADER_SIZE + 370, 60, 24));

    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 890, HEADER_SIZE + 470, 60, 24));
    gameObjectsList.push_back(new Table("assets/sprites/mesa.png", 828, HEADER_SIZE + 470, 60, 24));
}

void StageFour::createFinishPoints(){
    gameObjectsList.push_back(new FinishPoint("assets/sprites/cenary/tapete.png", 100, 595, 34, 34, "V"));
    gameObjectsList.push_back(new FinishPoint("assets/sprites/cenary/tapete.png", 540, 595, 34, 34, "B"));
    gameObjectsList.push_back(new FinishPoint("assets/sprites/cenary/tapete.png", 740, 595, 34, 34, "E"));
}
