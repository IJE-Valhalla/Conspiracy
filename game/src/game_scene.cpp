#include "game_scene.hpp"
#include "player.hpp"
#include "scene.hpp"
#include "engine.hpp"
#include "wall.hpp"
#include "collision_manager.hpp"
#include "guard.hpp"

#include <iostream>

using namespace engine;

GameScene::GameScene(int id) : Scene(id){

}

GameScene::~GameScene(){}

void GameScene::draw(){
    std::vector<GameObject*>::iterator it;
    for(it=gameObjectsList.begin() ; it < gameObjectsList.end(); it++) {
        //std::cout << "AQUI" << std::endl;
        (*it)->draw();
    }
}
void GameScene::update(double timeElapsed){
    std::vector<GameObject*>::iterator it;
    for(it=gameObjectsList.begin() ; it < gameObjectsList.end(); it++) {
        (*it)->update(timeElapsed);
    }
}
void GameScene::load(){
    gameObjectsList.push_back(new Guard("assets/sprites/seguranca_sheet.png", 400, 400, 100, 100));
    gameObjectsList.push_back(new Player());
    gameObjectsList.push_back(new Wall("assets/sprites/MYP.png", 100, 200, 100, 100));
    CollisionManager::instance.addWall(gameObjectsList.back());
}
void GameScene::unload(){
}
