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
    int selectButton{false};
    std::vector<std::pair<int, GameObject*>> gameObjectsList{};
    Animation * background{nullptr};
    Color select{255, 255, 255, 0};
    Color notSelect{0,0,0,0};
    Audio * soundEffect{nullptr};
    Audio * backgroundSound{nullptr};
};

#endif
