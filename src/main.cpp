#include <iostream>

#include "engine.hpp"
#include "game_scene.hpp"
#include "lose_scene.hpp"
#include "win_scene.hpp"
#include "menu_scene.hpp"
#include "alien.hpp"

using namespace engine;


int main(int, char**){
    loadEngine();
    MenuScene* menuScene = new MenuScene(0);
    GameScene* gameScene = new GameScene(1);
    LoseScene* loseScene = new LoseScene(2);
    WinScene* winScene = new WinScene(3);

    getSceneManager()->addScene(menuScene);
    getSceneManager()->addScene(gameScene);
    getSceneManager()->addScene(loseScene);
    getSceneManager()->addScene(winScene);

    getSceneManager()->loadScene(0);

    run();
    return 0;
}
