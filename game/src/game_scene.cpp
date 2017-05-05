#include "game_scene.hpp"
#include "player.hpp"
#include "scene.hpp"


GameScene::GameScene(int id){
    setSceneId(id);
}

GameScene::~GameScene(){}

GameScene::draw(){
    player->draw();
}
GameScene::update(int timeElapsed){
    player->update(timeElapsed);
}
GameScene::load(){
    player = new Player();
}
GameScene::unload(){
    free(player);
}
