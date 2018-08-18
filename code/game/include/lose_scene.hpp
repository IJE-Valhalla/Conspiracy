#ifndef LOSE_SCENE_HPP
#define LOSE_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "color.hpp"
#include "audio.hpp"

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
    void selectAction();
    int selectButton{1};
    std::vector<std::pair<int, GameObject*>> gameObjectsList{};
    Animation * background{nullptr};
    Color select{255, 255, 255, 0};
    Color notSelect{0, 0, 0, 0};
    Audio * soundEffect{nullptr};
    Audio * backgroundMusic{nullptr};
};

#endif
