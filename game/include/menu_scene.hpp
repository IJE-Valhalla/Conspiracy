#ifndef MENU_SCENE_HPP
#define MENU_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "sprite.hpp"
#include "game_object.hpp"
#include "color.hpp"
#include "audio.hpp"
#include "save_manager.hpp"

#include <vector>

using namespace engine;

class MenuScene: public Scene{
public:
    MenuScene(int id);
    ~MenuScene();
    void load();
    void draw();
    void update(double timeElapsed);
    void unload();
    void selectAction();

private:
    int selectButton{1};
    std::vector<std::pair<int, GameObject*>> gameObjectsList{};
    Sprite * background{nullptr};
    Color select{36,185,64,0};
    Color notSelect{0,0,0,0};
    Audio * buttonEffect{nullptr};
    Audio * selectEffect{nullptr};
    Audio * backgroundMusic{nullptr};
};

#endif
