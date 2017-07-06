#include <iostream>

#include "engine.hpp"
#include "game_scene.hpp"
#include "lose_scene.hpp"
#include "win_scene.hpp"
#include "menu_scene.hpp"
#include "alien.hpp"
#include "stage_one.hpp"
#include "stage_two.hpp"
#include "stage_three.hpp"
#include "stage_four.hpp"
#include "stage_five.hpp"
#include "choose_stage_scene.hpp"
#include "finish_scene.hpp"

using namespace engine;


int main(int, char**){
    loadEngine();
    MenuScene* menuScene = new MenuScene(0);
    StageOne * stageOne = new StageOne(1, "assets/tiledMaps/Stage1.txt");
    StageTwo * stageTwo = new StageTwo(2, "assets/tiledMaps/Stage2.txt");
    StageThree * stageThree = new StageThree(3, "assets/tiledMaps/Stage3.txt");
    StageFour * stageFour = new StageFour(4, "assets/tiledMaps/Stage4.txt");
    StageFive * stageFive = new StageFive(5, "assets/tiledMaps/Stage5.txt");
    LoseScene* loseScene = new LoseScene(6);
    WinScene* winScene = new WinScene(7);
    ChooseStageScene* chooseStageScene = new ChooseStageScene(8);
    FinishScene* finishScene = new FinishScene(9);

    getSceneManager()->addScene(menuScene);
    getSceneManager()->addScene(stageOne);
    getSceneManager()->addScene(stageTwo);
    getSceneManager()->addScene(stageThree);
    getSceneManager()->addScene(stageFour);
    getSceneManager()->addScene(stageFive);
    getSceneManager()->addScene(loseScene);
    getSceneManager()->addScene(winScene);
    getSceneManager()->addScene(chooseStageScene);
    getSceneManager()->addScene(finishScene);

    getSceneManager()->loadScene(0);

    run();
    return 0;
}
