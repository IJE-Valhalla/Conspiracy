#include "lose_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

LoseScene::LoseScene(int id) : Scene(id){
    soundEffect = new Audio("assets/sounds/SELECT6.wav", "EFFECT", 100);
    backgroundMusic = new Audio("assets/sounds/GAMEOVER.wav", "MUSIC", 50);
    background = new Animation("assets/sprites/lose.png", 1, 4, 0.8);
    background->addAction("lose", 0,3);
    background->setInterval("lose");
}

LoseScene::~LoseScene(){
}

void LoseScene::draw(){
        background->draw_instant(80, 20);

        for(auto gameObject : gameObjectsList) {
                (*gameObject.second).draw();
        }
}

void LoseScene::update(double timeElapsed){
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

void LoseScene::load(){
        gameObjectsList.push_back(std::pair<int, GameObject*>(1,new Button("assets/fonts/font.ttf", 700, 500, 500, 500, "Continue", 50)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(2,new Button("assets/fonts/font.ttf", 50, 500, 500, 500, "Menu", 50)));
        AnimationManager::instance.setBackgroundColor(Color{255,160,156, 125});
        backgroundMusic->play(0);

}

void LoseScene::selectAction(){
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
                        getSceneManager()->loadScene(getSceneManager()->getBeforeSceneId());
                        break;
                case 2:
                        getSceneManager()->loadScene(0);
                        break;
                default:
                        break;
                }

        }
}

void LoseScene::unload(){
}
