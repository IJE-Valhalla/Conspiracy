#include "scene.hpp"

using namespace engine;

    Scene::Scene(int id){
        setId(id);
    }

    int Scene::getId(){
        return sceneId;
    }
    void Scene::setId(int new_id){
        sceneId = new_id;
    }
    
