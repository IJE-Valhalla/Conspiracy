#include "game_scene.hpp"
#include "player.hpp"
#include "scene.hpp"
#include "engine.hpp"

using namespace engine;

GameScene::GameScene(int id) : Scene(id){

}

GameScene::~GameScene(){}

void GameScene::draw(){
    player->draw();
}
void GameScene::update(double timeElapsed){
    player->update(timeElapsed);
}
void GameScene::load(){
    player = new Player();
}
void GameScene::unload(){
    free(player);
}
