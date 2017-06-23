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

    for(int i=0; i<=960; i+=20){
        for(int j=0; j<=600; j+=20){
            gameObjectsList.push_back(new Ground("assets/sprites/cenary/chao.png", i, j, 20, 20));
        }
    }

    //gameObjectsList.push_back(new ProgressBar(100, 500, 45, 5));

    for(int i=0; i<=960; i+=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", i, 0, 5, 5));
    }
    for(int i=0; i<=960; i+=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", i, 595, 5, 5));
    }
    for(int j=0; j<=600; j+=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 955, j, 5, 5));
    }


    std::pair <int, int> biluPos (10, 500);
    std::pair <int, int> etemerPos (30, 510);
    std::pair <int, int> varginhaPos (50, 500);

    gameObjectsList.push_back(new Player(biluPos, etemerPos, varginhaPos));

    std::pair <std::string, int> wayOne ("right", 480);
    std::pair <std::string, int> wayTwo ("up", 20);
    std::pair <std::string, int> wayThree ("left", 220);
    std::pair <std::string, int> wayFour ("down", 120);

    Guard * guard = new Guard("assets/sprites/seguranca_sheet.png", 220, 120, 40, 40, "right");
    guard->addWay(1, wayOne);
    guard->addWay(2, wayTwo);
    guard->addWay(3, wayThree);
    guard->addWay(4, wayFour);

    gameObjectsList.push_back(guard);
    // gameObjectsList.push_back(new Guard("assets/sprites/seguranca_sheet.png", 900, 10, 40, 40));

    for(int i=0; i<=400; i+=20){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", i, 400, 20, 65));
    }
    for(int j=400; j>=320; j-=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 415, j, 5, 5));
    }

    for(int j=260; j>=180; j-=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 415, j, 5, 5));
    }

    for(int i=395; i>=0; i-=20){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", i, 180, 20, 65));
    }
    gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", 0, 180, 20, 65));

    for(int j=400; j>=180; j-=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 0, j, 5, 5));
    }

    for(int j=180; j>=120; j-=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 200, j, 5, 5));
    }

    for(int j=60; j>=0; j-=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 200, j, 5, 5));
    }
    for(int i=180; i>=0; i-=20){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", i, 0, 20, 65));
    }
    for(int j=180; j>=0; j-=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 0, j, 5, 5));
    }
    for(int i=835; i>=535; i-=20){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", i, 200, 20, 65));
    }
    for(int i=835; i>=535; i-=20){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", i, 0, 20, 65));
    }
    for(int j=0; j<=395; j+=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 535, j, 5, 5));
    }
    for(int i=535; i<=635; i+=20){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", i, 400, 20, 65));
    }
    gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", 640, 400, 20, 65));
    for(int i=720; i<=855; i+=20){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", i, 400, 20, 65));
    }
    for(int j=400; j>=140; j-=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 855, j, 5, 5));
    }
    for(int j=75; j>=0; j-=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", 855, j, 5, 5));
    }

    //Door edge 1
    gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_door.png", 200, 5, 5, 65));

    //Door edge 2
    gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_door.png", 415, 200, 5, 65));

    //Door edge 3
    gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_door.png", 855, 20, 5, 65));

    std::pair<int,int> doorOnePosition (360, 270);
    std::pair<int,int> switchOnePosition (150, 150);

    std::pair<int,int> doorTwoPosition (660, 460);
    std::pair<int,int> switchTwoPosition (600, 150);

    gameObjectsList.push_back(new DoorSystem(doorOnePosition,switchOnePosition));
    gameObjectsList.push_back(new DoorSystem(doorTwoPosition,switchTwoPosition));

    gameObjectsList.push_back(new Paper("assets/sprites/papeis(19X21).png", 100,300, 19, 21));
    gameObjectsList.push_back(new Paper("assets/sprites/papeis(19X21).png", 800,300, 19, 21));


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

void GameScene::unload(){
    CollisionManager::instance.resetLists();
    gameObjectsList.clear();
}
