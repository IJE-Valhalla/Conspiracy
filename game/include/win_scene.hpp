#ifndef WIN_SCENE_HPP
#define WIN_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "game_object.hpp"

#include <vector>

using namespace engine;

class WinScene: public Scene{
public:
    WinScene(int id);
    ~WinScene();
    void load();
    void draw();
    void update(double timeElapsed);
    void unload();
private:
    std::vector<GameObject*> gameObjectsList;
};

#endif
