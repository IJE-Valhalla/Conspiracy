#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "player.hpp"
#include "wall.hpp"
#include "game_object.hpp"
#include "guard.hpp"

#include <vector>

using namespace engine;

class LoseScene: public Scene{
public:
    GameScene(int id);
    ~GameScene();
    void load();
    void draw();
    void update(double timeElapsed);
    void unload();
private:
    std::vector<GameObject*> gameObjectsList;
};

#endif
