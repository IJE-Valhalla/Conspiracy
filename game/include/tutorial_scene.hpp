#ifndef TUTORIAL_SCENE_HPP
#define TUTORIAL_SCENE_HPP

#include "engine.hpp"
#include "button.hpp"


using namespace engine;

class TutorialScene: public Scene{
public:
    TutorialScene(int id, std::string backgroundFile);
    void load();
    void update(double timeElapsed);
    void draw();
    void unload();
private:
    Sprite* background;
    std::vector<std::pair<int, GameObject*>> gameObjectsList;
};

#endif
