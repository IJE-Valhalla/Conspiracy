#include <iostream>

#include "engine.hpp"
#include "game_scene.hpp"



int main(int, char**){
    GameScene* scene = new GameScene(0);
    engine::loadEngine();

    engine::getSceneManager()->addScene(scene);

    engine::getSceneManager()->loadScene(0);
    engine::run();

    return 0;
}
