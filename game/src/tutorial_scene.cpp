#include "tutorial_scene.hpp"

TutorialScene::TutorialScene(int id, std::string backgroundFile, int nextScene): Scene(id){
    background = new Sprite(backgroundFile);
    newNextScene = nextScene;
    sceneTimer = new Timer();
}

void TutorialScene::draw(){
    background->draw(0,0);
}

void TutorialScene::update(double timeElapsed){
    timeElapsed = timeElapsed;
    if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_ENTER) || sceneTimer->total_elapsed_time() >= 4000){
        getSceneManager()->loadScene(newNextScene);
    }
}

void TutorialScene::load(){
    sceneTimer->start();
    gameObjectsList.push_back(std::pair<int, GameObject*>(2,new Button("assets/fonts/font.ttf", 350, 400, 500, 500, "Continue", 50)));
}

void TutorialScene::unload(){

}
