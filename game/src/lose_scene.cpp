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
}

void LoseScene::load(){
    gameObjectsList.push_back(new Button("assets/fonts/font.ttf", 100, 100, 500, 500, "You Win", 200));


}
void LoseScene::unload(){
}
