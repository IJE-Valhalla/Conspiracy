#ifndef LOSE_SCENE_HPP
#define LOSE_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "game_object.hpp"

#include <vector>

using namespace engine;

class LoseScene: public Scene{
public:
    LoseScene(int id);
    ~LoseScene();
    void load();
    void draw();
    void update(double timeElapsed);
    void unload();
private:
    std::vector<GameObject*> gameObjectsList;
};

#endif
