#include "win_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

WinScene::WinScene(int id) : Scene(id){

}

WinScene::~WinScene(){}

void WinScene::draw(){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).draw();
    }
}

void WinScene::update(double timeElapsed){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).update(timeElapsed);
    }

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_ONE)){
        getSceneManager()->loadScene(0);
    }
}

void WinScene::load(){
    gameObjectsList.push_back(new Button("assets/fonts/font.ttf", 100, 100, 500, 500, "You Win", 200));



}

void WinScene::unload(){
}
