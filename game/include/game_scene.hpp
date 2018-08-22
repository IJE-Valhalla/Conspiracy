#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "player.hpp"
#include "wall.hpp"
#include "game_object.hpp"
#include "guard.hpp"
#include "camera.hpp"
#include "progress_bar.hpp"
#include "timer.hpp"
#include "player.hpp"
#include "camera_system.hpp"

#include <fstream>
#include <vector>

#ifndef HEADER_SIZE
   #define HEADER_SIZE 40
#endif

//Defining constants for assets
#define TABLEASSET "assets/sprites/mesa.png"
#define FINISHPOINTASSET "assets/sprites/cenary/tapete.png"
#define CHAIRASSET "assets/sprites/cadeira_sheet(20X27).png"

using namespace engine;

class GameScene: public Scene{
public:
    GameScene(int id, std::string newTiledFile);
    GameScene(int id, std::string newTiledFile, std::string music);
    virtual ~GameScene() = default;
    void load();
    void draw();
    void update(double timeElapsed);
    void unload();
    void verifyWinOrLose();
protected:
    Player* player;
    Audio* background_music;
    std::vector<GameObject*> gameObjectsList;
    std::string tiledFile;
    Timer* stageTimer;
    Timer* skipTimer;
    int actualPapers;
    bool aliensInPosition;
    void initializeColliders();
    virtual void createGuards() = 0;
    virtual void createAliens() = 0;
    void createCenary();
    virtual void createDoorSystems() = 0;
    virtual void createPapers() = 0;
    virtual void createFinishPoints() = 0;
    virtual void createTables();
    void createGameBorders();
    void createGround();
    virtual void createChairs();
};

#endif
