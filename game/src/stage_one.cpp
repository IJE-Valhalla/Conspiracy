#include "stage_one.hpp"

using namespace engine;

StageOne::StageOne(int id, std::string newTiledFile) : GameScene (id, newTiledFile){

}

void StageOne::createGuards(){
    std::pair <std::string, int> wayOne ("right", 480);
    std::pair <std::string, int> wayTwo ("up", HEADER_SIZE + 30);
    std::pair <std::string, int> wayThree ("left", 220);
    std::pair <std::string, int> wayFour ("down", HEADER_SIZE + 120);

    Guard * guard = new Guard("assets/sprites/seguranca_sheet.png", 220, HEADER_SIZE + 120, 18, 35, "right", 10);
    guard->addWay(1, wayOne);
    guard->addWay(2, wayTwo);
    guard->addWay(3, wayThree);
    guard->addWay(4, wayFour);

    CameraLever* cameraLever = new CameraLever(120, 530, "right");
    CameraSwitch* cameraSwitch = new CameraSwitch(100, 530, "right");
    Camera* camera = new Camera(130,530,"right");
    camera->setStates(0,270);
    CameraSystem* cameraSystem = new CameraSystem(camera,cameraSwitch,cameraLever);

    gameObjectsList.push_back(cameraSystem);

    // gameObjectsList.push_back(camera);
    // gameObjectsList.push_back(cameraSwitch);
    // gameObjectsList.push_back(cameraLever);

    gameObjectsList.push_back(guard);
}

void StageOne::createAliens(){
    std::pair <int, int> biluPos (10, HEADER_SIZE + 500);
    std::pair <int, int> etemerPos (30, HEADER_SIZE + 510);
    std::pair <int, int> varginhaPos (50, HEADER_SIZE + 500);

    player = new Player(biluPos, etemerPos, varginhaPos);

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
