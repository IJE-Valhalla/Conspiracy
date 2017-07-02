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


#include <typeinfo>
#include <iostream>

using namespace engine;

GameScene::GameScene(int id, std::string newTiledFile) : Scene(id){
    tiledFile = newTiledFile;
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
        }else if(typeid(*gameObject) == typeid(PaperTable)){
            if(!(((PaperTable*)(gameObject))->getPaper())->isEdited()){
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
    createTables();

    initializeColliders();

}

void GameScene::unload(){
    CollisionManager::instance.resetLists();
    gameObjectsList.clear();
}

void GameScene::createTables(){}

void GameScene::createGameBorders(){
    for(int i=0; i<=960; i+=5){
        gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", i, 0, 5, 20));
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
    tile_file.open(tiledFile);


    if(tile_file.is_open()){
        char c;
        int compare;
        for(int i=0; i<=600; i+=20){
            for(int j=0; j<=960; j+=20){
                tile_file.get(c);
                compare = c-48;
                switch(compare){
                    case 1: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede2.png", j, i+25, 20, 40));break;

                    case 2: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i+5, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i+10, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i+15, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i-5, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i-10, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i-15, 0, 0)); break;

                    case 3: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+5, i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+10, i+15, 5, 5));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j+15, i+15, 5, 5)); break;

                    case 4: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i+5, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i+10, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i+15, 5, 15));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i-5, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i-10, 0, 0));
                            gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_cima1.png", j, i-15, 0, 0));break;

                    case 5: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_door.png", j+15, i-20, 5, 65));break;

                    case 6: gameObjectsList.push_back(new Wall("assets/sprites/cenary/parede_door.png", j, i-20, 5, 65));break;
                }
            }
        }
    }
}
