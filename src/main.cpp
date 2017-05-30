#include <iostream>

#include "engine.hpp"
#include "game_scene.hpp"
#include "lose_scene.hpp"
#include "alien.hpp"

using namespace engine;


int main(int, char**){
    loadEngine();
    //LoseScene* scene = new LoseScene(0);
    GameScene* scene = new GameScene(0);

    getSceneManager()->addScene(scene);
    getSceneManager()->loadScene(0);

    run();
    return 0;
}
