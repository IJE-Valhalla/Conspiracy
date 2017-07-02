#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "player.hpp"
#include "wall.hpp"
#include "game_object.hpp"
#include "guard.hpp"
#include "progress_bar.hpp"

#include <fstream>
#include <vector>

using namespace engine;

class GameScene: public Scene{
public:
    GameScene(int id, std::string newTiledFile);
    ~GameScene();
    void load();
    void draw();
    void update(double timeElapsed);
    void unload();
    void verifyWinOrLose();
protected:
    std::vector<GameObject*> gameObjectsList;
    std::string tiledFile;
    void initializeColliders();
    virtual void createGuards() = 0;
    virtual void createAliens() = 0;
    void createCenary();
    virtual void createDoorSystems() = 0;
    virtual void createPapers() = 0;
    virtual void createTables();
    void createGameBorders();
    void createGround();
};

#endif
