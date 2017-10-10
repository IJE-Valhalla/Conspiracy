#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <unordered_map>
#include "scene.hpp"

namespace engine{
    class SceneManager{
    public:
        SceneManager();
        void addScene(Scene* scene);
        void loadScene(int id);
        Scene* getCurrentScene();
        int getCurrentSceneId();
        int getBeforeSceneId();
        void setCurrentSceneId(int id);
    private:
        std::unordered_map< int, Scene *> scenes{};
        Scene * currentScene{nullptr};
        int currentSceneId{0};
        int beforeSceneId{0};
    };
}
#endif
