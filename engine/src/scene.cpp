#include "scene.hpp"

namespace engine{
    int Scene::getId(){
        return sceneId;
    }
    void Scene::setId(int new_id){
        sceneId = new_id;
    }
}
