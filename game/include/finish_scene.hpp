#ifndef FINISH_SCENE_HPP
#define FINISH_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "color.hpp"
#include "audio.hpp"

#include <vector>

using namespace engine;

class FinishScene: public Scene{
public:
    FinishScene(int id);
    ~FinishScene();
    void load();
    void draw();
    void update(double timeElapsed);
    void unload();
private:
    void selectAction();
    int selectButton;
    std::vector<std::pair<int, GameObject*>> gameObjectsList;
    Animation * background;
    Color * select;
    Color * notSelect;
    Audio * soundEffect;
    Audio * backgroundSound;
};

#endif
