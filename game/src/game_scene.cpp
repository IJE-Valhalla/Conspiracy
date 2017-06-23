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


#include <typeinfo>
#include <iostream>

using namespace engine;

GameScene::GameScene(int id) : Scene(id){

}

GameScene::~GameScene(){}

void GameScene::draw(){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).draw();
    }
}

void GameScene::update(double timeElapsed){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).update(timeElapsed);
    }
    verifyWinOrLose();
}

void GameScene::verifyWinOrLose(){
    bool allPapersEdited = true;
    std::vector<Guard *> guards;
    Player * player = NULL;
    for(auto gameObject : gameObjectsList){
        if(typeid(*gameObject) == typeid(Guard)){
            guards.push_back((Guard *)(gameObject));
        }else if(typeid(*gameObject) == typeid(Paper)){
            if(!((Paper*)(gameObject))->isEdited()){
                allPapersEdited = false;
            }
        }else if(typeid(*gameObject) == typeid(Player)){
            player = (Player *)(gameObject);
        }
    }

    for(Guard * guard : guards){
        guard->verifyDistance(player->getVarginha());
        guard->verifyDistance(player->getBilu());
    }

    if(player->isDead()){
        getSceneManager()->loadScene(2);
    }else if(allPapersEdited){
        getSceneManager()->loadScene(3);
    }

}

void GameScene::load(){
    Audio background_music = Audio("assets/sounds/tema1demo.wav", "MUSIC", 50);
    background_music.play(-1);

    createGround();
    createGameBorders();
    createCenary();
    createAliens();
    createGuards();
    createDoorSystems();
    createPapers();

    initializeColliders();

}

void GameScene::unload(){
    CollisionManager::instance.resetLists();
    gameObjectsList.clear();
}

void GameScene::initializeColliders(){
    for(auto gameObject: gameObjectsList){
        if(typeid(*gameObject) == typeid(Wall)){
            CollisionManager::instance.addWall(gameObject);
        }else if(typeid(*gameObject) == typeid(Guard)){
            CollisionManager::instance.addEnemy(gameObject);
        }else if(typeid(*gameObject) == typeid(Paper)){
            CollisionManager::instance.addPaper(gameObject);
        }else if(typeid(*gameObject) == typeid(DoorSystem)){
            CollisionManager::instance.addDoor(((DoorSystem*)(gameObject))->getDoor());
            CollisionManager::instance.addSwitch(((DoorSystem*)(gameObject))->getSwitch());
        }
    }
}

void GameScene::createAliens(){
    std::pair <int, int> biluPos (10, 500);
    std::pair <int, int> etemerPos (30, 510);
    std::pair <int, int> varginhaPos (50, 500);

    gameObjectsList.push_back(new Player(biluPos, etemerPos, varginhaPos));
}

void GameScene::createGuards(){
    std::pair <std::string, int> wayOne ("right", 480);
    std::pair <std::string, int> wayTwo ("up", 20);
    std::pair <std::string, int> wayThree ("left", 220);
    std::pair <std::string, int> wayFour ("down", 120);

    Guard * guard = new Guard("assets/sprites/seguranca_sheet.png", 220, 120, 18, 35, "right");
    guard->addWay(1, wayOne);
    guard->addWay(2, wayTwo);
    guard->addWay(3, wayThree);
    guard->addWay(4, wayFour);

    gameObjectsList.push_back(guard);
}

void GameScene::createDoorSystems(){
    std::pair<int,int> doorOnePosition (360, 240);
    std::pair<int,int> switchOnePosition (150, 150);


    std::pair<int,int> doorTwoPosition (660, 381);
    std::pair<int,int> switchTwoPosition (400, 530);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition));
}

void GameScene::createPapers(){
    gameObjectsList.push_back(new Paper("assets/sprites/papeis(19X21).png", 100,300, 19, 21));
    gameObjectsList.push_back(new Paper("assets/sprites/papeis(19X21).png", 800,300, 19, 21));
}

void GameScene::createGameBorders(){
    for(int i=0; i<=960; i+=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", i, 0, 5, 5));
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", i, 595, 5, 5));
    }
    for(int j=0; j<=600; j+=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 955, j, 5, 5));
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 0, j, 5, 5));
    }
}

void GameScene::createGround(){
    for(int i=0; i<=960; i+=20){
        for(int j=0; j<=600; j+=20){
            gameObjectsList.push_back(new Ground("assets/sprites/cenary/chao.png", i, j, 20, 20));
        }
    }
}

void GameScene::createCenary(){
    std::ifstream tile_file;
    tile_file.open("assets/tiledMaps/Stage1.txt");


    if(tile_file.is_open()){
        char c;
        int compare;
        for(int i=0; i<=600; i+=20){
            for(int j=0; j<=960; j+=20){
                tile_file.get(c);
                compare = c-48;
                switch(compare){
                    case 1: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", j, i, 20, 65));break;

                    case 2: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i+5, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i+10, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i-5, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i-10, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i-15, 0, 0)); break;

                    case 3: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+5, i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+10, i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i+15, 5, 5)); break;

                    case 4: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i+5, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i+10, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i-5, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i-10, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i-15, 0, 0));break;

                    case 5: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_door.png", j+15, i-20, 5, 65));break;

                    case 6: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+5, i, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+10, i, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i, 5, 5)); break;
                }
            }
        }
    }
}
