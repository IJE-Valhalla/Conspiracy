#include "finish_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

FinishScene::FinishScene(int id) : Scene(id){
    selectButton = 1;
    select = new Color(255, 255, 255, 0);
    notSelect = new Color(0, 0, 0, 0);
    soundEffect = new Audio("assets/sounds/SELECT6.wav", "EFFECT", 100);
    background = new Animation("assets/sprites/finish.png", 1, 1, 0.8);
    background->addAction("finish", 0,0);
    background->setInterval("finish");
}

FinishScene::~FinishScene(){
}

void FinishScene::draw(){
        background->draw_instant(80, 20);

        for(auto gameObject : gameObjectsList) {
                (*gameObject.second).draw();
        }
}

void FinishScene::update(double timeElapsed){
        selectAction();

        background->update();

        for(auto gameObject : gameObjectsList) {
                if(typeid(*gameObject.second) == typeid(Button)) {
                        if(gameObject.first == selectButton) {
                                ((Button *)(gameObject.second))->setTextColor(select);
                        }else{
                                ((Button *)(gameObject.second))->setTextColor(notSelect);
                        }
                }

                (*gameObject.second).update(timeElapsed);
        }
}

void FinishScene::load(){
        gameObjectsList.push_back(std::pair<int, GameObject*>(1,new Button("assets/fonts/font.ttf", 420, 500, 500, 500, "Menu", 50)));
        AnimationManager::instance.setBackgroundColor(new Color(158,228,159, 125));

}

void FinishScene::selectAction(){
        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_ENTER)) {
                switch(selectButton) {
                case 1:
                        getSceneManager()->loadScene(0);
                        break;
                default:
                        break;
                }

        }
}

void FinishScene::unload(){
}
