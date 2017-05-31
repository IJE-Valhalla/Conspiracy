#include <iostream>

#include "engine.hpp"
#include "game_scene.hpp"
#include "lose_scene.hpp"
#include "win_scene.hpp"
#include "alien.hpp"

using namespace engine;


int main(int, char**){
    loadEngine();
    GameScene* gameScene = new GameScene(0);
    LoseScene* loseScene = new LoseScene(1);
    WinScene* winScene = new WinScene(2);

    getSceneManager()->addScene(gameScene);
    getSceneManager()->addScene(loseScene);
    getSceneManager()->addScene(winScene);

    getSceneManager()->loadScene(0);

    run();
    return 0;
}
