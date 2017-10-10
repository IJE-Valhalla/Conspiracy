#include "menu_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

MenuScene::MenuScene(int id) : Scene(id){
        background = new Sprite("assets/sprites/background.png");
        buttonEffect = new Audio("assets/sounds/SELECT6.wav", "EFFECT", 100);
        selectEffect = new Audio("assets/sounds/SELECT5.wav", "EFFECT", 128);
        backgroundMusic = new Audio("assets/sounds/MENU.wav", "MUSIC", 100);
        SaveManager::instance.verifySave();
}

MenuScene::~MenuScene(){
}

void MenuScene::draw(){
        background->draw(0,0);

        for(auto gameObject : gameObjectsList) {
                (*gameObject.second).draw();
        }
}

void MenuScene::update(double timeElapsed){
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

void MenuScene::selectAction(){
        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_UP)) {
                buttonEffect->pause();
                buttonEffect->play(0);
                selectButton--;
                if(selectButton <= 0) {
                        selectButton = 3;
                }
        }
        else if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_DOWN)) {
                buttonEffect->pause();
                buttonEffect->play(0);
                selectButton++;
                if(selectButton > 3) {
                        selectButton = 1;
                }
        }

        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_ENTER)) {
                selectEffect->play(0);
                switch(selectButton) {
                case 1:
                        getSceneManager()->loadScene(22);
                        break;
                case 2:
                        getSceneManager()->loadScene(8);
                        break;
                case 3:
                        InputManager::instance.setQuitRequest(true);
                        break;
                default:
                        break;
                }

        }
}

void MenuScene::load(){
        gameObjectsList.push_back(std::pair<int, GameObject*>(1, new Button("assets/fonts/font.ttf", 410, 300, 500, 500, "Jogar", 50)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(2,new Button("assets/fonts/font.ttf", 290, 400, 500, 500, "Selecionar Fase", 50)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(3,new Button("assets/fonts/font.ttf", 430, 500, 500, 500, "Sair", 50)));
        backgroundMusic->play(-1);
        AnimationManager::instance.setBackgroundColor(Color{100,100,100, 125});
}

void MenuScene::unload(){
}
