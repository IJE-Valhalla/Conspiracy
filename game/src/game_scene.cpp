#include "game_scene.hpp"
#include "player.hpp"
#include "scene.hpp"
#include "engine.hpp"
#include "wall.hpp"
#include "collision_manager.hpp"
#include "guard.hpp"
#include "paper.hpp"

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
    verifyWin();
}

void GameScene::verifyWin(){
    bool allPapersEdited = true;
    for(auto gameObject : gameObjectsList){
        if(typeid(*gameObject) == typeid(Paper)){
            if(!((Paper*)(gameObject))->isEdited()){
                allPapersEdited = false;
            }
        }
    }
    if(allPapersEdited){
        WARN("YOU WIN!!!");
    }
}

void GameScene::load(){
    gameObjectsList.push_back(new Player());
    gameObjectsList.push_back(new Guard("assets/sprites/seguranca_sheet.png", 400, 400, 40, 40, "right"));
    gameObjectsList.push_back(new Guard("assets/sprites/seguranca_sheet.png", 0, 100, 40, 40, "down"));
    gameObjectsList.push_back(new Wall("assets/sprites/MYP.png", 0, 0, 100, 100));
    gameObjectsList.push_back(new Wall("assets/sprites/MYP.png", 0, 400, 100, 100));
    gameObjectsList.push_back(new Wall("assets/sprites/MYP.png", 600, 400, 100, 100));
    gameObjectsList.push_back(new Paper("assets/sprites/papeis(19X21).png", 400,500, 19, 21));
    gameObjectsList.push_back(new Paper("assets/sprites/papeis(19X21).png", 800,20, 19, 21));
    gameObjectsList.push_back(new Paper("assets/sprites/papeis(19X21).png", 50,500, 19, 21));
    for(auto gameObject: gameObjectsList){
        if(typeid(*gameObject) == typeid(Wall)){
            CollisionManager::instance.addWall(gameObject);
        }else if(typeid(*gameObject) == typeid(Guard)){
            CollisionManager::instance.addEnemy(gameObject);
        }else if(typeid(*gameObject) == typeid(Paper)){
            CollisionManager::instance.addPaper(gameObject);
        }
    }

}
void GameScene::unload(){
}
