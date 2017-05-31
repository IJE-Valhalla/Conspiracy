#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <unordered_map>
#include "scene.hpp"

namespace engine{
    class SceneManager{
    public:
        void addScene(Scene* scene);
        void loadScene(int id);
        Scene* getCurrentScene();
    private:
    std::unordered_map< int, Scene *> scenes;
    Scene * currentScene;
    };
}
#endif
