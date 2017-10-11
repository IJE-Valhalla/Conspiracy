#include <iostream>
#include <memory>
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
#include "tutorial_scene.hpp"

using namespace engine;

int main(int, char**){
    loadEngine();

    /*** Initialization of scenes ***/
    std::vector<std::shared_ptr<Scene>> scenes{};
    scenes.emplace_back(std::make_shared<MenuScene>(0));
    scenes.emplace_back(std::make_shared<StageOne>(1, "assets/tiledMaps/Stage1.txt"));
    scenes.emplace_back(std::make_shared<StageTwo>(2, "assets/tiledMaps/Stage2.txt"));
    scenes.emplace_back(std::make_shared<StageThree>(3, "assets/tiledMaps/Stage3.txt"));
    scenes.emplace_back(std::make_shared<StageFour>(4, "assets/tiledMaps/Stage4.txt"));
    scenes.emplace_back(std::make_shared<StageFive>(5, "assets/tiledMaps/Stage5.txt"));
    scenes.emplace_back(std::make_shared<LoseScene>(6));
    scenes.emplace_back(std::make_shared<WinScene>(7));
    scenes.emplace_back(std::make_shared<ChooseStageScene>(8));
    scenes.emplace_back(std::make_shared<FinishScene>(9));

    scenes.emplace_back(std::make_shared<TutorialScene>(20, "assets/sprites/tutorial_bilu.png", 1));
    scenes.emplace_back(std::make_shared<TutorialScene>(21, "assets/sprites/tutorial_saida.png", 20));
    scenes.emplace_back(std::make_shared<TutorialScene>(22, "assets/sprites/tutoriaL_comandos.png", 21));
    scenes.emplace_back(std::make_shared<TutorialScene>(24, "assets/sprites/tutorial_temer2.png", 3));
    scenes.emplace_back(std::make_shared<TutorialScene>(23, "assets/sprites/tutorial_temer1.png", 24));
    scenes.emplace_back(std::make_shared<TutorialScene>(25, "assets/sprites/tutorial_varginha1.png", 26));
    scenes.emplace_back(std::make_shared<TutorialScene>(26, "assets/sprites/tutorial_varginha2.png", 2));

    for(auto &scene : scenes)
      getSceneManager()->addScene(scene.get());

    getSceneManager()->loadScene(0);

    run();
    return 0;
}
