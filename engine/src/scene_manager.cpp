#include "scene_manager.hpp"
#include "scene.hpp"

using namespace engine;

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
    }

}

Scene* SceneManager::getCurrentScene(){
    return currentScene;
}
