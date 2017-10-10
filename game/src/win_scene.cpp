#include "win_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

WinScene::WinScene(int id) : Scene(id){
    soundEffect = new Audio("assets/sounds/SELECT6.wav", "EFFECT",100);
    background = new Animation("assets/sprites/win.png", 1, 5, 0.8);
    background->addAction("win", 0, 4);
    background->setInterval("win");
}

WinScene::~WinScene(){
}

void WinScene::draw(){
        background->draw_instant(80, 20);
        for(auto gameObject : gameObjectsList) {
                (*gameObject.second).draw();
        }
}

void WinScene::update(double timeElapsed){
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

void WinScene::load(){
        gameObjectsList.push_back(std::pair<int, GameObject*>(1,new Button("assets/fonts/font.ttf", 700, 500, 500, 500, "Continue", 50)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(2,new Button("assets/fonts/font.ttf", 50, 500, 500, 500, "Menu", 50)));
        AnimationManager::instance.setBackgroundColor(Color{158,228,159, 125});

}

void WinScene::selectAction(){
        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_LEFT)) {
                soundEffect->pause();
                soundEffect->play(0);
                selectButton--;
                if(selectButton <= 0) {
                        selectButton = 2;
                }
        }
        else if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_RIGHT)) {
                soundEffect->pause();
                soundEffect->play(0);
                selectButton++;
                if(selectButton > 2) {
                        selectButton = 1;
                }
        }

        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_ENTER)) {
                switch(selectButton) {
                case 1:
                        if(getSceneManager()->getBeforeSceneId() == 1){
                            getSceneManager()->loadScene(25);
                        }else if(getSceneManager()->getBeforeSceneId() == 2){
                            getSceneManager()->loadScene(23);
                        }else{
                            getSceneManager()->loadScene(getSceneManager()->getBeforeSceneId()+1);
                        }

                        break;
                case 2:
                        getSceneManager()->loadScene(0);
                        break;
                default:
                        break;
                }

        }
}

void WinScene::unload(){
}
