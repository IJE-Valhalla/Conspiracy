#include "game_scene.hpp"
#include "player.hpp"
#include "scene.hpp"
#include "engine.hpp"
#include "wall.hpp"
#include "ground.hpp"
#include "collision_manager.hpp"
#include "guard.hpp"
#include "paper.hpp"
#include "door_system.hpp"
#include "audio.hpp"
#include "table.hpp"
#include "paper_table.hpp"
#include "chair.hpp"


#include <typeinfo>
#include <iostream>

#include "line.hpp"

using namespace engine;

GameScene::GameScene(int id, std::string newTiledFile) : Scene(id){
    tiledFile = newTiledFile;
    skipTimer = new Timer();
    stageTimer = new Timer();
    actualPapers = 0;
}

GameScene::GameScene(int id, std::string newTiledFile, std::string audioFile) : Scene(id){
    if(audioFile == "assets/sounds/TEMA3.wav"){
        background_music = new Audio(audioFile, "MUSIC", 55);
    }else{
        background_music = new Audio(audioFile, "MUSIC", 75);
    }
    tiledFile = newTiledFile;
    skipTimer = new Timer();
    stageTimer = new Timer();
    actualPapers = 0;
}

void GameScene::draw(){
        for(auto gameObject : gameObjectsList) {
                (*gameObject).draw();
        }
}

void GameScene::update(double timeElapsed){
    if(!player->isDead()){
        for(auto gameObject : gameObjectsList) {
                if(typeid(gameObject) != typeid(Player)){
                    (*gameObject).update(timeElapsed);
                }
        }
    }
    verifyWinOrLose();
}

void GameScene::verifyWinOrLose(){
        bool allPapersEdited = true;
        std::vector<Guard *> guards;
        int countPapers = 0;
        for(auto gameObject : gameObjectsList) {
                if(typeid(*gameObject) == typeid(Guard)) {
                        guards.push_back((Guard *)(gameObject));
                }else if(typeid(*gameObject) == typeid(PaperTable)) {
                        if(!(((PaperTable*)(gameObject))->getPaper())->isEdited()) {
                            allPapersEdited = false;
                        }else{
                            countPapers++;
                        }
                }
        }
        if(countPapers >= actualPapers){
            player->updatePaperQuantity(countPapers);
            actualPapers = countPapers;
        }
        for(Guard * guard : guards) {
            guard->verifyDistance(player->getVarginha());
            guard->verifyDistance(player->getBilu());
            ((Etemer *)(player->getEtemer()))->verifyDistance(guard);
        }
    if((Etemer *)(player->getEtemer())->isInPosition() &&
      (Bilu*)(player->getBilu())->isInPosition() &&
      (Varginha*)(player->getVarginha())->isInPosition()){
          aliensInPosition = true;
      }

    if(!player->isDead()){
        stageTimer->step();
    }
    if(player->isDead()){
        if(stageTimer->elapsed_time() >= 2500){
            getSceneManager()->loadScene(6);
        }

    }else if((allPapersEdited && aliensInPosition) || (InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_K) && skipTimer->total_elapsed_time() >= 500)){
        if(getSceneManager()->getCurrentSceneId() == 5){
            getSceneManager()->loadScene(9);
        }else{
            getSceneManager()->loadScene(7);
        }
    }
}

void GameScene::initializeColliders(){
    for(auto gameObject: gameObjectsList){
        if(typeid(*gameObject) == typeid(Wall)){
            CollisionManager::instance.addWall(gameObject);
        }else if(typeid(*gameObject) == typeid(Guard)){
            CollisionManager::instance.addGuard(gameObject);
            CollisionManager::instance.addGuardFieldOfVision(((Guard*)gameObject)->getFieldOfVision());
        }else if(typeid(*gameObject) == typeid(CameraSystem)){
            CollisionManager::instance.addCameraFieldOfVision(((CameraSystem*)gameObject)->getCamera()->getFieldOfVision());
            CollisionManager::instance.addCameraSwitch(((CameraSystem*)gameObject)->getCameraSwitch());
            CollisionManager::instance.addCameraLever(((CameraSystem*)gameObject)->getCameraLever());
        }else if(typeid(*gameObject) == typeid(PaperTable)){
            CollisionManager::instance.addPaper(((PaperTable*)(gameObject))->getPaper());
            CollisionManager::instance.addWall(((PaperTable*)(gameObject))->getTable());
        }else if(typeid(*gameObject) == typeid(DoorSystem)){
            CollisionManager::instance.addDoor(((DoorSystem*)(gameObject))->getDoor());
            CollisionManager::instance.addSwitch(((DoorSystem*)(gameObject))->getSwitch());
            CollisionManager::instance.addWall(((DoorSystem*)(gameObject))->getTable());
        }else if(typeid(*gameObject) == typeid(Table)){
            CollisionManager::instance.addWall(((Table*)(gameObject)));
        }else if(typeid(*gameObject) == typeid(Chair)) {
            CollisionManager::instance.addChair(gameObject);
        }else if(typeid(*gameObject) == typeid(FinishPoint)){
            CollisionManager::instance.addFinishPoint(gameObject);
        }
    }
}

void GameScene::load(){
    background_music->play(-1);
    aliensInPosition = false;
    stageTimer->start();
    skipTimer->start();
    skipTimer->step();

    createGround();
    createGameBorders();
    createCenary();
    createAliens();
    createGuards();
    createDoorSystems();
    createPapers();
    createTables();
    createChairs();
    createFinishPoints();

    initializeColliders();
    AnimationManager::instance.setBackgroundColor(Color{100,100,100, 125});

}

void GameScene::unload(){
    CollisionManager::instance.resetLists();
    actualPapers = 0;
    for(GameObject* object: gameObjectsList){
        free(object);
    }
    gameObjectsList.clear();
}

void GameScene::createTables(){}

void GameScene::createChairs(){}

void GameScene::createGameBorders(){
        for(int i=0; i<=960; i+=5) {
                gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", i, HEADER_SIZE + 0, 5, 20));
                gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", i, HEADER_SIZE + 595, 5, 5));
        }
        for(int j=0; j<=600; j+=5) {
                gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 955, HEADER_SIZE + j, 5, 5));
                gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 0, HEADER_SIZE + j, 5, 5));
        }
}

void GameScene::createGround(){
        for(int i=0; i<=960; i+=20) {
                for(int j=0; j<=600; j+=20) {
                        gameObjectsList.push_back(new Ground("assets/sprites/cenary/chao.png", i, HEADER_SIZE + j, 20, 20));
                }
        }
}

void GameScene::createCenary(){
    std::ifstream tile_file;
    tile_file.open(tiledFile);
    if(tile_file.is_open()) {
        char c;
        int compare;
        for(int i=0; i<=600; i+=20) {
            for(int j=0; j<=960; j+=20) {
                tile_file.get(c);
                compare = c-48;
                switch(compare) {
                    case 1: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", j, HEADER_SIZE + i+25, 20, 40)); break;

                    case 2: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, HEADER_SIZE + i, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, HEADER_SIZE + i+5, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, HEADER_SIZE + i+10, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, HEADER_SIZE + i+15, 5, 30));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, HEADER_SIZE + i-5, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, HEADER_SIZE + i-10, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, HEADER_SIZE + i-15, 0, 0)); break;

                    case 3: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, HEADER_SIZE + i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+5, HEADER_SIZE + i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+10, HEADER_SIZE + i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, HEADER_SIZE +i+15, 5, 5)); break;

                    case 4: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, HEADER_SIZE + i, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, HEADER_SIZE + i+5, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, HEADER_SIZE + i+10, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, HEADER_SIZE + i+15, 5, 30));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, HEADER_SIZE + i-5, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, HEADER_SIZE + i-10, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, HEADER_SIZE + i-15, 0, 0)); break;

                    case 5: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_door.png", j+15, HEADER_SIZE + i-20, 5, 60)); break;

                    case 6: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_door.png", j, HEADER_SIZE + i-20, 5, 60));break;
                }
            }
        }
    }
}
