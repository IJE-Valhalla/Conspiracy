#include "scene_manager.hpp"
#include "scene.hpp"
#include "save_manager.hpp"

using namespace engine;

SceneManager::SceneManager(){
    beforeSceneId = 0;
    currentSceneId = 0;  
}

void SceneManager::addScene(Scene* scene){
    if(scenes.find(scene->getId()) != scenes.end()){
        INFO("Failed to load scene");
    }else{
        scenes[scene->getId()] = scene;
    }
}

void SceneManager::loadScene(int id){
    if(scenes.find(id) == scenes.end()){
        INFO("Invalid Scene ID to Load");
    }else{
        Scene* scene = currentScene;
        if(scene != NULL){
            scene->unload();
        }
        currentScene = scenes[id];
        currentScene->load();
        beforeSceneId = currentSceneId;
        currentSceneId = currentScene->getId();
        if (beforeSceneId >= SaveManager::instance.getStageNumberUnlock() && beforeSceneId < 6 && currentSceneId != 6){
              SaveManager::instance.saveActualSituation(beforeSceneId + 1);
        }
    }
}

Scene* SceneManager::getCurrentScene(){
    return currentScene;
}

int SceneManager::getCurrentSceneId(){
    return currentSceneId;
}

int SceneManager::getBeforeSceneId(){
    return beforeSceneId;
}

void SceneManager::setCurrentSceneId(int id){
    currentSceneId = id;
}
