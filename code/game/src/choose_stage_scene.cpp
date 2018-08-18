#include "choose_stage_scene.hpp"
#include "choice.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

#define MAX_CHOICE 5
#define MIN_CHOICE 0


ChooseStageScene::ChooseStageScene(int id) : Scene(id){
    selectButton = 1;
    background = new Sprite("assets/sprites/selecao_fases.png");
    soundEffect = new Audio("assets/sounds/SELECT6.wav", "EFFECT", 100);
}

ChooseStageScene::~ChooseStageScene(){
}

void ChooseStageScene::draw(){
        background->draw(80, 20);

        for(auto gameObject : gameObjectsList) {
                (*gameObject.second).draw();
        }
}

void ChooseStageScene::update(double timeElapsed){
        selectAction();

        for(auto gameObject : gameObjectsList) {
                if(typeid(*gameObject.second) == typeid(Choice)) {
                        if(gameObject.first == selectButton) {
                                ((Choice *)(gameObject.second))->setTextColor(select);
                                ((Choice *)(gameObject.second))->setChosen(true);
                        }else{
                                ((Choice *)(gameObject.second))->setTextColor(notSelect);
                                ((Choice *)(gameObject.second))->setChosen(false);
                        }

                        if(gameObject.first <= SaveManager::instance.getStageNumberUnlock()){
                                ((Choice *)(gameObject.second))->setUnlock(true);
                        }
                }

                if(!gameObject.first){
                        if(gameObject.first == selectButton){
                          ((Button *)(gameObject.second))->setTextColor(select);
                        }else{
                          ((Button *)(gameObject.second))->setTextColor(notSelect);
                        }
                }

                (*gameObject.second).update(timeElapsed);
        }
}

void ChooseStageScene::load(){
        gameObjectsList.push_back(std::pair<int, GameObject*>(0,new Button("assets/fonts/font.ttf", 20, 20, 100, 100, "Voltar", 30)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(1,new Choice("assets/sprites/choices/stage_1.png", 50, 100, 200, 150, "Fase 1", 40)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(2,new Choice("assets/sprites/choices/stage_2.png", 720, 100, 200, 150, "Fase 2", 40)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(3,new Choice("assets/sprites/choices/stage_3.png", 50, 400, 200, 150, "Fase 3", 40)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(4,new Choice("assets/sprites/choices/stage_4.png", 720, 400, 200, 150, "Fase 4", 40)));
        gameObjectsList.push_back(std::pair<int, GameObject*>(5,new Choice("assets/sprites/choices/stage_5.png", 400, 250, 200, 150, "Fase 5", 40)));
        AnimationManager::instance.setBackgroundColor(Color{255,225,142, 125});
}

void ChooseStageScene::selectAction(){
        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_LEFT)||
           InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_UP)) {
                soundEffect->pause();
                soundEffect->play(0);
                selectButton--;
                if(selectButton < MIN_CHOICE) {
                        selectButton = MAX_CHOICE;
                }
        }
        else if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_RIGHT)||
                InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_DOWN)) {
                soundEffect->pause();
                soundEffect->play(0);
                selectButton++;
                if(selectButton > MAX_CHOICE) {
                        selectButton = MIN_CHOICE;
                }
        }

        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_ENTER)) {
                switch(selectButton) {
                  case 0:
                          getSceneManager()->loadScene(0);
                          break;
                  case 1:
                          if(selectButton <= SaveManager::instance.getStageNumberUnlock()){
                              getSceneManager()->loadScene(22);
                          }
                          break;
                  case 2:
                          if(selectButton <= SaveManager::instance.getStageNumberUnlock()){
                              getSceneManager()->loadScene(2);
                          }
                          break;
                  case 3:
                          if(selectButton <= SaveManager::instance.getStageNumberUnlock()){
                              getSceneManager()->loadScene(3);
                          }
                          break;
                  case 4:
                          if(selectButton <= SaveManager::instance.getStageNumberUnlock()){
                              getSceneManager()->loadScene(4);
                          }
                          break;
                  case 5:
                          if(selectButton <= SaveManager::instance.getStageNumberUnlock()){
                              getSceneManager()->loadScene(5);
                          }
                          break;
                default:
                        break;
                }

        }
}

void ChooseStageScene::unload(){
}
