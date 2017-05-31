#include "lose_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

LoseScene::LoseScene(int id) : Scene(id){

}

LoseScene::~LoseScene(){}

void LoseScene::draw(){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).draw();
    }
}

void LoseScene::update(double timeElapsed){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).update(timeElapsed);
    }

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_ONE)){
        getSceneManager()->loadScene(0);
    }
}

void LoseScene::load(){
    gameObjectsList.push_back(new Button("assets/fonts/font.ttf", 100, 100, 500, 500, "You Lose", 200));



}

void LoseScene::unload(){
}
