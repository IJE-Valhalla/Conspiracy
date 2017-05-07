#include "game_scene.hpp"
#include "player.hpp"
#include "scene.hpp"

GameScene::~GameScene(){}

void GameScene::draw(){
    player->draw();
}
void GameScene::update(int timeElapsed){
    player->update(timeElapsed);
}
void GameScene::load(){
    player = new Player();
}
void GameScene::unload(){
    free(player);
}

void GameScene::init(){
    player->init();
}
