#include <iostream>

#include "engine.hpp"
#include "game_scene.hpp"
#include "alien.hpp"

using namespace engine;


int main(){
    loadEngine();

    GameScene* scene = new GameScene(0);
    engine::getSceneManager()->addScene(scene);
    engine::getSceneManager()->loadScene(0);

    run();

    return 0;
}
