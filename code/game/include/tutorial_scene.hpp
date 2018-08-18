#ifndef TUTORIAL_SCENE_HPP
#define TUTORIAL_SCENE_HPP

#include "engine.hpp"
#include "button.hpp"
#include "timer.hpp"


using namespace engine;

class TutorialScene: public Scene{
public:
    TutorialScene(int id, std::string backgroundFile, int nextScene);
    void load();
    void update(double timeElapsed);
    void draw();
    void unload();
private:
    Timer* sceneTimer;
    Sprite* background;
    int newNextScene;
    std::vector<std::pair<int, GameObject*>> gameObjectsList;
};

#endif
