#ifndef CHOOSE_STAGE_SCENE_HPP
#define CHOOSE_STAGE_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "sprite.hpp"
#include "game_object.hpp"
#include "color.hpp"
#include "audio.hpp"
#include "save_manager.hpp"

#include <vector>

using namespace engine;

class ChooseStageScene: public Scene{
public:
    ChooseStageScene(int id);
    ~ChooseStageScene();
    void load();
    void draw();
    void update(double timeElapsed);
    void unload();
private:
    void selectAction();
    int selectButton{0};
    std::vector<std::pair<int, GameObject*>> gameObjectsList{};
    Sprite * background{nullptr};
    Color select{36,185,64,0};
    Color notSelect{0,0,0,0};
    Audio * soundEffect{nullptr};
};

#endif
