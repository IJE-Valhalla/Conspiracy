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
    int selectButton;
    std::vector<std::pair<int, GameObject*>> gameObjectsList;
    Sprite * background;
    Color * select;
    Color * notSelect;
    Audio * soundEffect;
};

#endif
