#include "lose_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

LoseScene::LoseScene(int id) : Scene(id){
    selectButton = 1;
    select = new Color(255, 255, 255, 0);
    notSelect = new Color(0, 0, 0, 0);
    background = new Sprite("assets/sprites/background.png");
    soundEffect = new Audio("assets/sounds/SELECT6.wav", "EFFECT", 100);
}

LoseScene::~LoseScene(){
}

void LoseScene::draw(){
        for(auto gameObject : gameObjectsList) {
                (*gameObject.second).draw();
        }
}

void LoseScene::update(double timeElapsed){
        selectAction();

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

void LoseScene::load(){
        gameObjectsList.push_back(std::pair<int, GameObject*>(1,new Button("assets/fonts/font.ttf", 350, 400, 500, 500, "Continue", 50)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(2,new Button("assets/fonts/font.ttf", 400, 500, 500, 500, "Exit", 50)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(0,new Button("assets/fonts/font.ttf", 100, 100, 500, 500, "You Lose", 200)));
}

void LoseScene::selectAction(){
        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_UP)) {
                soundEffect->pause();
                soundEffect->play(0);
                selectButton--;
                if(selectButton <= 0) {
                        selectButton = 2;
                }
        }
        else if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_DOWN)) {
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
                        getSceneManager()->loadScene(1);
                        break;
                case 2:
                        InputManager::instance.setQuitRequest(true);
                        break;
                default:
                        break;
                }

        }
}

void LoseScene::unload(){
}
